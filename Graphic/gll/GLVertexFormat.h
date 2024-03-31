#pragma once


#include <cstdint>
#include "GLTypes.h"

class GLVertexFormat {
public:
    uint32_t m_Size;
    GLVertexAttrib m_Attribs[16];
};


