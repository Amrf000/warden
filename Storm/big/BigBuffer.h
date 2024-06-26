#pragma once


#include <cstdint>
#include "Common/TSGrowableArray.h"

class BigBuffer {
public:
    // Member variables
    TSGrowableArray <uint32_t> m_data;
    uint32_t m_offset = 0;

    // Member functions
    uint32_t &operator[](uint32_t index);

    uint32_t operator[](uint32_t index) const;

    void Clear();

    uint32_t Count() const;

    void GrowToFit(uint32_t index);

    int32_t IsUsed(uint32_t index) const;

    void SetCount(uint32_t count);

    void SetOffset(uint32_t offset);

    void Trim() const;
};


