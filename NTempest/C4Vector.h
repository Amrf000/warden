#pragma once

#include <cmath>

namespace NTempest {
    class C4Vector {
    public:
        C4Vector();

        C4Vector(float x, float y, float z, float w);

        C4Vector *operator/=(float div);

        C4Vector *Normalize();

    public:
        float x;
        float y;
        float z;
        float w;
    };
}


