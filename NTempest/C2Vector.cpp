#include "C2Vector.h"
#include <cmath>

using namespace NTempest;

C2Vector::C2Vector() {
    x = 0.0f;
    y = 0.0f;
}

C2Vector::C2Vector(float x, float y) : x(x), y(y) {}

bool C2Vector::operator==(const C2Vector &v) {
    return this->x == v.x && this->y == v.y;
}


long double C2Vector::Mag() {
    return sqrtf((float) (this->x * this->x) + (float) (this->y * this->y));
}

void C2Vector::FromAxisAngle(float value) {
    x = sinf(value);
    y = cosf(value);
}

float C2Vector::AxisAngle() {
    return AxisAngle_(Mag());
}

float C2Vector::AxisAngle_(float a2) {
    long double result;
    if (fabs(a2) < 0.00000023841858)
        return 0.0;
    result = acosf(this->x / a2);
    if (this->y < 0.0) {
        return (float) (6.2831855 - result);
    }
    return result;
}