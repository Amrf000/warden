#include "TEXTLINETEXTURE.h"

TEXTLINETEXTURE *TEXTLINETEXTURE::NewTextLineTexture() {
    // TODO
    // Allocate off of TEXTLINETEXTURE::s_freeTextLineTextures

    auto m = SMemAlloc(sizeof(TEXTLINETEXTURE), __FILE__, __LINE__, 0x0);
    return new(m) TEXTLINETEXTURE();
}

void TEXTLINETEXTURE::Recycle(TEXTLINETEXTURE *ptr) {
    // TODO if (TEXTLINETEXTURE::s_recycledBytes <= 0x80000)

    if (ptr) {
        delete ptr;
    }
}

void TEXTLINETEXTURE::WriteGeometry(CGxVertexPCT *buf, const CImVector &fontColor, const C2Vector &shadowOffset,
                                    const CImVector &shadowColor, const C3Vector &viewTranslation, bool a7, bool a8,
                                    int32_t ofs, int32_t size) {
    if (!size || !this->m_vert.Count()) {
        return;
    }

    uint32_t colorCount = this->m_vert.Count() == this->m_colors.Count()
                          ? this->m_colors.Count()
                          : 0;

    if (ofs >= this->m_vert.Count()) {
        return;
    }

    uint32_t v24 = this->m_vert.Count() - ofs;

    if (size >= v24) {
        size = v24;
    }

    if (a7) {
        C3Vector shadowTranslation = {
                viewTranslation.x + floor(ScreenToPixelWidth(0, shadowOffset.x)),
                viewTranslation.y + floor(ScreenToPixelHeight(0, shadowOffset.y)),
                viewTranslation.z
        };

        auto color = colorCount ? this->m_colors[ofs] : fontColor;

        for (int32_t i = 0; i < size; i++) {
            auto &vert = this->m_vert[i + ofs];

            C3Vector p = {
                    vert.vc.x + shadowTranslation.x,
                    vert.vc.y + shadowTranslation.y,
                    vert.vc.z + shadowTranslation.z
            };

            buf->p = p;
            buf->tc[0] = vert.tc;

            auto formattedShadowColor = shadowColor;
            if (a8 && colorCount) {
                formattedShadowColor.a = static_cast<uint8_t>(
                        (static_cast<float>(formattedShadowColor.a) * static_cast<float>(color.a)) / 65536.0f
                );
            }
            GxFormatColor(formattedShadowColor);
            buf->c = formattedShadowColor;

            buf++;
        }
    }

    // if (BATCHEDRENDERFONTDESC::s_billboarded) {
    //     // TODO
    // }

    for (int32_t i = 0; i < size; i++) {
        auto &vert = this->m_vert[i + ofs];

        auto color = colorCount ? this->m_colors[i + ofs] : fontColor;
        GxFormatColor(color);

        // if (BATCHEDRENDERFONTDESC::s_billboarded) {
        //     // TODO
        //     continue;
        // }

        C3Vector p = {
                vert.vc.x + viewTranslation.x,
                vert.vc.y + viewTranslation.y,
                vert.vc.z + viewTranslation.z
        };

        buf->p = p;
        buf->tc[0] = vert.tc;

        buf->c = color;

        buf++;
    }
}