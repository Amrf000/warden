#pragma once

#include "C2Vector.h"

namespace NTempest {
    class CRect {
    public:
        static CRect Intersection(const CRect &l, const CRect &r) {
            CRect i;

            i.maxX = r.maxX <= l.maxX ? r.maxX : l.maxX;
            i.maxY = r.maxY <= l.maxY ? r.maxY : l.maxY;
            i.minX = r.minX >= l.minX ? r.minX : l.minX;
            i.minY = r.minY >= l.minY ? r.minY : l.minY;

            return i;
        }

        CRect() {
            minY = 0.0f; // t
            minX = 0.0f; // l
            maxY = 0.0f; // b
            maxX = 0.0f; // r
        }

        CRect(float miny,
              float minx,
              float maxy,
              float maxx) : minY(miny), minX(minx), maxY(maxy), maxX(maxx) {}

        bool operator==(const CRect &rect) {
            return this->minX == rect.minX && this->minY == rect.minY && this->maxX == rect.maxX &&
                   this->maxY == rect.maxY;
        }


        bool IsPointInside(const C2Vector &pt) {
            return this->minX <= pt.x && this->maxX >= pt.x && this->minY <= pt.y && this->maxY >= pt.y;
        }

        CRect *Clamp(C2Vector &a2) {
            float y;
            float lminy;
            float lminx;

            y = a2.y;
            if (this->minY <= y)
                lminy = fminf(this->maxY, y);
            else
                lminy = this->minY;
            a2.y = lminy;
            if (this->minX <= a2.x)
                lminx = fminf(this->maxX, a2.x);
            else
                lminx = this->minX;
            a2.x = lminx;
            return this;
        }

    public:
        float minY;
        float minX;
        float maxY;
        float maxX;
    };
}


