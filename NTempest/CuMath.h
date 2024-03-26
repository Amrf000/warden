// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.


#ifndef ENGINE_CUMATH_H
#define ENGINE_CUMATH_H

#include <cstdint>
#include <ntdef.h>


namespace NTempest {
    class CuMath {
    public:
        int fuint_n() {
            char v1[8];

            sub_D5B9E(v1);
            return sub_D4E04(v1);
        }

        int fint_mi() {
            char v1[8];

            sub_D532C(v1);
            return sub_D4E04(v1);
        }

        uint32_t *clamp_(uint32_t *a1, float *a2, float *a3, float *a4) {
            float *v4;

            v4 = a3;
            if (*a3 <= *a2) {
                v4 = a4;
                if (*a2 <= *a4)
                    v4 = a2;
            }
            *a1 = *(uint32_t *) v4;
            return a1;
        }

        bool fequalz_(float *a1, float *a2, float *a3) {
            int v4[3];

            sub_D546C(v4, a1, a2);
            return *a3 > COERCE_FLOAT(v4[0] & 0x7FFFFFFF);
        }

        uint32_t *splitr_(float *a1, uint32_t *a2, float *a3) {
            uint32_t *result;
            int v4;
            int v5[7];

            sub_D5102(&v4);
            *(uint32_t *) a3 = v4;
            if (((*(int *) a1 >> 31) & (2 * *(uint32_t *) a1)) != 0)
                sub_D546C(a3, a3, &flt_F6A0B4);
            sub_D546C(v5, a1, a3);
            result = a2;
            *a2 = v5[0];
            return result;
        }

        int hypotinv_(int a1) {
            char v2[4];
            char v3[4];
            char v4[12];

            sub_D4F30(v3);
            sub_D4F30(v4);
            sub_D560C((unsigned int *) v2, (unsigned int *) v4, (unsigned int *) v3);
            sub_D5244(a1);
            return a1;
        }

        int fuint_pi() {
            char v1[8];

            sub_D527E(v1);
            return sub_D4E04(v1);
        }

        int fint_n() {
            char v1[8];

            sub_D5B9E(v1);
            return sub_D4E04(v1);
        }

        int hypotinv_(int a1) {
            char v2[4];
            char v3[4];
            char v4[4];
            char v5[4];
            char v6[12];

            sub_D4F30(v3);
            sub_D4F30(v5);
            sub_D4F30(v6);
            sub_D560C((unsigned int *) v4, (unsigned int *) v6, (unsigned int *) v5);
            sub_D560C((unsigned int *) v2, (unsigned int *) v4, (unsigned int *) v3);
            sub_D5244(a1);
            return a1;
        }

        uint32_t *fcleanupz_(uint32_t *a1, uint32_t *a2, uint32_t *a3, int a4) {
            uint32_t *v4;

            v4 = a3;
            if (!fequalz_(a2, a3, a4))
                v4 = a2;
            *a1 = *v4;
            return a1;
        }

        uint32_t *fcleanup4_(uint32_t *a1, uint32_t *a2, uint32_t *a3) {
            uint32_t *v3;

            v3 = a3;
            if (!fequalz_(a2, a3, &dword_F69F90))
                v3 = a2;
            *a1 = *v3;
            return a1;
        }

        uint32_t *fcleanup_(uint32_t *a1, uint32_t *a2, uint32_t *a3) {
            uint32_t *v3;

            v3 = a3;
            if (!fequalz_(a2, a3, &dword_F69F94))
                v3 = a2;
            *a1 = *v3;
            return a1;
        }

        int sub_D5B9E(int a1, unsigned int *a2) {
            unsigned int v3[7];

            sub_D560C(v3, a2, (unsigned int *) &dword_F6A0D8);
            sub_D532C(a1);
            return a1;
        }
    };
}


#endif //ENGINE_CUMATH_H
