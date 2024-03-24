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

namespace NTempest {
    class CuRect {
    public:
        CuRect(uint32_t *a2, uint32_t *a3, uint32_t *a4, int *a5) {
            *miny = *a2;
            miny[1] = *a3;
            miny[2] = *a4;
            miny[3] = *a5;
        }

        int Offset(unsigned int *a2, unsigned int *a3) {
            int result;
            unsigned int v4;
            unsigned int v5;
            unsigned int v6;
            int v7[3];

            sub_D560C(&v4, miny, a3);
            *miny = v4;
            sub_D560C(&v5, miny + 1, a2);
            miny[1] = v5;
            sub_D560C(&v6, miny + 2, a3);
            miny[2] = v6;
            sub_D560C((unsigned int *) v7, miny + 3, a2);
            result = v7[0];
            miny[3] = v7[0];
            return result;
        }

        CuRect(uint32_t *a2) {
            *miny = *a2;
            miny[1] = *a2;
            miny[2] = *a2;
            miny[3] = *a2;
        }

        bool Contains(const C2uVector *a2) {
            float v2;
            bool result;

            result = 0;
            if (*(float *) &a2->x > *(float *) &this->minx && *(float *) &this->maxx > *(float *) &a2->x) {
                v2 = *(float *) &a2->y;
                if (v2 > *(float *) &this->miny && *(float *) &this->maxy > v2)
                    result = 1;
            }
            return result;
        }

        CuRect() {
            this->maxx = 0;
            this->maxy = 0;
            this->minx = 0;
            this->miny = 0;
        }

        int ValueV(int a1, float *a2) {
            char v3[4];
            int v4[3];

            sub_D546C(v4, a2 + 2, a2);
            sub_631BF4(v3);
            sub_D560C((unsigned int *) a1, (unsigned int *) a2, (unsigned int *) v3);
            return a1;
        }

        int ValueH(int a1, int a2) {
            char v3[4];
            int v4[3];

            sub_D546C(v4, (float *) (a2 + 12), (float *) (a2 + 4));
            sub_631BF4(v3);
            sub_D560C((unsigned int *) a1, (unsigned int *) (a2 + 4), (unsigned int *) v3);
            return a1;
        }

        bool NotEmpty() {
            return *(float *) &this->maxy > *(float *) &this->miny && *(float *) &this->maxx > *(float *) &this->minx;
        }

        CuRect(const CiRect *a2) {
            sub_D5CD6(&this->miny, a2->x);
            sub_D5CD6(&this->minx, a2->y);
            sub_D5CD6(&this->maxy, a2->z);
            sub_D5CD6(&this->maxx, a2->w);
        }

        CuRect(const C2uVector *a2, const C2uVector *a3) {
            this->miny = a2->y;
            this->minx = a2->x;
            this->maxy = a3->y;
            this->maxx = a3->x;
        }

        CuRect(const CuRect *a2) {
            this->miny = a2->miny;
            this->minx = a2->minx;
            this->maxy = a2->maxy;
            this->maxx = a2->maxx;
        }

        CuRect *Center(unsigned int *a2) {
            char v3[4];
            char v4[4];
            char v5[4];
            char v6[28];

            sub_D560C((unsigned int *) v4, a2 + 2, a2);
            sub_D4F30(v3);
            sub_D560C((unsigned int *) v6, a2 + 3, a2 + 1);
            sub_D4F30(v5);
            C2uVector::C2uVector((C2uVector *) this, (unsigned int *) v5, (unsigned int *) v3);
            return this;
        }

        CuRect *Intersection(const CuRect *a2, const CuRect *a3) {
            const CuRect *v3;
            unsigned int *v4;
            unsigned int *v5;
            unsigned int *v6;
            unsigned int *v8;

            v3 = a3;
            v4 = &a3->maxx;
            if (*(float *) &a3->maxx > *(float *) &a2->maxx)
                v4 = &a2->maxx;
            v8 = v4;
            v5 = &a3->maxy;
            if (*(float *) &a3->maxy > *(float *) &a2->maxy)
                v5 = &a2->maxy;
            v6 = &a3->minx;
            if (*(float *) &a2->minx > *(float *) &a3->minx)
                v6 = &a2->minx;
            if (*(float *) &a2->miny > *(float *) &a3->miny)
                v3 = a2;
            CuRect(this, v3, v6, v5, v8);
            return this;
        }

        CuRect *Intersect(const CuRect *a2, CuRect *a3) {
            CuRect v4;

            Intersection(&v4, a2, a3);
            *a2 = v4;
            CuRect(this, a2);
            return this;
        }

        int Stretch(int a1, float *a2, float *a3) {
            int result;
            unsigned int v4;
            unsigned int v5;
            int v6;
            int v7[3];

            sub_D560C(&v4, (unsigned int *) a1, (unsigned int *) a3);
            *(uint32_t *) a1 = v4;
            sub_D560C(&v5, (unsigned int *) (a1 + 4), (unsigned int *) a2);
            *(uint32_t *) (a1 + 4) = v5;
            sub_D546C(&v6, (float *) (a1 + 8), a3);
            *(uint32_t *) (a1 + 8) = v6;
            sub_D546C(v7, (float *) (a1 + 12), a2);
            result = v7[0];
            *(uint32_t *) (a1 + 12) = v7[0];
            return result;
        }

        CuRect *asCRect(uint32_t *a2) {
            CuRect *result;
            unsigned int v3;
            unsigned int v4;
            unsigned int v5;

            result = this;
            v3 = a2[3];
            v4 = a2[2];
            v5 = a2[1];
            this->miny = *a2;
            this->minx = v5;
            this->maxy = v4;
            this->maxx = v3;
            return result;
        }

        int Stretch(const C2uVector *a2) {
            int result;
            unsigned int v3;
            unsigned int v4;
            unsigned int v5;
            int v6[3];

            sub_D560C(&v3, &this->miny, &a2->y);
            this->miny = v3;
            sub_D560C(&v4, &this->minx, &a2->x);
            this->minx = v4;
            sub_D546C(&v5, (float *) &this->maxy, (float *) &a2->y);
            this->maxy = v5;
            sub_D546C(v6, (float *) &this->maxx, (float *) &a2->x);
            result = v6[0];
            this->maxx = v6[0];
            return result;
        }

        CuRect(const C2uVector *a2) {
            this->miny = a2->y;
            *(C2uVector *) &this->minx = *a2;
            this->maxx = a2->x;
        }

    public:
        unsigned int miny;
        unsigned int minx;
        unsigned int maxy;
        unsigned int maxx;
    };
}


#endif //ENGINE_CURECT_H
