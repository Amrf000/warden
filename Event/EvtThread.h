#pragma once

#include "event/EvtContext.h"
#include <cstdint>
#include <storm/List.h>
#include <storm/Thread.h>

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


