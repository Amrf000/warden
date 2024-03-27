// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

#ifndef WARDEN_CGXTEX_H
#define WARDEN_CGXTEX_H

#include "NTempest.h"
#include "../const/EGxTexTarget.h"
#include "../const/EGxTexFormat.h"
#include "CGxTexFlags.h"
#include "../const/EGxTexCommand.h"

using namespace NTempest;

class CGxTex {
public:
    // Member variables
    CiRect m_updateRect = {0, 0, 0, 0};
    int16_t m_updatePlaneMin = -1;
    int16_t m_updatePlaneMax = -1;
    uint32_t m_width;
    uint32_t m_height;
    uint32_t m_depth;
    EGxTexTarget m_target;
    EGxTexFormat m_format;
    EGxTexFormat m_dataFormat;
    CGxTexFlags m_flags = CGxTexFlags(GxTex_Linear, 0, 0, 0, 0, 0, 1);
    void *m_userArg;

    void (*m_userFunc)(EGxTexCommand, uint32_t, uint32_t, uint32_t, uint32_t, void *, uint32_t &, const void *&);

    void *m_apiSpecificData;
    void *m_apiSpecificData2; // invented name
    uint8_t m_needsUpdate;
    uint8_t m_needsCreation;
    uint8_t m_needsFlagUpdate;

    // Member functions
    CGxTex(EGxTexTarget, uint32_t, uint32_t, uint32_t, EGxTexFormat, EGxTexFormat, CGxTexFlags, void *,
           void (*)(EGxTexCommand, uint32_t, uint32_t, uint32_t, uint32_t, void *, uint32_t &, const void *&),
           const char *);

    float GetHeight(void);

    float GetWidth(void);
};


#endif //WARDEN_CGXTEX_H
