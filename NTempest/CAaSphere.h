// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2019/5/9.
//

#ifndef ENGINE_CAASPHERE_H
#define ENGINE_CAASPHERE_H


#include "C3Vector.h"

namespace NTempest {
    class CAaSphere {
    public:
        long double SquaredD(CAaSphere *that) {
            return (float) ((float) ((float) ((float) (that->a1 - this->a1) * (float) (that->a1 - this->a1))
                                     + (float) ((float) (that->a2 - this->a2) * (float) (that->a2 - this->a2)))
                            + (float) ((float) (that->a3 - this->a3) * (float) (that->a3 - this->a3)));
        }

        bool Intersects(CAaSphere *that) {
            float v3;

            v3 = this->SquaredD(that);
            return (float) ((float) (this->a4 + that->a4) * (float) (this->a4 + that->a4)) >= v3;
        }

    public:
        C3Vector position;
        float radius;
    };
}


#endif //ENGINE_CAASPHERE_H
