


#pragma once

#include <cmath>

namespace NTempest {
    class C4Vector {
    public:
        C4Vector *operator/=(float div) {
            this->x = this->x / div;
            this->y = this->y / div;
            this->z = this->z / div;
            this->w = this->w / div;
            return this;
        }

        C4Vector *Normalize() {
            float v2;
            v2 = 1.0
                 / sqrt((float) ((float) ((float) ((float) (this->x * this->x) + (float) (this->y * this->y))
                                          + (float) (this->z * this->z))
                                 + (float) (this->w * this->w)));
            this->x = this->x * v2;
            this->y = v2 * this->y;
            this->z = v2 * this->z;
            this->w = v2 * this->w;
            return this;
        }

    public:
        float x;
        float y;
        float z;
        float w;
    };
}


