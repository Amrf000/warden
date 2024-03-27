// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2019/5/9.
//

#ifndef ENGINE_C3VECTOR_H
#define ENGINE_C3VECTOR_H

#include <cmath>
#include <ntdef.h>

namespace NTempest {
    class C3Vector {
    public:
        long double Mag() {
            return sqrtf((float) ((float) (this->x * this->x) + (float) (this->y * this->y)) +
                         (float) (this->z * this->z));
        }

        C3Vector *ProjectionOnPlane(const C3Vector *a2, const C3Vector *a3) {
            v4 = a2->x;
            v5 = a3->x;
            v6 = a2->y;
            v7 = a3->y;
            v8 = a3->z;
            v9 = (float) ((float) (a2->x * a3->x) + (float) (v6 * v7)) + (float) (a2->z * v8);
            this->z = a2->z - (float) (v8 * v9);
            this->y = v6 - (float) (v7 * v9);
            this->x = v4 - (float) (v5 * v9);
            return this;
        }

        C3Vector *NearestOnPlane(const C3Vector *a2, const C3Vector *a3, const C3Vector *a4) {
            v4 = a2->y - a3->y;
            v5 = a2->x - a3->x;
            v10.z = a2->z - a3->z;
            v10.y = v4;
            v10.x = v5;
            ProjectionOnPlane(v9, &v10, a4);
            v9[2] = v9[0];
            v6 = a3->y + v9[0].y;
            v7 = a3->x + v9[0].x;
            this->z = a3->z + v9[0].z;
            this->y = v6;
            this->x = v7;
            return this;
        }

        C3Vector *Normalize() {
            float v2;
            v2 = 1.0
                 / sqrt((float) ((float) ((float) (this->x * this->x) + (float) (this->y * this->y)) +
                                 (float) (this->z * this->z)));
            this->x = this->x * v2;
            this->y = v2 * this->y;
            this->z = v2 * this->z;
            return this;
        }

        bool IsUnit() {
            return fabs(
                    (float) ((float) ((float) (this->x * this->x) + (float) (this->y * this->y)) +
                             (float) (this->z * this->z))
                    - 1.0) < 0.001;
        }

        C3Vector *operator/=(float a2) {
            this->x = this->x / a2;
            this->y = this->y / a2;
            this->z = this->z / a2;
            return this;
        }

    public:
        float x;
        float y;
        float z;
    };
}

#endif //ENGINE_C3VECTOR_H
