#pragma once

#include "ui/Types.h"
#include <cstdint>
#include "NTempest/C2Vector.h"
#include "NTempest/CRect.h"

using namespace NTempest;

class CLayoutFrame;


class CFramePoint {
public:
    // Static variables
    static float const UNDEFINED;

    // Member variables
    C2Vector m_offset;
    CLayoutFrame *m_relative;
    uint32_t m_framePoint: 8;
    uint32_t m_flags: 24;

    // Member functions
    CFramePoint(CLayoutFrame *relative, FRAMEPOINT framePoint, float offsetX, float offsetY);

    CLayoutFrame *GetRelative();

    int32_t GetRelativeRect(CRect &rect);

    void MarkUnused();

    void SetRelative(CLayoutFrame *relative, FRAMEPOINT relativePoint, float offsetX, float offsetY);

    float X(float scale);

    float Y(float scale);
};


