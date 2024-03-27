// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.


#ifndef WARDEN_CGXTEXFLAGS_H
#define WARDEN_CGXTEXFLAGS_H

#include <cstdint>
#include "../const/EGxTexFilter.h"

class CGxTexFlags {
public:
    // Member variables
    uint32_t m_filter: 3;
    uint32_t m_wrapU: 1;
    uint32_t m_wrapV: 1;
    uint32_t m_forceMipTracking: 1;
    uint32_t m_generateMipMaps: 1;
    uint32_t m_renderTarget: 1;
    uint32_t m_maxAnisotropy: 5;
    uint32_t m_bit13: 1;
    uint32_t m_bit14: 1;
    uint32_t m_bit15: 1;

    // Member functions
    CGxTexFlags();


    CGxTexFlags(EGxTexFilter, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);

    bool operator==(const CGxTexFlags &texFlags);
};

#endif //WARDEN_CGXTEXFLAGS_H
