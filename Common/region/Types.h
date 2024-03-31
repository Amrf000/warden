#pragma once

#include <cstdint>
#include "Storm/Handle.h"


DECLARE_HANDLE(HSRGN);

DECLARE_HANDLE(HLOCKEDRGN);

struct RECTF {
    float left;
    float bottom;
    float right;
    float top;
};

