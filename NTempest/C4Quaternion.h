#pragma once

#include "C33Matrix.h"

namespace NTempest {
    class C4Quaternion {
    public:
        // Static functions
        static C4Quaternion Nlerp(float ratio, const C4Quaternion &q1, const C4Quaternion &q2);

        C4Quaternion();

        C4Quaternion(float x, float y, float z, float w);

    public:
        float x;
        float y;
        float z;
        float w;
    };

//    C4Quaternion *operator C33Matrix(C33Matrix *that) {
//
//    }
}


