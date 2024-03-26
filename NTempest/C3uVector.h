// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2019/5/9.
//

#ifndef ENGINE_C3UVECTOR_H
#define ENGINE_C3UVECTOR_H

#include "C3Vector.h"
#include "C2uVector.h"
#include "CuMath.h"

namespace NTempest {
    class C3uVector {
    public:
        C3Vector *asC3Vector(C3Vector *ret) {
            C3Vector *result;
            float v3;
            float v4;

            result = ret;
            v3 = *(float *) &this->z;
            v4 = *(float *) &this->y;
            LODWORD(ret->x) = this->x;
            ret->y = v4;
            ret->z = v3;
            return result;
        }

        C3uVector(int *a) {
            sub_D5CD6(x, *a);
            sub_D5CD6(y, a[1]);
            sub_D5CD6(z, a[2]);
        }

        C3uVector *SquaredMag() {
            char v2[4];
            char v3[4];
            char v4[4];
            char v5[12];

            softFloatMultiply(v2);
            softFloatMultiply(v4);
            softFloatMultiply(v5);
            softFloatAdd((unsigned int *) v3, (unsigned int *) v5, (unsigned int *) v4);
            softFloatAdd(&this->x, (unsigned int *) v3, (unsigned int *) v2);
            return this;
        }

        C3uVector(const C3uVector *that) {
            int result;

            this->x = that->x;
            this->y = that->y;
            result = that->z;
            this->z = result;
        }

        C3uVector(unsigned int *a2, unsigned int *a3, unsigned int *a4) {
            unsigned int result;

            this->x = *a2;
            this->y = *a3;
            result = *a4;
            this->z = *a4;
        }

        C3uVector() {
            C3uVector *result;

            result = this;
            this->z = 0;
            this->y = 0;
            this->x = 0;
        }

        C3uVector(const C2uVector *that) {
            int result;

            this->x = that->x;
            result = that->y;
            this->y = result;
            this->z = 0;
        }

        C3uVector *Mag() {
            C3uVector v2;
            v2.SquaredMag();
            softFloatSqrt(this, (int *) v2);
            return this;
        }

        C3uVector *operator+=(C3uVector *that) {
            unsigned int v3;
            unsigned int v4;
            int v5[3];

            softFloatAdd(&v3, &this->x, &that->x);
            this->x = v3;
            softFloatAdd(&v4, &this->y, &that->y);
            this->y = v4;
            softFloatAdd((unsigned int *) v5, &this->z, &that->z);
            this->z = v5[0];
            return this;
        }

        int Scale() {
            int result;
            char v2[4];
            char v3[4];
            unsigned int v4;
            unsigned int v5;
            int v6[3];

            CuMath::hypotinv_(v3);
            softFloatMultiply(v2);
            softFloatMultiply(&v4);
            this->x = v4;
            softFloatMultiply(&v5);
            this->y = v5;
            softFloatMultiply(v6);
            result = v6[0];
            this->z = v6[0];
            return result;
        }

        int Normalize() {
            int result;
            char v2[4];
            unsigned int v3;
            unsigned int v4;
            int v5[3];

            CuMath::hypotinv_(v2);
            softFloatMultiply(&v3);
            this->x = v3;
            softFloatMultiply(&v4);
            this->y = v4;
            softFloatMultiply(v5);
            result = v5[0];
            this->z = v5[0];
            return result;
        }

        C3uVector *operator*=() {
            unsigned int v2;
            unsigned int v3;
            int v4[3];

            softFloatMultiply(&v2);
            this->x = v2;
            softFloatMultiply(&v3);
            this->y = v3;
            softFloatMultiply(v4);
            this->z = v4[0];
            return this;
        }

    public:
        unsigned int x;
        unsigned int y;
        unsigned int z;
    };
}

#endif //ENGINE_C3UVECTOR_H
