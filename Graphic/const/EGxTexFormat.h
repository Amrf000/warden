#pragma once


enum EGxTexFormat {
    GxTex_Unknown = 0x0,
    GxTex_Abgr8888 = 0x1,
    GxTex_Argb8888 = 0x2,
    GxTex_Argb4444 = 0x3,
    GxTex_Argb1555 = 0x4,
    GxTex_Rgb565 = 0x5,
    GxTex_Dxt1 = 0x6,
    GxTex_Dxt3 = 0x7,
    GxTex_Dxt5 = 0x8,
    GxTex_Uv88 = 0x9,
    GxTex_Gr1616F = 0xA,
    GxTex_R32F = 0xB,
    GxTex_D24X8 = 0xC,
    GxTexFormats_Last = 0xD,
};

