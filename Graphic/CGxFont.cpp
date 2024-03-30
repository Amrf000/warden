#include "CGxFont.h"

CGxFont::~CGxFont() {
    this->Clear();
}

int32_t CGxFont::CheckStringGlyphs(const char *string) {
    if (!string || !*string) {
        return 1;
    }

    while (*string) {
        int32_t advance;
        auto code = SUniSGetUTF8(reinterpret_cast<const uint8_t *>(string), &advance);

        HASHKEY_NONE key = {};

        if (code != '\r' && code != '\n' && !this->m_activeCharacters.Ptr(code, key)) {
            return 0;
        }

        string += advance;
    }

    return 1;
}

void CGxFont::Clear() {
    if (this->m_faceHandle) {
        FontFaceCloseHandle(this->m_faceHandle);
    }

    this->m_faceHandle = nullptr;

    this->ClearGlyphs();
}

void CGxFont::ClearGlyphs() {
    for (int32_t i = 0; i < 8; i++) {
        auto &cache = this->m_textureCache[i];

        if (cache.m_texture) {
            HandleClose(this->m_textureCache[i].m_texture);
        }

        cache.m_texture = nullptr;

        // TODO
    }

    this->m_activeCharacters.Clear();

    this->m_activeCharacterCache.Clear();

    this->m_kernInfo.Clear();
}

float CGxFont::ComputeStep(uint32_t currentCode, uint32_t nextCode) {
    KERNINGHASHKEY kernKey = {nextCode | (currentCode << 16)};
    KERNNODE *kern = this->m_kernInfo.Ptr(currentCode, kernKey);

    if (kern && kern->flags & 0x02) {
        return kern->proporportionalSpacing;
    }

    auto face = FontFaceGetFace(this->m_faceHandle);
    auto currentIndex = FT_Get_Char_Index(face, currentCode);
    auto nextIndex = FT_Get_Char_Index(face, nextCode);

    FT_Vector vector;
    vector.x = 0;

    if (face->face_flags & FT_FACE_FLAG_KERNING) {
        FT_Get_Kerning(face, currentIndex, nextIndex, ft_kerning_unscaled, &vector);
        vector.x &= (vector.x >= 0) - 1;
    }

    HASHKEY_NONE charKey = {};
    auto activeChar = this->m_activeCharacters.Ptr(currentCode, charKey);

    float advance = 0.0f;

    if (activeChar) {
        advance = this->m_flags & 0x08
                  ? activeChar->bitmapData.m_glyphAdvance + 1.0f
                  : activeChar->bitmapData.m_glyphAdvance;
    }

    float spacing = (this->m_pixelsPerUnit * vector.x) + advance;

    if (!kern) {
        kern = this->m_kernInfo.New(currentCode, kernKey, 0, 0);
    }

    kern->flags |= 0x02;
    kern->proporportionalSpacing = ceil(spacing);

    return kern->proporportionalSpacing;
}

float CGxFont::ComputeStepFixedWidth(uint32_t currentCode, uint32_t nextCode) {
    // TODO
    return 0.0f;
}

float CGxFont::GetGlyphBearing(const CHARCODEDESC *glyph, bool billboarded, float height) {
    if (billboarded) {
        float v8 = ScreenToPixelHeight(1, height) / this->GetPixelSize();
        return glyph->bitmapData.m_glyphBearing * v8;
    }

    return ceil(glyph->bitmapData.m_glyphBearing);
}

int32_t CGxFont::GetGlyphData(GLYPHBITMAPDATA *glyphData, uint32_t code) {
    FT_Face face = FontFaceGetFace(this->m_faceHandle);
    FT_Set_Pixel_Sizes(face, this->m_pixelSize, 0);

    uint32_t v6 = 0;

    if (this->m_flags & 0x8) {
        v6 = 4;
    } else if (this->m_flags & FONT_OUTLINE) {
        v6 = 2;
    }

    return IGxuFontGlyphRenderGlyph(
            face,
            this->m_pixelSize,
            code,
            this->m_baseline,
            glyphData,
            this->m_flags & FONT_MONOCHROME,
            v6
    );
}

const char *CGxFont::GetName(void) const {
    STORM_ASSERT(this->m_faceHandle);

    return FontFaceGetFontName(this->m_faceHandle);
}

uint32_t CGxFont::GetPixelSize() {
    return this->m_pixelSize;
}

int32_t CGxFont::Initialize(const char *name, uint32_t newFlags, float fontHeight) {
    SStrPrintf(this->m_fontName, 260, "%s", name);

    this->m_requestedFontHeight = fontHeight;

    this->Clear();

    this->m_flags = newFlags;

    this->m_faceHandle = FontFaceGetHandle(name, GetFreeTypeLibrary());

    if (this->m_faceHandle) {
        return this->UpdateDimensions();
    } else {
        return 0;
    }
}

const CHARCODEDESC *CGxFont::NewCodeDesc(uint32_t code) {
    HASHKEY_NONE key = {};
    CHARCODEDESC * charDesc = this->m_activeCharacters.Ptr(code, key);

    if (charDesc) {
        this->m_activeCharacterCache.LinkToHead(charDesc);
        return charDesc;
    }

    GLYPHBITMAPDATA data;

    if (!CGxFont::GetGlyphData(&data, code)) {
        return nullptr;
    }

    // Attempt to allocate the character off of texture caches
    for (uint32_t textureNumber = 0; textureNumber < 8; textureNumber++) {
        TEXTURECACHE *textureCache = &this->m_textureCache[textureNumber];

        if (textureCache->m_texture &&
            TextureGetGxTex(reinterpret_cast<CTexture *>(textureCache->m_texture), 1, nullptr)) {
            charDesc = textureCache->AllocateNewGlyph(&data);

            if (charDesc) {
                charDesc->textureNumber = textureNumber;
                break;
            }
        } else {
            textureCache->CreateTexture(this->m_flags & 0x4);
            textureCache->Initialize(this, this->m_cellHeight);

            charDesc = textureCache->AllocateNewGlyph(&data);

            if (charDesc) {
                charDesc->textureNumber = textureNumber;
            }

            break;
        }
    }

    // No character was allocated from the texture caches, so evict the oldest character and
    // attempt to allocate from that character's texture cache row
    if (!charDesc) {
        CHARCODEDESC * oldestDesc = this->m_activeCharacterCache.Tail();

        if (oldestDesc) {
            uint32_t textureNumber = oldestDesc->textureNumber;
            uint32_t rowNumber = oldestDesc->rowNumber;

            TEXTURECACHE *textureCache = &this->m_textureCache[textureNumber];
            TEXTURECACHEROW *cacheRow = &textureCache->m_textureRows[rowNumber];
            cacheRow->EvictGlyph(oldestDesc);

            this->RegisterEvictNotice(textureNumber);

            charDesc = cacheRow->CreateNewDesc(&data, rowNumber, this->m_cellHeight);

            if (charDesc) {
                charDesc->rowNumber = rowNumber;
                charDesc->textureNumber = textureNumber;
            }
        }
    }

    if (charDesc) {
        this->m_activeCharacters.Insert(charDesc, code, key);
        this->m_activeCharacterCache.LinkToHead(charDesc);
        this->m_textureCache[charDesc->textureNumber].m_anyDirtyGlyphs = 1;
    }

    return charDesc;
}

void CGxFont::RegisterEvictNotice(uint32_t a2) {
    // TODO
}

int32_t CGxFont::UpdateDimensions() {
    FT_Face theFace = FontFaceGetFace(this->m_faceHandle);

    float v11 = Sub6C2280(theFace, this->m_requestedFontHeight);
    float v3 = 2.0 / GetScreenPixelHeight();

    if (v11 > v3) {
        v3 = v11;
    }

    float height = v3;

    uint32_t pixelSize = ScreenToPixelHeight(0, height);

    if (pixelSize <= 32) {
        if (!pixelSize) {
            // TODO
            // nullsub_3();
        }
    } else {
        pixelSize = 32;
    }

    this->m_pixelSize = pixelSize;

    uint32_t v10 = theFace->ascender + abs(theFace->descender);

    if (!v10) {
        return 0;
    }

    this->m_cellHeight = pixelSize;
    float baseline = (double) (pixelSize * theFace->ascender) / (double) v10;

    this->m_baseline = (int64_t)(baseline + 0.5);

    uint32_t flags = this->m_flags;

    if (flags & 0x8) {
        this->m_cellHeight = pixelSize + 4;
    } else if (flags & 0x1) {
        this->m_cellHeight = pixelSize + 2;
    }

    int32_t result = FT_Set_Pixel_Sizes(theFace, pixelSize, 0) == FT_Err_Ok;

    this->m_pixelsPerUnit = (double) theFace->size->metrics.x_ppem / (double) theFace->units_per_EM;

    return result;
}
