// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2019/5/9.
//

#ifndef ENGINE_C2UVECTOR_H
#define ENGINE_C2UVECTOR_H

#include "C2iVector.h"
#include "CuMath.h"

namespace NTempest {
    class C2uVector {
    public:
        C2uVector(C2iVector *that) {
            sub_D5CD6(&this->x, that->x);
            sub_D5CD6(&this->y, that->y);
        }

        C2uVector(unsigned int *a2, unsigned int *a3) {
            this->x = *a2;
            this->y = *a3;
        }

        C2uVector() {
            this->y = 0;
            this->x = 0;
        }

        C2uVector(const C2uVector *that) {
            this->x = that->x;
            this->y = that->y;
        }

        C2uVector *SquaredMag() {
            char v2[4];
            char v3[12];

            sub_D4F30(v2);
            sub_D4F30(v3);
            sub_D560C(&this->x, (unsigned int *) v3, (unsigned int *) v2);
            return this;
        }

        C2uVector *Mag() {
            C2uVector v2;
            v2.SquaredMag();
            sub_D5144(this, v2);
            return this;
        }

        C2uVector *operator+=(C2uVector *that) {
            unsigned int a1;
            int v4[3];

            sub_D560C(&a1, &this->x, &that->x);
            this->x = a1;
            sub_D560C((unsigned int *) v4, &this->y, &that->y);
            this->y = v4[0];
            return this;
        }

        C2uVector *SquaredDist(const C2uVector *that) {
            sub_D6070(this);
            return this;
        }

        C2uVector(unsigned int *a2) {
            unsigned int result;
            this->x = *a2;
            this->y = *a2;
        }

        int FromAxisAngle() {
            char v2[4];
            char v3[4];
            char v4[4];
            char v5[12];

            sub_D6B84(v3);
            sub_D4F30(v2);
            sub_D6CE0(v5);
            sub_D4F30(v4);
            *this = C2uVector((unsigned int *) v4, (unsigned int *) v2);
            return this;
        }

        C2uVector *operator/=(const int *a2) {
            NTempest::C2uVector v3;

            softFloatDiv(&v3.x, this, a2);
            this->x = v3.x;
            softFloatDiv(&v3.y, &this->y, a2);
            this->y = v3.y;
            return this;
        }

        C2uVector *AxisAngle() {
            C2uVector v2;

            v2.Mag();
            sub_6383EC(this);
            return this;
        }

        C2uVector *operator-(unsigned int *a2) {
            unsigned int v3;
            unsigned int v4[3];

            v3 = a2[1] + 0x80000000;
            v4[0] = *a2 + 0x80000000;
            *this = C2uVector(v4, &v3);
            return this;
        }

        float *AngleToAxisAngle(float *a1, float *a2) {
            unsigned int v3[2];
            float v4[7];

            v3[0] = *(unsigned int *) a2;
            v3[1] = v3[0] & 0x7FFFFFFF;
            if (COERCE_FLOAT(v3[0] & 0x7FFFFFFF) >= *(float *) &dword_F69FA0) {
                sub_D5BEA(v4);
                *(float *) v3 = v4[0];
            }
            if (flt_F6A138 <= *(float *) v3)
                *a1 = *(float *) v3;
            else
                sub_D560C((unsigned int *) a1, v3, (unsigned int *) &dword_F69FA0);
            return a1;
        }

        int Scale() {
            int result;
            char v2[4];
            char v3[4];
            unsigned int v4;
            int v5[3];

            CuMath::hypotinv_(v3);
            sub_D4F30(v2);
            sub_D4F30(&v4);
            this->x = v4;
            sub_D4F30(v5);
            result = v5[0];
            this->y = v5[0];
            return result;
        }

        C2uVector asC2Vector() {
            return *this;
        }

        C2uVector *Dot(const C2uVector *a2, const C2uVector *a3) {
            char v4[4];
            char v5[12];

            sub_D4F30(v4);
            sub_D4F30(v5);
            sub_D560C(&this->x, (unsigned int *) v5, (unsigned int *) v4);
            return this;
        }

        int Normalize() {
            int result;
            char v2[4];
            unsigned int v3;
            int v4[3];

            CuMath::hypotinv_(v2);
            sub_D4F30(&v3);
            this->x = v3;
            sub_D4F30(v4);
            result = v4[0];
            this->y = v4[0];
            return result;
        }

        C2uVector *operator-=(float *a3) {
            unsigned int a1;
            int v4[3];

            sub_D546C(&a1, (float *) &this->x, a3);
            this->x = a1;
            sub_D546C(v4, (float *) &this->y, a3 + 1);
            this->y = v4[0];
            return this;
        }

        C2uVector *operator*=() {
            unsigned int v2;
            int v3[3];

            sub_D4F30(&v2);
            this->x = v2;
            sub_D4F30(v3);
            this->y = v3[0];
            return this;
        }

    public:
        unsigned int x;
        unsigned int y;
    };
}

#endif //ENGINE_C2UVECTOR_H
