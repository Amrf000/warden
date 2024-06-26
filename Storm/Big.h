#pragma once


#include <cstdint>
#include "Storm/big/BigData.h"

void SBigAdd(BigData *a, BigData *b, BigData *c);

void SBigBitLen(BigData *num, uint32_t *len);

int32_t SBigCompare(BigData *a, BigData *b);

void SBigDel(BigData *num);

void SBigFromBinary(BigData *num, const void *data, uint32_t bytes);

void SBigFromUnsigned(BigData *num, uint32_t val);

void SBigMod(BigData *a, BigData *b, BigData *c);

void SBigMul(BigData *a, BigData *b, BigData *c);

void SBigNew(BigData **num);

void SBigPowMod(BigData *a, BigData *b, BigData *c, BigData *d);

void SBigShl(BigData *a, BigData *b, uint32_t shift);

void SBigShr(BigData *a, BigData *b, uint32_t shift);

void SBigSquare(BigData *a, BigData *b);

void SBigSub(BigData *a, BigData *b, BigData *c);

void SBigToBinaryBuffer(BigData *num, uint8_t *data, uint32_t maxBytes, uint32_t *bytes);


