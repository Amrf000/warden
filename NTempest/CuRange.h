// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.


#ifndef ENGINE_CURANGE_H
#define ENGINE_CURANGE_H

#include "CRndSeed.h"

namespace NTempest {
    class CuRange {
    public:
        CuRange(unsigned int *min, unsigned int *max) {
            this->min = *min;
            this->max = *max;
        }

        CuRange *ClampClosed(float *a2, float *a3) {
            float *v3;

            v3 = a2;
            if (*a2 <= *a3) {
                v3 = a2 + 1;
                if (*a3 <= a2[1])
                    v3 = a3;
            }
            this->min = *(unsigned int *) v3;
            return this;
        }

        CuRange *Value(CRndSeed *a2) {
            char v2[4];
            char v3[12];

            sub_D546C(v3);
            sub_5E602C(v2);
            sub_D560C(this);
            return this;
        }

        bool InClosedRange(float *a2) {
            return *a2 >= *(float *) &this->min && *(float *) &this->max >= *a2;
        }

    public:
        unsigned int min;
        unsigned int max;
    };
}


#endif //ENGINE_CURANGE_H
