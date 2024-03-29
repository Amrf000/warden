// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

#pragma once

#include "common.h"
#include "EvtContextQueue.h"

class EvtThread : public TSLinkedNode<EvtThread> {
public:
    // Member variables
    uint32_t m_threadSlot;
    uint32_t m_threadCount;
    uint32_t m_weightTotal;
    uint32_t m_weightAvg;
    uint32_t m_contextCount;
    uint32_t m_rebalance;
    SEvent m_wakeEvent = SEvent(0, 0);
    EvtContextQueue m_contextQueue;

    // Member functions
    EvtThread();
};
