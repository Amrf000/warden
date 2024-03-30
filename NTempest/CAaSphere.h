


#pragma once


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



