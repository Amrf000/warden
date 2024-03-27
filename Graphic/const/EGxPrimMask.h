// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/28.
//

#ifndef WARDEN_EGXPRIMMASK_H
#define WARDEN_EGXPRIMMASK_H
enum EGxPrimMask {
    GxPrim_Position = 0x1,
    GxPrim_BlendWeight = 0x2,
    GxPrim_BlendIndices = 0x4,
    GxPrim_Normal = 0x8,
    GxPrim_Color0 = 0x10,
    GxPrim_Color1 = 0x20,
    GxPrim_TexCoord0 = 0x40,
    GxPrim_TexCoord1 = 0x80
};
#endif //WARDEN_EGXPRIMMASK_H
