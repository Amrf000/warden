#pragma once


#include <cstdint>
#include "CGxStateBom.h"

class CGxAppRenderState {
public:
    CGxStateBom m_value;
    uint32_t m_stackDepth;
    int32_t m_dirty;
};


