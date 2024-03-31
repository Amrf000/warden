#pragma once


namespace NTempest {
    class C3Vector;

    class CAaSphere {
    public:
        long double SquaredD(CAaSphere *that);

        bool Intersects(CAaSphere *that);

    public:
        C3Vector position;
        float radius;
    };
}



