// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/28.
//

#ifndef WARDEN_CGXTEXPARMS_H
#define WARDEN_CGXTEXPARMS_H


#include <cstdint>
#include "../const/EGxTexTarget.h"
#include "../const/EGxTexFormat.h"
#include "CGxTexFlags.h"
#include "../const/EGxTexCommand.h"

class CGxTexParms {
public:
    // Member variables
    EGxTexTarget target;
    uint32_t width;
    uint32_t height;
    uint32_t depth;
    EGxTexFormat format;
    EGxTexFormat dataFormat;
    CGxTexFlags flags = CGxTexFlags(GxTex_Linear, 0, 0, 0, 0, 0, 1);
    void *userArg;

    void (*userFunc)(EGxTexCommand, uint32_t, uint32_t, uint32_t, uint32_t, void *, uint32_t &, const void *&);
};


#endif //WARDEN_CGXTEXPARMS_H
