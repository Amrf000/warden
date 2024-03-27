// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.


#ifndef WARDEN_CGXPUSHEDRENDERSTATE_H
#define WARDEN_CGXPUSHEDRENDERSTATE_H


#include <cstdint>
#include "CGxStateBom.h"
#include "const/EGxRenderState.h"

class CGxPushedRenderState {
public:
    EGxRenderState m_which;
    CGxStateBom m_value;
    uint32_t m_stackDepth;
};


#endif //WARDEN_CGXPUSHEDRENDERSTATE_H
