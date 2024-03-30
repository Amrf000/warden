//
// Created by liuyawu on 2024/3/30.
//

#pragma once


#include <cstdint>
#include "const/EGxTexCommand.h"
#include "CGxFont.h"
#include "TEXTURECACHEROW.h"
#include "CHARCODEDESC.h"
#include "GLYPHBITMAPDATA.h"

class TEXTURECACHE {
public:
    // Static variables
    static uint16_t s_textureData[256 * 256];

    // Static functions
    static void
    TextureCallback(EGxTexCommand, uint32_t, uint32_t, uint32_t, uint32_t, void *, uint32_t &, const void *&);

    // Member variables
    HTEXTURE m_texture = nullptr;
    CGxFont *m_theFace = nullptr;
    int8_t m_anyDirtyGlyphs = 0;
    int8_t pad[3];
    TSFixedArray<TEXTURECACHEROW, TSCD<TEXTURECACHEROW>> m_textureRows;

    // Member functions
    CHARCODEDESC *AllocateNewGlyph(GLYPHBITMAPDATA *);

    void CreateTexture(int32_t);

    void Initialize(CGxFont *, uint32_t);

    void PasteGlyph(const GLYPHBITMAPDATA &, uint16_t *);

    void PasteGlyphNonOutlinedAA(const GLYPHBITMAPDATA &, uint16_t *);

    void PasteGlyphNonOutlinedMonochrome(const GLYPHBITMAPDATA &, uint16_t *);

    void PasteGlyphOutlinedAA(const GLYPHBITMAPDATA &, uint16_t *);

    void PasteGlyphOutlinedMonochrome(const GLYPHBITMAPDATA &, uint16_t *);

    void UpdateDirty(void);

    void WriteGlyphToTexture(CHARCODEDESC *);
};
