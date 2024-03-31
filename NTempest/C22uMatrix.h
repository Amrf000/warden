#pragma once

#include "C2uVector.h"
#include "Common/softfloat.h"

namespace NTempest {
    class C22uMatrix {
    public:
        C22uMatrix(uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5) {
            this->a0 = a2;
            this->a1 = a3;
            this->b0 = a4;
            this->b1 = a5;
        }

    public:
        softfloat a0;
        softfloat a1;
        softfloat b0;
        softfloat b1;
    };
}


