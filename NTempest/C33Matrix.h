#pragma once

#include "C3Vector.h"

namespace NTempest {
    class C33Matrix;

    class C3Vector;

    C33Matrix operator*(const C33Matrix &l, float a);

    C33Matrix operator/(const C33Matrix &l, float a);

    C33Matrix operator*(const C33Matrix &l, const C33Matrix &r);

    C3Vector operator*(const C33Matrix &l, const C3Vector &r);

    class C33Matrix {
    public:
        // Member functions
        C33Matrix() {
            a0 = 1.0f;
            a1 = 0.0f;
            a2 = 0.0f;
            b0 = 0.0f;
            b1 = 1.0f;
            b2 = 0.0f;
            c0 = 0.0f;
            c1 = 0.0f;
            c2 = 1.0f;
        }

        C33Matrix(float a0, float a1, float a2, float b0, float b1, float b2, float c0, float c1, float c2)
                : a0(a0), a1(a1), a2(a2), b0(b0), b1(b1), b2(b2), c0(c0), c1(c1), c2(c2) {};

        C33Matrix Adjoint() const {
            float a0 = (this->c2 * this->b1) - (this->b2 * this->c1);
            float a1 = -(this->a1 * this->c2 - this->a2 * this->c1);
            float a2 = this->b2 * this->a1 - this->a2 * this->b1;

            float b0 = -(this->b0 * this->c2 - this->b2 * this->c0);
            float b1 = this->c2 * this->a0 - this->a2 * this->c0;
            float b2 = -(this->b2 * this->a0 - this->a2 * this->b0);

            float c0 = this->c1 * this->b0 - this->c0 * this->b1;
            float c1 = -(this->c1 * this->a0 - this->a1 * this->c0);
            float c2 = this->a0 * this->b1 - this->a1 * this->b0;

            return {a0, a1, a2, b0, b1, b2, c0, c1, c2};
        }

        float Determinant() const {
            return this->a0 * this->b1 * this->c2 + this->a1 * this->b2 * this->c0 + this->a2 * this->b0 * this->c1 -
                   this->a0 * this->b2 * this->c1 - this->a1 * this->b0 * this->c2 - this->a2 * this->b1 * this->c0;
        }

        C33Matrix Inverse(float det) const {
            return this->Adjoint() / det;
        }


    public:
        float a0;
        float a1;
        float a2;
        float b0;
        float b1;
        float b2;
        float c0;
        float c1;
        float c2;
    };

    C33Matrix operator*(const C33Matrix &l, const C33Matrix &r) {
        float a0 = l.a0 * r.a0 + l.a1 * r.b0 + l.a2 * r.c0;
        float a1 = l.a0 * r.a1 + l.a1 * r.b1 + l.a2 * r.c1;
        float a2 = l.a0 * r.a2 + l.a1 * r.b2 + l.a2 * r.c2;

        float b0 = l.b0 * r.a0 + l.b1 * r.b0 + l.b2 * r.c0;
        float b1 = l.b0 * r.a1 + l.b1 * r.b1 + l.b2 * r.c1;
        float b2 = l.b0 * r.a2 + l.b1 * r.b2 + l.b2 * r.c2;

        float c0 = l.c0 * r.a0 + l.c1 * r.b2 + l.c2 * r.c0;
        float c1 = l.c0 * r.a1 + l.c1 * r.c0 + l.c2 * r.c1;
        float c2 = l.c0 * r.a2 + l.c1 * r.c1 + l.c2 * r.c2;

        return {a0, a1, a2, b0, b1, b2, c0, c1, c2};
    }

    C33Matrix operator/(const C33Matrix &l, float a) {
        float div = (1.0f / a);
        return l * div;
    }

    C33Matrix operator*(const C33Matrix &l, float a) {
        float a0 = l.a0 * a;
        float a1 = l.a1 * a;
        float a2 = l.a2 * a;

        float b0 = l.b0 * a;
        float b1 = l.b1 * a;
        float b2 = l.b2 * a;

        float c0 = l.c0 * a;
        float c1 = l.c1 * a;
        float c2 = l.c2 * a;

        return {a0, a1, a2, b0, b1, b2, c0, c1, c2};
    }

    C3Vector operator*(const C33Matrix &l, const C3Vector &r) {
        float x = l.a0 * r.x + l.a1 * r.y + l.a2 * r.z;
        float y = l.b0 * r.x + l.b1 * r.y + l.b2 * r.z;
        float z = l.c0 * r.x + l.c1 * r.y + l.c2 * r.z;
        return {x, y, z};
    }
}


