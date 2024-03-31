#pragma once


namespace NTempest {
    class C2Vector {
    public:
        C2Vector();

        C2Vector(float x, float y);

        bool operator==(const C2Vector &v);


        long double Mag();

        void FromAxisAngle(float value);

        float AxisAngle();

        float AxisAngle_(float a2);

    public:
        float x;
        float y;
    };
}


