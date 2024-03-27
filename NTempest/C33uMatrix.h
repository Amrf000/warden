// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

#ifndef ENGINE_C33UMATRIX_H
#define ENGINE_C33UMATRIX_H

#include <cstdint>
#include "C33Matrix.h"
#include "C3uVector.h"


namespace NTempest {
    class C33uMatrix {
    public:
        C33Matrix *asC33Matrix(C33Matrix *ret) {
            C3uVector v7(&this->a7, &this->a8, &this->a9);
            C3Vector v8;
            C3uVector v9(&this->a4, &this->a5, &this->a6);
            float v10;
            float v11;
            C3uVector v12(&this->a1, &this->a2, &this->a3);


            v7.asC3Vector(&v5);
            v6 = v5;
            v9.asC3Vector(&v4);
            v8 = v4;
            v12.asC3Vector(&v3);
            v10 = *(float *) &v3.y;
            v11 = *(float *) &v3.z;
            ret->a1 = v3.x;
            ret->a2 = v10;
            ret->a3 = v11;
            *(C3uVector *) &ret->a4 = v8;
            *(C3uVector *) &ret->a7 = v6;
            return ret;
        }

        C33uMatrix() {
            this->a1 = 1065353216;
            this->a2 = 0;
            this->a3 = 0;
            this->a4 = 0;
            this->a5 = 1065353216;
            this->a6 = 0;
            this->a7 = 0;
            this->a8 = 0;
            this->a9 = 1065353216;
        }

        C33uMatrix *Det() {
            softFloatMultiply(&v2);
            softFloatMultiply(v3);
            softFloatSubtract(v3, &v2);
            return this;
        }

        C33uMatrix(uint32_t *a2, uint32_t *a3, uint32_t *a4, uint32_t *a5, uint32_t *a6, uint32_t *a7, uint32_t *a8,
                   uint32_t *a9, int *a10) {
            this->a1 = *a2;
            this->a2 = *a3;
            this->a3 = *a4;
            this->a4 = *a5;
            this->a5 = *a6;
            this->a6 = *a7;
            this->a7 = *a8;
            this->a8 = *a9;
            this->a9 = *a10;
        }

        C33uMatrix *softFloatSubtract(float *a2, float *a3) {
            v3 = *(uint32_t *) a3 + 0x80000000;
            v4 = *(uint32_t *) a2;
            v15 = *(uint32_t *) a2 & 0x7F800000;
            if (!v15)
                goto LABEL_16;
            v16 = v3 & 0x7F800000;
            if ((v3 & 0x7F800000) == 0)
                goto LABEL_15;
            v5 = ((v4 >> 31) ^ ((2 * (v4 & 0x7FFFFF)) | 0x1000000)) - (v4 >> 31);
            v6 = ((v3 >> 31) ^ ((2 * (v3 & 0x7FFFFF)) | 0x1000000)) - (v3 >> 31);
            v7 = v16 - v15;
            if (v16 - v15 > 0) {
                if (v7 <= 192937983) {
                    v5 >>= (unsigned int) v7 >> 23;
                    v15 = v3 & 0x7F800000;
                    goto LABEL_8;
                }
                LABEL_16:
                this->a1 = v3;
                return this;
            }
            if (v7 <= -192937984) {
                LABEL_15:
                this->a1 = v4;
                return this;
            }
            v6 >>= (unsigned int) (v15 - v16) >> 23;
            LABEL_8:
            v8 = v5 + v6;
            if (v8) {
                v14 = v8 & 0x80000000;
                v9 = v8;
                v10 = -v8;
                if (v9 <= -1)
                    v9 = v10;
                if (v9) {
                    _BitScanReverse(&v12, v9);
                    v11 = 8 - (v12 ^ 0x1F);
                } else {
                    v11 = -24;
                }
                this->a1 = ((v9 << -(char) v11) & (v11 >> 31) | ~(v11 >> 31) & (v9 >> v11)) & 0x7FFFFF |
                           ((v11 << 23) + v15 - 0x800000) | v14;
            } else {
                this->a1 = 0;
            }
            return this;
        }

    public:
        C3uVector columns[3];
    };
}

#endif 
