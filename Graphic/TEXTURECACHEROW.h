#pragma once

#include <cstdint>

class TEXTURECACHEROW {
public:
    // Member variables
    uint32_t widestFreeSlot = 0;
    STORM_EXPLICIT_LIST(CHARCODEDESC, textureRowLink) glyphList;

    // Member functions
    CHARCODEDESC* CreateNewDesc(GLYPHBITMAPDATA*, uint32_t, uint32_t);
    void EvictGlyph(CHARCODEDESC*);
};
