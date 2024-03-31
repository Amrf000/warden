#pragma once

#include <cmath>
#include "CImVector.h"
#include "CMath.h"


namespace NTempest {
    class C3Vector {
    public:
        C3Vector() {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }

        C3Vector(float x, float y, float z)
                : x(x), y(y), z(z) {}

        C3Vector(const CImVector &color)
                : x(color.r / 255.0f), y(color.g / 255.0f), z(color.b / 255.0f) {}


        C3Vector &operator*=(float a) {
            this->x *= a;
            this->y *= a;
            this->z *= a;

            return *this;
        }


        float SquaredMag() const {
            return this->x * this->x + this->y * this->y + this->z * this->z;
        }


        float Mag() const {
            return CMath::sqrt(this->SquaredMag());
        }

        C3Vector *ProjectionOnPlane(const C3Vector &a2, const C3Vector &a3) {
            float v9 = (a2.x * a3.x) + (a2.y * a3.y) + (a2.z * a3.z);
            this->z = a2.z - (a3.z * v9);
            this->y = a2.y - (a3.y * v9);
            this->x = a2.x - (a3.x * v9);
            return this;
        }

        C3Vector *NearestOnPlane(const C3Vector &a2, const C3Vector &a3, const C3Vector &a4) {
            C3Vector v11(a2.x - a3.x, a2.y - a3.y, a2.z - a3.z);
            this->ProjectionOnPlane(v11, a4);
            this->z = a3.z + this->z;
            this->y = a3.y + this->y;
            this->x = a3.x + this->x;
            return this;
        }

        void Normalize() {
            this->operator*=(1.0f / this->Mag());
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

    class C44Matrix;

    C3Vector operator+(const C3Vector &l, const C3Vector &r);

    C3Vector operator*(const C3Vector &l, const C44Matrix &r);

    bool operator!=(const C3Vector &l, const C3Vector &r);
}


