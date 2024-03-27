// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/28.
//

#ifndef WARDEN_EGXTEXFILTER_H
#define WARDEN_EGXTEXFILTER_H
enum EGxTexFilter {
    GxTex_Nearest = 0x0,
    GxTex_Linear = 0x1,
    GxTex_NearestMipNearest = 0x2,
    GxTex_LinearMipNearest = 0x3,
    GxTex_LinearMipLinear = 0x4,
    GxTex_Anisotropic = 0x5,
    GxTexFilters_Last = 0x6,
};
#endif //WARDEN_EGXTEXFILTER_H
