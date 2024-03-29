#pragma once


#include "CSBasePriorityQueue.h"

template<typename T>
class TSPriorityQueue : public CSBasePriorityQueue {
public:
    // Member functions
    TSPriorityQueue(uint32_t linkOffset) : CSBasePriorityQueue() {
        this->m_linkOffset = linkOffset;
    }

    T *Dequeue() {
        return static_cast<T *>(CSBasePriorityQueue::Dequeue());
    }
};



