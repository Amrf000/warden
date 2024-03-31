#pragma once

#include "C3Vector.h"

namespace NTempest {
    class C4Plane {
    public:
        C4Plane(const C3Vector &a2, const C3Vector &a3, const C3Vector &a4);

        void From3Pos(const C3Vector &a2, const C3Vector &a3, const C3Vector &a4);


    private:
        C3Vector normal;
        float distance;
    };
}


