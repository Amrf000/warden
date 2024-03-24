// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2019/5/9.
//

#ifndef ENGINE_C2VECTOR_H
#define ENGINE_C2VECTOR_H

#include <math.h>


namespace NTempest {
    class C2Vector {
    public:
        long double Mag() {
            return sqrtf((float) (this->x * this->x) + (float) (this->y * this->y));
        }

        int FromAxisAngle(float a2) {
            int result;
            float v3;

            sinf(*(float *) &this);
            v3 = cosf(*(float *) &this);
            *(float *) &result = a2 * v3;
            return result;
        }

        void AxisAngle() {
            long double a = Mag();
            sub_659E20(&this->x, (float) a);
        }

    public:
        float x;
        float y;
    };
}

#endif //ENGINE_C2VECTOR_H
