#pragma once

#include "gx/gll/GLTypes.h"
#include <cstdint>

class GLVertexFormat {
    public:
        uint32_t m_Size;
        GLVertexAttrib m_Attribs[16];
};


