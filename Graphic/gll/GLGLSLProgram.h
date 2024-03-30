#pragma once

#include "gx/gll/GLObject.h"

class GLShader;

class GLGLSLProgram : public GLObject {
    public:
        // Static functions
        static GLGLSLProgram* Find(GLShader*, GLShader*);
};


