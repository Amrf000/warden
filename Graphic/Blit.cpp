#include "Blit.h"
#include <algorithm>
#include <cstring>
#include "Storm/Unimplemented.h"
#include <NTempest/C2iVector.h>

using namespace NTempest;

int32_t initBlit = 0;
BLIT_FUNCTION s_blits[BlitFormats_Last][BlitFormats_Last][BlitAlphas_Last];

BlitFormat GxGetBlitFormat(EGxTexFormat format) {
    static BlitFormat blitTable[] = {
            BlitFormat_Unknown,     // GxTex_Unknown
            BlitFormat_Abgr8888,    // GxTex_Abgr8888
            BlitFormat_Argb8888,    // GxTex_Argb8888
            BlitFormat_Argb4444,    // GxTex_Argb4444
            BlitFormat_Argb1555,    // GxTex_Argb1555
            BlitFormat_Rgb565,      // GxTex_Rgb565
            BlitFormat_Dxt1,        // GxTex_Dxt1
            BlitFormat_Dxt3,        // GxTex_Dxt3
            BlitFormat_Dxt5,        // GxTex_Dxt5
            BlitFormat_Uv88,        // GxTex_Uv88
            BlitFormat_Gr1616F,     // GxTex_Gr1616F
            BlitFormat_R32F,        // GxTex_R32F
            BlitFormat_D24X8        // GxTex_D24X8
    };

    return blitTable[format];
}

void Blit_uint16_uint16(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    if (inStride == 2 * size.x && outStride == 2 * size.x) {
        memcpy(out, in, 2 * size.x * size.y);
        return;
    }

    const char *in_ = reinterpret_cast<const char *>(in);
    char *out_ = reinterpret_cast<char *>(out);

    for (int32_t i = 0; i < size.y; i++) {
        memcpy(out, in, 2 * size.x);
        in_ += inStride;
        out_ += outStride;
    }
}

void Blit_uint32_uint32(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    if (inStride == 4 * size.x && outStride == 4 * size.x) {
        memcpy(out, in, 4 * size.x * size.y);
        return;
    }

    const char *in_ = reinterpret_cast<const char *>(in);
    char *out_ = reinterpret_cast<char *>(out);

    for (int32_t i = 0; i < size.y; i++) {
        memcpy(out, in, 4 * size.x);
        in_ += inStride;
        out_ += outStride;
    }
}

void Blit_Argb8888_Abgr8888(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    WHOA_UNIMPLEMENTED();
}

void Blit_Argb8888_Argb8888(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    Blit_uint32_uint32(size, in, inStride, out, outStride);
}

void
Blit_Argb8888_Argb8888_A1(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    WHOA_UNIMPLEMENTED();
}

void
Blit_Argb8888_Argb8888_A8(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    WHOA_UNIMPLEMENTED();
}

void Blit_Argb8888_Argb4444(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    WHOA_UNIMPLEMENTED();
}

void Blit_Argb8888_Argb1555(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    WHOA_UNIMPLEMENTED();
}

void Blit_Argb8888_Rgb565(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    WHOA_UNIMPLEMENTED();
}

void Blit_Argb4444_Abgr8888(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    WHOA_UNIMPLEMENTED();
}

void Blit_Argb4444_Argb4444(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    Blit_uint16_uint16(size, in, inStride, out, outStride);
}

void Blit_Argb1555_Argb1555(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    WHOA_UNIMPLEMENTED();
}

void Blit_Rgb565_Rgb565(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    WHOA_UNIMPLEMENTED();
}

void Blit_Dxt1_Argb8888(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    WHOA_UNIMPLEMENTED();
}

void Blit_Dxt1_Argb1555(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    WHOA_UNIMPLEMENTED();
}

void Blit_Dxt1_Rgb565(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    WHOA_UNIMPLEMENTED();
}

void Blit_Dxt1_Dxt1(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    const char *in_ = static_cast<const char *>(in);
    char *out_ = static_cast<char *>(out);

    int32_t v6 = (std::max)(size.x, 4);
    int32_t v7 = (std::max)(size.y, 4);

    memcpy(out_, in_, (4 * v6 * v7) >> 3);
}

void Blit_Dxt3_Argb8888(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    WHOA_UNIMPLEMENTED();
}

void Blit_Dxt3_Argb4444(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    WHOA_UNIMPLEMENTED();
}

void Blit_Dxt35_Dxt35(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    int32_t v5 = (std::max)(size.x, 4);
    int32_t v6 = (std::max)(size.y / 4, 1);

    const char *in_ = static_cast<const char *>(in);
    char *out_ = static_cast<char *>(out);

    if (inStride == v5 * 4 && outStride == v5 * 4) {
        memcpy(out_, in_, v5 * v6 * 4);
        return;
    }

    for (int32_t i = v6; i > 0; i--) {
        memcpy(out_, in_, v5 * 4);
        in_ += inStride;
        out_ += outStride;
    }
}

void Blit_Dxt5_Argb8888(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    WHOA_UNIMPLEMENTED();
}

void Blit_Dxt5_Argb4444(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    WHOA_UNIMPLEMENTED();
}

void Blit_Uv88_Uv88(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    WHOA_UNIMPLEMENTED();
}

void Blit_Gr1616F_Gr1616F(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    WHOA_UNIMPLEMENTED();
}

void Blit_R32F_R32F(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    WHOA_UNIMPLEMENTED();
}

void Blit_D24X8_D24X8(const C2iVector &size, const void *in, uint32_t inStride, void *out, uint32_t outStride) {
    WHOA_UNIMPLEMENTED();
}

void InitBlit() {
    // Source: Argb8888
    s_blits[BlitFormat_Argb8888][BlitFormat_Abgr8888][BlitAlpha_0] = &Blit_Argb8888_Abgr8888;
    s_blits[BlitFormat_Argb8888][BlitFormat_Argb8888][BlitAlpha_0] = &Blit_Argb8888_Argb8888;
    s_blits[BlitFormat_Argb8888][BlitFormat_Argb8888][BlitAlpha_1] = &Blit_Argb8888_Argb8888_A1;
    s_blits[BlitFormat_Argb8888][BlitFormat_Argb8888][BlitAlpha_8] = &Blit_Argb8888_Argb8888_A8;
    s_blits[BlitFormat_Argb8888][BlitFormat_Argb4444][BlitAlpha_0] = &Blit_Argb8888_Argb4444;
    s_blits[BlitFormat_Argb8888][BlitFormat_Argb1555][BlitAlpha_0] = &Blit_Argb8888_Argb1555;
    s_blits[BlitFormat_Argb8888][BlitFormat_Rgb565][BlitAlpha_0] = &Blit_Argb8888_Rgb565;

    // Source: Argb4444
    s_blits[BlitFormat_Argb4444][BlitFormat_Abgr8888][BlitAlpha_0] = &Blit_Argb4444_Abgr8888;
    s_blits[BlitFormat_Argb4444][BlitFormat_Argb4444][BlitAlpha_0] = &Blit_Argb4444_Argb4444;

    // Source: Argb1555
    s_blits[BlitFormat_Argb1555][BlitFormat_Argb1555][BlitAlpha_0] = &Blit_Argb1555_Argb1555;

    // Source: Rgb565
    s_blits[BlitFormat_Rgb565][BlitFormat_Rgb565][BlitAlpha_0] = &Blit_Rgb565_Rgb565;

    // Source: Dxt1
    s_blits[BlitFormat_Dxt1][BlitFormat_Argb8888][BlitAlpha_0] = &Blit_Dxt1_Argb8888;
    s_blits[BlitFormat_Dxt1][BlitFormat_Argb1555][BlitAlpha_0] = &Blit_Dxt1_Argb1555;
    s_blits[BlitFormat_Dxt1][BlitFormat_Rgb565][BlitAlpha_0] = &Blit_Dxt1_Rgb565;
    s_blits[BlitFormat_Dxt1][BlitFormat_Dxt1][BlitAlpha_0] = &Blit_Dxt1_Dxt1;

    // Source: Dxt3
    s_blits[BlitFormat_Dxt3][BlitFormat_Argb8888][BlitAlpha_0] = &Blit_Dxt3_Argb8888;
    s_blits[BlitFormat_Dxt3][BlitFormat_Argb4444][BlitAlpha_0] = &Blit_Dxt3_Argb4444;
    s_blits[BlitFormat_Dxt3][BlitFormat_Dxt3][BlitAlpha_0] = &Blit_Dxt35_Dxt35;

    // Source: Dxt5
    s_blits[BlitFormat_Dxt5][BlitFormat_Argb8888][BlitAlpha_0] = &Blit_Dxt5_Argb8888;
    s_blits[BlitFormat_Dxt5][BlitFormat_Argb4444][BlitAlpha_0] = &Blit_Dxt5_Argb4444;
    s_blits[BlitFormat_Dxt5][BlitFormat_Dxt5][BlitAlpha_0] = &Blit_Dxt35_Dxt35;

    // Source: Uv88
    s_blits[BlitFormat_Uv88][BlitFormat_Uv88][BlitAlpha_0] = &Blit_Uv88_Uv88;

    // Source: Gr1616F
    s_blits[BlitFormat_Gr1616F][BlitFormat_Gr1616F][BlitAlpha_0] = &Blit_Gr1616F_Gr1616F;

    // Source: R32F
    s_blits[BlitFormat_R32F][BlitFormat_R32F][BlitAlpha_0] = &Blit_R32F_R32F;

    // Source: D24X8
    s_blits[BlitFormat_D24X8][BlitFormat_D24X8][BlitAlpha_0] = &Blit_D24X8_D24X8;
}

void Blit(const C2iVector &size, BlitAlpha alpha, const void *src, uint32_t srcStride, BlitFormat srcFmt, void *dst,
          uint32_t dstStride, BlitFormat dstFmt) {
    if (!initBlit) {
        InitBlit();
        initBlit = 1;
    }

    BLIT_FUNCTION blit = s_blits[srcFmt][dstFmt][alpha];

    blit(size, src, srcStride, dst, dstStride);
}
