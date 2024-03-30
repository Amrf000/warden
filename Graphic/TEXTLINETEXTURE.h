#pragma once

#include "NTempest.h"
#include "VERT.h"

using namespace NTempest;

class CGxVertexPCT;

class TEXTLINETEXTURE {
public:
    // Static functions
    static TEXTLINETEXTURE *NewTextLineTexture(void);

    static void Recycle(TEXTLINETEXTURE *ptr);

    // Member variables
    TSGrowableArray<VERT, TSCD<VERT>> m_vert;
    TSGrowableArray<CImVector, TSCD<CImVector>> m_colors;

    // Member functions
    void
    WriteGeometry(CGxVertexPCT *, const CImVector &, const C2Vector &, const CImVector &, const C3Vector &, bool, bool,
                  int32_t, int32_t);
};