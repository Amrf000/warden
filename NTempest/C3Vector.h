#pragma once

#include <cmath>
#include "CImVector.h"
#include "C44Matrix.h"
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


        C3Vector operator+(const C3Vector &l, const C3Vector &r) {
            float x = l.x + r.x;
            float y = l.y + r.y;
            float z = l.z + r.z;

            return {x, y, z};
        }

        C3Vector operator*(const C3Vector &l, const C44Matrix &r) {
            float x = r.c0 * l.z + r.b0 * l.y + r.a0 * l.x + r.d0;
            float y = r.c1 * l.z + r.b1 * l.y + r.a1 * l.x + r.d1;
            float z = r.c2 * l.z + r.b2 * l.y + r.a2 * l.x + r.d2;

            return {x, y, z};
        }

        bool operator!=(const C3Vector &l, const C3Vector &r) {
            return l.x != r.x || l.y != r.y || l.z != r.z;
        }

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

        C3Vector *ProjectionOnPlane(const C3Vector *a2, const C3Vector *a3) {
            v4 = a2->x;
            v5 = a3->x;
            v6 = a2->y;
            v7 = a3->y;
            v8 = a3->z;
            v9 = (float) ((float) (a2->x * a3->x) + (float) (v6 * v7)) + (float) (a2->z * v8);
            this->z = a2->z - (float) (v8 * v9);
            this->y = v6 - (float) (v7 * v9);
            this->x = v4 - (float) (v5 * v9);
            return this;
        }

        C3Vector *NearestOnPlane(const C3Vector *a2, const C3Vector *a3, const C3Vector *a4) {
            v4 = a2->y - a3->y;
            v5 = a2->x - a3->x;
            v10.z = a2->z - a3->z;
            v10.y = v4;
            v10.x = v5;
            ProjectionOnPlane(v9, &v10, a4);
            v9[2] = v9[0];
            v6 = a3->y + v9[0].y;
            v7 = a3->x + v9[0].x;
            this->z = a3->z + v9[0].z;
            this->y = v6;
            this->x = v7;
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
}


