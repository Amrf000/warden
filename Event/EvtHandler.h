#pragma once

#include <cstdint>
#include "Common/TSLink.h"


class EvtHandler {
public:
    // Member variables
    TSLink<EvtHandler> link;

    int32_t (*func)(const void *, void *);

    void *param;
    float priority;
    int32_t marker;
};


