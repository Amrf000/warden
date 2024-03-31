#pragma once

#include "C3Vector.h"

namespace NTempest {
    class CAaSphere {
    public:
        long double SquaredD(CAaSphere *that);

        bool Intersects(CAaSphere *that);

    public:
        C3Vector position;
        float radius;
    };
}



