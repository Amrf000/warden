#pragma once

#include <cstdint>
#include <storm/Queue.h>

class EvtTimer {
    public:
        // Member variables
        uint32_t id;
        TSTimerPriority<uint32_t> targetTime;
        float timeout;
        int32_t (*handler)(const void*, void*);
        void* param;
        int32_t (*guidHandler)(const void*, uint64_t, void*);
        uint64_t guidParam;
        void* guidParam2;
};

class EvtTimerQueue : public TSPriorityQueue<EvtTimer> {
    public:
        EvtTimerQueue()
            : TSPriorityQueue<EvtTimer>(offsetof(EvtTimer, targetTime))
            {};
};


