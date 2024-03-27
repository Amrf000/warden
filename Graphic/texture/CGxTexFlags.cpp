// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

#include "CGxTexFlags.h"

CGxTexFlags::CGxTexFlags() : CGxTexFlags(GxTex_Linear, 0, 0, 0, 0, 0, 1) {};

CGxTexFlags::CGxTexFlags(EGxTexFilter, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t) {

}

bool CGxTexFlags::operator==(const CGxTexFlags &texFlags) {
    return false;
}



