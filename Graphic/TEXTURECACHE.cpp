#include "TEXTURECACHE.h"

uint16_t TEXTURECACHE::s_textureData[256 * 256];

void
TEXTURECACHE::TextureCallback(EGxTexCommand cmd, uint32_t w, uint32_t h, uint32_t d, uint32_t mipLevel, void *userArg,
                              uint32_t &texelStrideInBytes, const void *&texels) {
    TEXTURECACHE *cache = static_cast<TEXTURECACHE *>(userArg);

    switch (cmd) {
        case GxTex_Latch: {
            for (int32_t i = cache->m_textureRows.Count() - 1; i >= 0; i--) {
                auto &cacheRow = cache->m_textureRows[i];

                for (auto glyph = cacheRow.glyphList.Head(); glyph; glyph = cacheRow.glyphList.Next(glyph)) {
                    cache->WriteGlyphToTexture(glyph);
                }
            }

            texelStrideInBytes = 512;
            texels = TEXTURECACHE::s_textureData;

            break;
        };
    }
}

CHARCODEDESC *TEXTURECACHE::AllocateNewGlyph(GLYPHBITMAPDATA *data) {
    for (int32_t i = 0; i < this->m_textureRows.Count(); i++) {
        auto &cacheRow = this->m_textureRows[i];
        CHARCODEDESC *glyph = cacheRow.CreateNewDesc(data, i, this->m_theFace->m_cellHeight);

        if (glyph) {
            return glyph;
        }
    }

    return nullptr;
}

void TEXTURECACHE::CreateTexture(int32_t filter) {
    CGxTexFlags flags = CGxTexFlags(filter ? GxTex_Linear : GxTex_Nearest, 0, 0, 0, 0, 0, 1);

    HTEXTURE texture = TextureCreate(
            256,
            256,
            GxTex_Argb4444,
            GxTex_Argb4444,
            flags,
            this,
            TEXTURECACHE::TextureCallback,
            "GxuFont",
            0
    );

    this->m_texture = texture;
}

void TEXTURECACHE::Initialize(CGxFont *face, uint32_t pixelSize) {
    this->m_theFace = face;

    uint32_t rowCount = 256 / pixelSize;
    this->m_textureRows.SetCount(rowCount);

    for (int32_t i = 0; i < rowCount; i++) {
        this->m_textureRows[i].widestFreeSlot = 256;
    }
}

void TEXTURECACHE::PasteGlyph(const GLYPHBITMAPDATA &data, uint16_t *dst) {
    if (this->m_theFace->m_flags & FONT_OUTLINE) {
        if (this->m_theFace->m_flags & FONT_MONOCHROME) {
            this->PasteGlyphOutlinedMonochrome(data, dst);
        } else {
            this->PasteGlyphOutlinedAA(data, dst);
        }
    } else if (this->m_theFace->m_flags & FONT_MONOCHROME) {
        this->PasteGlyphNonOutlinedMonochrome(data, dst);
    } else {
        this->PasteGlyphNonOutlinedAA(data, dst);
    }
}

void TEXTURECACHE::PasteGlyphNonOutlinedAA(const GLYPHBITMAPDATA &glyphData, uint16_t *dst) {
    auto src = reinterpret_cast<uint8_t *>(glyphData.m_data);
    auto pitch = glyphData.m_glyphPitch;
    auto dstCellStride = glyphData.m_glyphCellWidth * 2;

    for (int32_t y = 0; y < glyphData.m_yStart; y++) {
        memset(dst, 0, dstCellStride);
        dst += 256;
    }

    for (int32_t y = 0; y < glyphData.m_glyphHeight; y++) {
        for (int32_t x = 0; x < glyphData.m_glyphWidth; x++) {
            dst[x] = ((src[x] & 0xF0) << 8) | 0xFFF;
        }

        src += pitch;
        dst += 256;
    }

    auto glyphHeight = glyphData.m_glyphHeight;
    auto yStart = glyphData.m_yStart;
    if (this->m_theFace->m_cellHeight - glyphHeight - yStart > 0 &&
        this->m_theFace->m_cellHeight - glyphHeight != yStart) {
        for (int32_t y = 0; y < this->m_theFace->m_cellHeight - glyphHeight - yStart; y++) {
            memset(dst, 0, dstCellStride);
            dst += 256;
        }
    }
}

void TEXTURECACHE::PasteGlyphNonOutlinedMonochrome(const GLYPHBITMAPDATA &data, uint16_t *dst) {
    // TODO
}

void TEXTURECACHE::PasteGlyphOutlinedAA(const GLYPHBITMAPDATA &glyphData, uint16_t *dst) {
    uint32_t v6;
    uint32_t v7;
    uint16_t *v8;
    int32_t v9;
    int32_t v15;
    int32_t v16;
    uint32_t v17;
    uint32_t v18;
    uint32_t v19;
    uint32_t v20;
    int32_t v21;
    int32_t v22;
    int32_t v23;
    int32_t v24;
    int32_t v25;
    uint32_t v26;
    uint32_t v27;
    uint32_t v28;
    bool v29;
    bool v30;
    int32_t v31;
    int32_t v32;
    int32_t v33;
    int32_t v34;
    int32_t v35;
    int32_t v36;
    bool v37;
    int32_t v38;
    int32_t v39;
    int32_t v40;
    uint32_t v41;
    uint8_t v42;
    bool v43;
    uint16_t v44[9216];
    uint16_t v45[9216];
    uint16_t v46[9216];
    uint32_t v49;
    uint16_t *v52;
    uint32_t v52_2;
    uint32_t v52_3;
    int32_t v53;

    static uint8_t pixelsLitLevels[] = {
            0, 1, 1, 3, 5, 7, 9, 0xB, 0xD, 0xF, 0, 0
    };

    const char *src = reinterpret_cast<char *>(glyphData.m_data);
    uint32_t thick = this->m_theFace->m_flags & 0x8;

    memset(v45, 0, sizeof(v45));
    memset(v46, 0, sizeof(v46));

    uint32_t ofs = thick
                   ? 256 * glyphData.m_yStart + 258
                   : 256 * glyphData.m_yStart + 257;

    for (int32_t y = 0; y < glyphData.m_glyphHeight; y++) {
        for (int32_t x = 0; x < glyphData.m_glyphWidth; x++) {
            uint8_t v10 = src[(y * glyphData.m_glyphPitch) + x];

            if (v10) {
                v45[ofs + (y * 256) + x] = v10;
                v46[ofs + (y * 256) + x] = 1;
            }
        }
    }

    v52_2 = 0;

    v15 = glyphData.m_yStart - 1;

    for (int32_t i = 0; i < (thick != 0) + 1; i++) {
        v49 = 2 * (i != 0) + 2;
        v16 = 2 * (i != 0) + 1;
        v17 = v15 < 0 ? 0 : v15;
        v53 = v15 < 0 ? 0 : v15;

        if (v17 >= this->m_theFace->m_cellHeight) {
            continue;
        }

        do {
            v18 = glyphData.m_glyphCellWidth;
            v19 = v17 << 8;
            v20 = 0;

            if (!v18) {
                goto LABEL_68;
            }

            do {
                v21 = v19 + v20;

                if (v46[v19 + v20] & v16) {
                    goto LABEL_66;
                }

                if (v53) {
                    if (v53 == this->m_theFace->m_cellHeight - 1) {
                        if (v20) {
                            if (v20 == v18 - 1) {
                                if (
                                        v46[v21 - 1] & v16
                                        || v46[v19 + v20 - 257] & v16
                                        ) {
                                    goto LABEL_65;
                                }

                                v22 = v46[v19 + v20 - 256];
                            } else {
                                if (
                                        v46[v19 + v20 - 257] & v16
                                        || v46[v19 + v20 - 256] & v16
                                        || v46[v19 + v20 - 255] & v16
                                        || v46[v21 - 1] & v16
                                        ) {
                                    goto LABEL_65;
                                }

                                v22 = v46[v21 + 1];
                            }
                        } else {
                            if (
                                    v46[v19 - 256] & v16
                                    || v46[v19 - 255] & v16
                                    ) {
                                goto LABEL_65;
                            }

                            v22 = v46[v19 + 1];
                        }
                    } else if (v20) {
                        v24 = v19 + v20;

                        if (v20 == v18 - 1) {
                            if (
                                    v46[v24 - 256] & v16
                                    || v46[v19 + v20 - 257] & v16
                                    || v46[v21 - 1] & v16
                                    || v46[v21 + 255] & v16
                                    ) {
                                goto LABEL_65;
                            }

                            v22 = v46[v21 + 256];
                        } else {
                            if (
                                    v46[v24 - 257] & v16
                                    || v46[v19 + v20 - 256] & v16
                                    || v46[v19 + v20 - 255] & v16
                                    || v46[v21 - 1] & v16
                                    || v46[v21 + 1] & v16
                                    || v46[v21 + 255] & v16
                                    || v46[v21 + 256] & v16
                                    ) {
                                goto LABEL_65;
                            }

                            v22 = v46[v21 + 257];
                        }
                    } else {
                        if (
                                v46[v19 - 256] & v16
                                || v46[v19 - 255] & v16
                                || v46[v19 + 1] & v16
                                || v46[v19 + 257] & v16
                                ) {
                            goto LABEL_65;
                        }

                        v22 = v46[v19 + 256];
                    }
                    LABEL_64:
                    if (!(v22 & v16)) {
                        goto LABEL_66;
                    }

                    goto LABEL_65;
                }

                if (v20) {
                    v23 = v46[v20 - 1];

                    if (v20 == v18 - 1) {
                        if (!(v23 & v16) && !(v46[v20 + 255] & v16)) {
                            v22 = v46[v20 + 256];
                            goto LABEL_64;
                        }
                    } else if (!(v23 & v16) && !(v46[v20 + 1] & v16) && !(v46[v20 + 255] & v16) &&
                               !(v46[v20 + 256] & v16)) {
                        v22 = v46[v20 + 257];
                        goto LABEL_64;
                    }
                } else if (!(v46[1] & v16) && !(v46[257] & v16)) {
                    v22 = v46[256];
                    goto LABEL_64;
                }
                LABEL_65:
                v46[v21] = v49;
                LABEL_66:
                ++v20;
            } while (v20 < v18);

            v17 = v53;
            LABEL_68:
            v53 = ++v17;
        } while (v17 < this->m_theFace->m_cellHeight);
    }

    memset(v44, 0, sizeof(v44));

    v26 = 0;
    v53 = 0;

    if (!this->m_theFace->m_cellHeight) {
        goto LABEL_95;
    }

    while (2) {
        v27 = glyphData.m_glyphCellWidth;
        v28 = v26 << 8;
        v25 = 0;

        if (!v27) {
            goto LABEL_94;
        }

        while (2) {
            v37 = v46[v28 + v25] == 0;
            v52 = &v46[v28 + v25];
            v29 = !v37;
            v30 = !v37;

            if (v26) {
                if (v53 == this->m_theFace->m_cellHeight - 1) {
                    if (!v25) {
                        v31 = v30 + (v46[v28 + 1] != 0) + (v46[v28 - 255] != 0) + (v46[v28 - 256] != 0);
                        goto LABEL_92;
                    }

                    v37 = v25 == v27 - 1;
                    v34 = v28 + v25;

                    if (v37) {
                        v31 = (v46[v28 + v25 - 256] != 0) + (v46[v34 - 257] != 0) + v30 + (*(v52 - 1) != 0);
                        goto LABEL_92;
                    }

                    v35 = (v46[v34 - 256] != 0) + (v46[v28 + v25 - 257] != 0);
                    v36 = 0;
                    v37 = v46[v28 + v25 - 255] == 0;
                    v38 = v28 + v25;
                } else {
                    if (!v25) {
                        v31 = v30
                              + (v46[v28 + 256] != 0)
                              + (v46[v28 + 1] != 0)
                              + (v46[v28 + 257] != 0)
                              + (v46[v28 - 255] != 0)
                              + (v46[v28 - 256] != 0);

                        goto LABEL_92;
                    }

                    v37 = v25 == v27 - 1;
                    v39 = v28 + v25;

                    if (v37) {
                        v31 = (v46[v28 + v25 + 256] != 0)
                              + (v46[v28 + v25 + 255] != 0)
                              + (v46[v28 + v25 - 256] != 0)
                              + (v46[v39 - 257] != 0)
                              + v30
                              + (*(v52 - 1) != 0);

                        goto LABEL_92;
                    }

                    v37 = v46[v39 - 256] == 0;
                    v38 = v28 + v25;
                    v35 = (v46[v28 + v25 + 256] != 0)
                          + (v46[v28 + v25 + 255] != 0)
                          + (v46[v28 + v25 - 255] != 0)
                          + !v37
                          + (v46[v28 + v25 - 257] != 0);
                    v36 = 0;
                    v37 = v46[v28 + v25 + 257] == 0;
                }

                v36 = !v37;
                v31 = (v46[v38 + 1] != 0) + v36 + v35 + v30 + (*(v52 - 1) != 0);
            } else if (v25) {
                if (v25 == v27 - 1) {
                    v32 = (v46[v25 + 255] != 0) + (v46[v25 - 1] != 0);
                    v33 = v29 + (v46[v25 + 256] != 0);
                } else {
                    v32 = (v46[v25 + 257] != 0)
                          + (v46[v25 + 256] != 0)
                          + (v46[v25 + 255] != 0)
                          + (v46[v25 - 1] != 0);
                    v33 = v29 + (v46[v25 + 1] != 0);
                }

                v31 = v33 + v32;
            } else {
                v31 = v29 + (v46[1] != 0) + (v46[257] != 0) + (v46[256] != 0);
            }
            LABEL_92:
            v26 = v53;

            v44[v28 + v25] = pixelsLitLevels[v31];

            v27 = glyphData.m_glyphCellWidth;

            if (++v25 < v27) {
                continue;
            }

            break;
        }

        LABEL_94:
        v53 = ++v26;

        if (v26 < this->m_theFace->m_cellHeight) {
            continue;
        }

        break;
    }

    LABEL_95:
    v40 = 0;

    for (int32_t y = 0; y < this->m_theFace->m_cellHeight; y++) {
        for (int32_t x = 0; x < glyphData.m_glyphCellWidth; x++) {
            if (v46[v40 + x]) {
                if (v45[v40 + x]) {
                    v42 = (255 * v45[v40 + x]) >> 12;
                    dst[v40 + x] = v42 | (16 * (v42 | (16 * (v42 | (16 * v44[v40 + x])))));
                } else {
                    dst[v40 + x] = v44[v40 + x] << 12;
                }
            } else {
                dst[v40 + x] = 0;
            }
        }

        v40 += 256;
    }
}

void TEXTURECACHE::PasteGlyphOutlinedMonochrome(const GLYPHBITMAPDATA &data, uint16_t *dst) {
    // TODO
}

void TEXTURECACHE::UpdateDirty() {
    if (this->m_anyDirtyGlyphs && this->m_texture) {
        CGxTex *gxTex = TextureGetGxTex(this->m_texture, 1, nullptr);
        CiRect updateRect = {0, 0, 256, 256};
        GxTexUpdate(gxTex, updateRect, 1);

        this->m_anyDirtyGlyphs = 0;
    }
}

void TEXTURECACHE::WriteGlyphToTexture(CHARCODEDESC *glyph) {
    if (!this->m_texture || !this->m_theFace || !this->m_theFace->m_cellHeight) {
        return;
    }

    uint32_t ofs = glyph->glyphStartPixel + (glyph->rowNumber * this->m_theFace->m_cellHeight << 8);
    uint16_t *ptr = &TEXTURECACHE::s_textureData[ofs];

    this->PasteGlyph(glyph->bitmapData, ptr);
}
