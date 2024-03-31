#pragma once

#include <cstdint>

struct fixed16 {
    int16_t n;

    explicit operator float() const;
};

fixed16::operator float() const {
    return this->n / 32767.0f;
}