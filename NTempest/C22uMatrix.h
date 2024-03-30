

#pragma once

#include "C2uVector.h"

namespace NTempest {
    class C22uMatrix {
    public:
        C22uMatrix(unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5) {
            this->columns[0].x = a2;
            this->columns[0].y = a3;
            this->columns[1].x = a4;
            this->columns[1].y = a5;
        }

    public:
        C2uVector columns[2];
    };
}


