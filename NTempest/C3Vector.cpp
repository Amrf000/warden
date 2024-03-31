#include "C3Vector.h"
#include "C44Matrix.h"
#include "CImVector.h"
#include "CMathi.h"
#include <cmath>

using namespace NTempest;

C3Vector::C3Vector() {
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

C3Vector::C3Vector(float x, float y, float z)
        : x(x), y(y), z(z) {}

C3Vector::C3Vector(const CImVector &color)
        : x(color.r / 255.0f), y(color.g / 255.0f), z(color.b / 255.0f) {}


C3Vector &C3Vector::operator*=(float a) {
    this->x *= a;
    this->y *= a;
    this->z *= a;

    return *this;
}


float C3Vector::SquaredMag() const {
    return this->x * this->x + this->y * this->y + this->z * this->z;
}


float C3Vector::Mag() const {
    return CMathi::sqrt(this->SquaredMag());
}

C3Vector *C3Vector::ProjectionOnPlane(const C3Vector &a2, const C3Vector &a3) {
    float v9 = (a2.x * a3.x) + (a2.y * a3.y) + (a2.z * a3.z);
    this->z = a2.z - (a3.z * v9);
    this->y = a2.y - (a3.y * v9);
    this->x = a2.x - (a3.x * v9);
    return this;
}

C3Vector *C3Vector::NearestOnPlane(const C3Vector &a2, const C3Vector &a3, const C3Vector &a4) {
    C3Vector v11(a2.x - a3.x, a2.y - a3.y, a2.z - a3.z);
    this->ProjectionOnPlane(v11, a4);
    this->z = a3.z + this->z;
    this->y = a3.y + this->y;
    this->x = a3.x + this->x;
    return this;
}

void C3Vector::Normalize() {
    this->operator*=(1.0f / this->Mag());
}

bool C3Vector::IsUnit() {
    return fabs(
            (float) ((float) ((float) (this->x * this->x) + (float) (this->y * this->y)) +
                     (float) (this->z * this->z))
            - 1.0) < 0.001;
}

C3Vector *C3Vector::operator/=(float a2) {
    this->x = this->x / a2;
    this->y = this->y / a2;
    this->z = this->z / a2;
    return this;
}

C3Vector NTempest::operator+(const C3Vector &l, const C3Vector &r) {
    float x = l.x + r.x;
    float y = l.y + r.y;
    float z = l.z + r.z;

    return C3Vector(x, y, z);
}

C3Vector NTempest::operator*(const C3Vector &l, const C44Matrix &r) {
    float x = r.c0 * l.z + r.b0 * l.y + r.a0 * l.x + r.d0;
    float y = r.c1 * l.z + r.b1 * l.y + r.a1 * l.x + r.d1;
    float z = r.c2 * l.z + r.b2 * l.y + r.a2 * l.x + r.d2;

    return C3Vector(x, y, z);
}

bool NTempest::operator!=(const C3Vector &l, const C3Vector &r) {
    return l.x != r.x || l.y != r.y || l.z != r.z;
}