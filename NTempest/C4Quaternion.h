// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.
#ifndef ENGINE_C4QUATERNION_H
#define ENGINE_C4QUATERNION_H

#include "C33Matrix.h"

namespace NTempest {
    class C4Quaternion {
    public:
        C4Quaternion *operator C33Matrix(C33Matrix *that) {
            float v3;
            float v4;
            float v5;
            float v6;
            float v7;
            float v8;
            float v9;
            float v10;
            float v11;
            float v12;
            float v13;
            float v14;
            float v15;
            v3 = that->a1;
            v4 = that->a2;
            v5 = that->a3;
            v6 = that->a4;
            v13 = (float) (v3 + v3) * v6;
            v7 = (float) (v4 + v4) * v6;
            v14 = v6 * (float) (v5 + v5);
            v15 = (float) (v3 + v3) * v3;
            v8 = that->a1 * (float) (v4 + v4);
            v12 = that->a1 * (float) (v5 + v5);
            v9 = (float) (v4 + v4) * v4;
            v10 = v4 * (float) (v5 + v5);
            v11 = v5 * (float) (v5 + v5);
            this->a1 = 1.0 - (float) (v9 + v11);
            this->a2 = v14 + v8;
            this->a3 = v12 - v7;
            this->a4 = v8 - v14;
            this->a5 = 1.0 - (float) (v11 + v15);
            this->a6 = v13 + v10;
            this->a7 = v7 + v12;
            this->a8 = v10 - v13;
            this->a9 = 1.0 - (float) (v9 + v15);
            return this;
        }

    public:
        float x;
        float y;
        float z;
        float w;
    };
}

#endif //ENGINE_C4QUATERNION_H
