// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/28.
//

#ifndef WARDEN_BLITFORMAT_H
#define WARDEN_BLITFORMAT_H
enum BlitFormat {
    BlitFormat_Unknown = 0,
    BlitFormat_Abgr8888 = 1,
    BlitFormat_Argb8888 = 2,
    BlitFormat_Argb4444 = 3,
    BlitFormat_Argb1555 = 4,
    BlitFormat_Rgb565 = 5,
    BlitFormat_Dxt1 = 6,
    BlitFormat_Dxt3 = 7,
    BlitFormat_Dxt5 = 8,
    BlitFormat_Uv88 = 9,
    BlitFormat_Gr1616F = 10,
    BlitFormat_R32F = 11,
    BlitFormat_D24X8 = 12,
    BlitFormats_Last = 13
};

#endif //WARDEN_BLITFORMAT_H
