// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/28.
//

#ifndef WARDEN_PIXEL_FORMAT_H
#define WARDEN_PIXEL_FORMAT_H
enum PIXEL_FORMAT {
    PIXEL_DXT1 = 0x0,
    PIXEL_DXT3 = 0x1,
    PIXEL_ARGB8888 = 0x2,
    PIXEL_ARGB1555 = 0x3,
    PIXEL_ARGB4444 = 0x4,
    PIXEL_RGB565 = 0x5,
    PIXEL_A8 = 0x6,
    PIXEL_DXT5 = 0x7,
    PIXEL_UNSPECIFIED = 0x8,
    PIXEL_ARGB2565 = 0x9,
    NUM_PIXEL_FORMATS = 0xA
};
#endif //WARDEN_PIXEL_FORMAT_H
