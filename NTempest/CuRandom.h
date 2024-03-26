// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

#ifndef ENGINE_CURANDOM_H
#define ENGINE_CURANDOM_H

#include "CRandom.h"


namespace NTempest {
    class CuRandom {
    public:
        int checksumr_(CRandom **a1, unsigned int a2, unsigned int *a3) {
            return CRandom::checksum32_(*a1, a2, a3);
        }

        int real_(int a1, int a2) {
            unsigned int v3[3];

            v3[0] = CRandom::uint32_(a2) & 0x7FFFFF | 0x3F800000;
            sub_D560C((unsigned int *) a1, v3, &dword_F6A144);
            return a1;
        }

        uint32_t *realp_(uint32_t *a1, int a2) {
            float v3[3];

            LODWORD(v3[0]) = CRandom::uint32_(a2) & 0x7FFFFF | 0x3F800000;
            sub_D546C(a1, &flt_F6A0A4, v3);
            return a1;
        }

        uint32_t *reals_(uint32_t *a1, int a2) {
            int v2;
            float v4[3];

            v2 = CRandom::uint32_(a2);
            LODWORD(v4[0]) = v2 & 0x7FFFFF | 0x3F800000;
            if (v2 >= 0)
                sub_D560C(a1, (unsigned int *) v4, &dword_F6A14C);
            else
                sub_D546C(a1, &flt_F6A0A4, v4);
            return a1;
        }
    };
}


#endif //ENGINE_CURANDOM_H
