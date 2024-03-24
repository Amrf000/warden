// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2019/5/9.
//

#ifndef ENGINE_CURECT_H
#define ENGINE_CURECT_H

#include <cstdint>
#include <ntdef.h>
#include "C2uVector.h"
#include "CRandSeed.h"

namespace NTempest {
    class CuRect {
    public:
        CuRect() {
            this->maxx = 0;
            this->maxy = 0;
            this->minx = 0;
            this->miny = 0;
        }

        CuRect(unsigned int *miny, unsigned int *minx, unsigned int *maxy, unsigned int *maxx) {
            this->maxx = *miny;
            this->maxy = *minx;
            this->minx = *maxy;
            this->miny = *maxx;
        }

        CuRect(unsigned int *val) {
            this->miny = *val;
            this->minx = *val;
            this->maxy = *val;
            this->maxx = *val;
        }

        CuRect(const CuRect *that) {
            *this = *that;
        }

        CuRect(const CiRect *that) {
            sub_D5CD6(this);
            sub_D5CD6(&this->minx);
            sub_D5CD6(&this->maxy);
            sub_D5CD6(&this->maxx);
        }

        CuRect(const C2uVector *topLeft, const C2uVector *downRight) {
            this->miny = topLeft->y;
            this->minx = topLeft->x;
            this->maxy = downRight->y;
            this->maxx = downRight->x;
        }

        CuRect(const C2uVector *pos) {
            this->miny = pos->y;
            this->minx = pos->x;
            this->maxy = pos->y;
            this->maxx = pos->x;
        }

        bool Contains(const C2uVector *pos) {
            float v2;
            bool result = 0;
            if (*(float *) &pos->x > *(float *) &this->minx && *(float *) &this->maxx > *(float *) &pos->x) {
                v2 = *(float *) &pos->y;
                if (v2 > *(float *) &this->miny && *(float *) &this->maxy > v2)
                    return 1;
            }
            return result;
        }

        C2uVector *Center() {
            char v2[4];
            char v3[4];
            char v4[4];
            char v5[28];

            sub_D560C(v3);
            sub_D4F30(v2);
            sub_D560C(v5);
            sub_D4F30(v4);
            C2uVector *ret = new C2uVector(v4, v2);
            return ret;
        }

        CuRect *Intersect(CuRect *a2) {
            CuRect v4;

            CuRect::Intersection(&v4, a2, a3);
            *a2 = v4;
            CuRect::CuRect(a2);
            return this;
        }

        CuRect *Intersection(const CuRect *rect1, const CuRect *rect2) {
            const CuRect *v3;
            unsigned int *p_maxx;
            unsigned int *p_maxy;
            unsigned int *p_minx;
            int v8;

            v3 = rect2;
            p_maxx = &rect2->maxx;
            if (*(float *) &rect2->maxx > *(float *) &rect1->maxx)
                p_maxx = &rect1->maxx;
            v8 = (int) p_maxx;
            p_maxy = &rect2->maxy;
            if (*(float *) &rect2->maxy > *(float *) &rect1->maxy)
                p_maxy = &rect1->maxy;
            p_minx = &rect2->minx;
            if (*(float *) &rect1->minx > *(float *) &rect2->minx)
                p_minx = &rect1->minx;
            if (*(float *) &rect1->miny > *(float *) &rect2->miny)
                v3 = rect1;
            CuRect::CuRect((int) this, (int) v3, (int) p_minx, (int) p_maxy, v8);
            return this;
        }

        bool NotEmpty() {
            return *(float *) &this->maxy > *(float *) &this->miny && *(float *) &this->maxx > *(float *) &this->minx;
        }

        int Offset(unsigned int *x, unsigned int *y) {
            unsigned int v3;
            unsigned int v4;
            unsigned int v5;
            unsigned int v6;

            sub_D560C(&v3);
            this->miny = v3;
            sub_D560C(&v4);
            this->minx = v4;
            sub_D560C(&v5);
            this->maxy = v5;
            sub_D560C(&v6);
            this->maxx = v6;
        }

        void Stretch(C2uVector *size) {
            unsigned int v3;
            unsigned int v4;
            unsigned int v5;
            unsigned int v6;

            sub_D560C(&v3);
            this->miny = v3;
            sub_D560C(&v4);
            this->minx = v4;
            sub_D546C(&v5);
            this->maxy = v5;
            sub_D546C(&v6);
            this->maxx = v6;
        }

        void Stretch(const int *x, const int *y) {
            unsigned int v4;
            unsigned int v5;
            unsigned int v6;
            unsigned int v7;

            sub_D560C(&v4);
            this->miny = v4;
            sub_D560C(&v5);
            this->minx = v5;
            sub_D546C(&v6);
            this->maxy = v6;
            sub_D546C(&v7);
            this->maxx = v7;
        }

        CuRect *ValueH(CRandSeed *seed) {
            char v3[4];
            char v4[12];

            sub_D546C(v4);
            sub_631BF4(v3);
            sub_D560C(this);
            return this;
        }

        CuRect *ValueV(CRandSeed *seed) {
            char v3[4];
            char v4[12];

            sub_D546C(v4);
            sub_631BF4(v3);
            sub_D560C(this);
            return this;
        }

        CRect *asCRect() {
            CRect result;
            result.miny = *(float *) &this->miny;
            result.minx = *(float *) &this->minx;
            result.maxy = *(float *) &this->maxy;
            result.maxx = *(float *) &this->maxx;
            return &result;
        }

    public:
        unsigned int miny;
        unsigned int minx;
        unsigned int maxy;
        unsigned int maxx;
    };
}


#endif //ENGINE_CURECT_H
