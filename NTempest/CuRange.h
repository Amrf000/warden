#pragma once

#include "common.h"

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

            softFloatSubtract(v3);
            sub_5E602C(v2);
            softFloatAdd(this);
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
