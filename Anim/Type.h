#pragma once

#include <cstdint>

struct fixed16 {
    int16_t n;

    explicit operator float() const;
};

