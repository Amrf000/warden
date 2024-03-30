#pragma once


#include <cstdint>
#include "NTempest.h"

using namespace NTempest;

class GLYPHBITMAPDATA {
public:
    // Member variables
    void *m_data = nullptr;
    uint32_t m_dataSize = 0;
    uint32_t m_glyphWidth;
    uint32_t m_glyphHeight;
    uint32_t m_glyphCellWidth;
    float m_glyphAdvance;
    float m_glyphBearing;
    uint32_t m_glyphPitch;
    int32_t m_yOffset;
    int32_t m_yStart;
    CRect m_textureCoords;

    // Member functions
    ~GLYPHBITMAPDATA();

    void CopyFrom(GLYPHBITMAPDATA *);
};
