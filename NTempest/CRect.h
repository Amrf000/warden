


#pragma once

#include "C2Vector.h"

namespace NTempest {
    class CRect {
    public:
        CRect *Clamp(C2Vector &a2) {
            float y;
            float lminy;
            float lminx;

            y = a2.y;
            if (this->miny <= y)
                lminy = fminf(this->maxy, y);
            else
                lminy = this->miny;
            a2.y = lminy;
            if (this->minx <= a2.x)
                lminx = fminf(this->maxx, a2.x);
            else
                lminx = this->minx;
            a2.x = lminx;
            return this;
        }

    public:
        float miny;
        float minx;
        float maxy;
        float maxx;
    };


}


