#pragma once


#include <cstdint>
#include "BigBuffer.h"
#include "BigStack.h"
#include "Common/TSGrowableArray.h"

void Add(BigBuffer &a, const BigBuffer &b, uint32_t c);

void Add(BigBuffer &a, const BigBuffer &b, const BigBuffer &c);

int32_t Compare(const BigBuffer &a, const BigBuffer &b);

void Div(BigBuffer &a, uint32_t *b, const BigBuffer &c, uint64_t d);

void Div(BigBuffer &a, BigBuffer &b, const BigBuffer &c, const BigBuffer &d, BigStack &stack);

uint32_t ExtractLowPart(uint64_t &value);

uint32_t ExtractLowPartLargeSum(uint64_t &value, uint64_t add);

uint32_t ExtractLowPartSx(uint64_t &value);

void FromBinary(BigBuffer &buffer, const void *value, uint32_t bytes);

void FromUnsigned(BigBuffer &buffer, uint32_t value);

uint32_t HighBitPos(const BigBuffer &buffer);

void InsertLowPart(uint64_t &value, uint32_t low);

uint64_t MakeLarge(uint32_t low, uint32_t high);

void Mul(BigBuffer &a, const BigBuffer &b, uint64_t c);

void Mul(BigBuffer &a, const BigBuffer &b, const BigBuffer &c, BigStack &stack);

void MulMod(BigBuffer &a, const BigBuffer &b, const BigBuffer &c, const BigBuffer &d, BigStack &stack);

void PowMod(BigBuffer &a, const BigBuffer &b, const BigBuffer &c, const BigBuffer &d, BigStack &stack);

void SetOne(BigBuffer &buffer);

void SetZero(BigBuffer &buffer);

void Shl(BigBuffer &a, const BigBuffer &b, uint32_t shift);

void Shr(BigBuffer &a, const BigBuffer &b, uint32_t shift);

void Square(BigBuffer &a, const BigBuffer &b, BigStack &stack);

void Sub(BigBuffer &a, const BigBuffer &b, const BigBuffer &c);

void ToBinary(TSGrowableArray<uint8_t> &output, const BigBuffer &buffer);


