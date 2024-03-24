// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2019/5/9.
//

#ifndef ENGINE_C4VECTOR_H
#define ENGINE_C4VECTOR_H

#include <cmath>

namespace NTempest {
    class C4Vector {
    public:
        C4Vector *operator/=(float a2) {
            C4Vector *result;

            result = this;
            this->x = this->x / a2;
            this->y = this->y / a2;
            this->z = this->z / a2;
            this->w = this->w / a2;
            return result;
        }

        C4Vector *Normalize() {
            C4Vector *result;
            float v2;

            result = this;
            v2 = 1.0
                 / sqrt((float) ((float) ((float) ((float) (this->x * this->x) + (float) (this->y * this->y))
                                          + (float) (this->z * this->z))
                                 + (float) (this->w * this->w)));
            this->x = this->x * v2;
            this->y = v2 * this->y;
            this->z = v2 * this->z;
            this->w = v2 * this->w;
            return result;
        }

    public:
        float x;
        float y;
        float z;
        float w;
    };
}

#endif //ENGINE_C4VECTOR_H
