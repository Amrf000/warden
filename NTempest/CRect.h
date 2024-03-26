// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.


#ifndef ENGINE_CRECT_H
#define ENGINE_CRECT_H

#include "C2Vector.h"

namespace NTempest {
    class CRect {
    public:
        CRect *Clamp(C2Vector *a2) {
            float y;
            float miny;
            float minx;

            y = a2->y;
            if (this->miny <= y)
                miny = fminf(this->maxy, y);
            else
                miny = this->miny;
            a2->y = miny;
            if (this->minx <= a2->x)
                minx = fminf(this->maxx, a2->x);
            else
                minx = this->minx;
            a2->x = minx;
            return this;
        }

    public:
        float miny;
        float minx;
        float maxy;
        float maxx;
    };


}

#endif //ENGINE_CRECT_H
