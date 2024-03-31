#pragma once


namespace NTempest {
    class CImVector;

    class C44Matrix;

    class C3Vector {
    public:
        C3Vector();

        C3Vector(float x, float y, float z);

        C3Vector(const CImVector &color);


        C3Vector &operator*=(float a);


        float SquaredMag() const;


        float Mag() const;

        C3Vector *ProjectionOnPlane(const C3Vector &a2, const C3Vector &a3);

        C3Vector *NearestOnPlane(const C3Vector &a2, const C3Vector &a3, const C3Vector &a4);

        void Normalize();

        bool IsUnit();

        C3Vector *operator/=(float a2);

    public:
        float x;
        float y;
        float z;
    };


    C3Vector operator+(const C3Vector &l, const C3Vector &r);

    C3Vector operator*(const C3Vector &l, const C44Matrix &r);

    bool operator!=(const C3Vector &l, const C3Vector &r);
}


