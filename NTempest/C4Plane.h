// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.



#ifndef ENGINE_C4PLANE_H
#define ENGINE_C4PLANE_H

#include "C3Vector.h"

namespace NTempest {
    class C4Plane {
    public:
        C3Vector *From3Pos(const C3Vector *a2, const C3Vector *a3, const C3Vector *a4) {
            v4 = a2->z;
            v5 = a4->z - v4;
            v6 = a2->y;
            v7 = a4->y - v6;
            v8 = a4->x - a2->x;
            v9 = a3->z - v4;
            v10 = a3->y - v6;
            v11 = a3->x - a2->x;
            this->normal.z = (float) (v7 * v11) - (float) (v8 * v10);
            this->normal.y = (float) (v8 * v9) - (float) (v11 * v5);
            this->normal.x = (float) (v5 * v10) - (float) (v7 * v9);
            C3Vector *result = this->normal.Normalize();
            this->distance = -(float) ((float) ((float) (this->normal.x * a2->x) + (float) (this->normal.y * a2->y))
                                       + (float) (this->normal.z * a2->z));
            return result;
        }

        C4Plane(const C3Vector *a2, const C3Vector *a3, const C3Vector *a4) {
            this->normal.x = 0.0;
            this->normal.y = 0.0;
            this->normal.z = 0.0;
            this->From3Pos(a2, a3, a4);
        }

    private:
        C3Vector normal;
        float distance;
    };
}

#endif //ENGINE_C4PLANE_H
