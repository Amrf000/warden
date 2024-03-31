#include "C3Vector.h"
#include "C44Matrix.h"

using namespace NTempest;

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