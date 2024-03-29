// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

#pragma once

#include <cstdint>
#include "common.h"


class EvtTimer {
public:
    // Member variables
    uint32_t id;
    TSTimerPriority <uint32_t> targetTime;
    float timeout;

    int32_t (*handler)(const void *, void *);

    void *param;

    int32_t (*guidHandler)(const void *, uint64_t, void *);

    uint64_t guidParam;
    void *guidParam2;
};
