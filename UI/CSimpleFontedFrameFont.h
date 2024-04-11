#pragma once

#include "ui/CSimpleFont.h"

class CSimpleFontedFrame;

class CSimpleFontedFrameFont : public CSimpleFont {
public:
    // Member variables
    CSimpleFontedFrame *m_frame;

    // Member functions
    CSimpleFontedFrameFont(CSimpleFontedFrame *frame)
            : m_frame(frame) {};
};

