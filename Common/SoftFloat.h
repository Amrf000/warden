// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.


#ifndef WARDEN_SOFTFLOAT_H
#define WARDEN_SOFTFLOAT_H


unsigned int *SoftFloatFromInt(unsigned int *a1, unsigned int *a2);

unsigned int *softFloatSubtract(unsigned int *a1, unsigned int *a2, unsigned int *a3);

unsigned int *softFloatSqrt(unsigned int *a1, unsigned int *a2);

unsigned int *softFloatReciprocal(unsigned int *a1, unsigned int *a2);

unsigned int *softFloatMultiply(unsigned int *a1, unsigned int *a2, unsigned int *a3);

unsigned int *softFloatInverseSqrt(unsigned int *a1, unsigned int *a2);

unsigned int *softFloatDiv(unsigned int *a1, unsigned int *a2, unsigned int *a3);

unsigned int *softFloatAdd(unsigned int *ret, float *value1, float *value2);


#endif //WARDEN_SOFTFLOAT_H
