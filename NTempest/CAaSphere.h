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
        long double SquaredD(NTempest::CAaSphere *that) {
            return (float) ((float) ((float) ((float) (that->position.x - this->position.x)
                                              * (float) (that->position.x - this->position.x))
                                     + (float) ((float) (that->position.y - this->position.y)
                                                * (float) (that->position.y - this->position.y)))
                            + (float) ((float) (that->position.z - this->position.z) *
                                       (float) (that->position.z - this->position.z)));
        }

        bool Intersects(NTempest::CAaSphere *that) {
            float v3 = SquaredD(that);
            return (float) ((float) (this->radius + that->radius) * (float) (this->radius + that->radius)) >= v3;
        }

    public:
        C3Vector position;
        float radius;
    };
}


#endif //ENGINE_CAASPHERE_H
