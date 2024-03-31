#pragma once

#include <cmath>
#include "Storm/Error.h"


namespace NTempest {
    class CMath {
    public:
        static constexpr float PI = 3.1415927f;
        static constexpr float TWO_PI = 6.2831855f;
        static constexpr float OO_TWO_PI = 1.0f / TWO_PI;

        static int32_t fint(float n) {
            return static_cast<int32_t>(n);
        }

        static int32_t fint_n(float n) {
            return n <= 0.0f ? static_cast<int32_t>(n - 0.5f) : static_cast<int32_t>(n + 0.5f);
        }

        static uint32_t fuint(float n) {
            return static_cast<uint32_t>(n);
        }

        static uint32_t fuint_n(float n) {
            return static_cast<uint32_t>(n + 0.5f);
        }

        static uint32_t fuint_pi(float n) {
            return static_cast<uint32_t>(n + 0.99994999);
        }

        static float sqrt(float x) {
            STORM_ASSERT(x >= 0.0f);
            return ::sqrt(x);
        }

        static int32_t fint_mi(float input) {
            if (input <= 0.0f) {
                float result = (std::max)(0.99998999f - input, 0.0f);
                result = result - 1.5f;
                int32_t intResult = static_cast<int32_t>(result);
                intResult += (result >= 0.0f) ? 0x80000000 : 0;
                intResult |= (result >= 2.0f) ? 0x80000000 : 0;
                return -intResult;
            } else {
                float result = (std::max)(input, 0.0f);
                result = result - 1.5f;
                int32_t intResult = static_cast<int32_t>(result);
                intResult += (result >= 0.0f) ? 0x80000000 : 0;
                intResult |= (result >= 2.0f) ? 0x80000000 : 0;
                return intResult;
            }
        }

        static void sincos_(float value, float &a2, float &a3) {
            a2 = sinf(value);
            a3 = cosf(value);
        }

        static void sincos_(double value, double &x_8, double &x_12) {
            x_8 = sin(value);
            x_12 = cos(value);
        }
    };
}



