// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

#ifndef ENGINE_C22UMATRIX_H
#define ENGINE_C22UMATRIX_H

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

#endif //ENGINE_C22UMATRIX_H
