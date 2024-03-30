#pragma once

#include "common.h"


class CHARCODEDESC : public TSHashObject<CHARCODEDESC, HASHKEY_NONE> {
public:
    // Member variables
    TSLink<CHARCODEDESC> textureRowLink;
    TSLink<CHARCODEDESC> fontGlyphLink;
    uint32_t textureNumber = -1;
    uint32_t rowNumber = -1;
    uint32_t glyphStartPixel = -1;
    uint32_t glyphEndPixel = 0;
    GLYPHBITMAPDATA bitmapData;

    // Member functions
    uint32_t GapToNextTexture(void);

    uint32_t GapToPreviousTexture(void);

    void GenerateTextureCoords(uint32_t, uint32_t);
};
