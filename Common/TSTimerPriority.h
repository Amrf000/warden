#pragma once

#include "CSBasePriority.h"

template<typename T>
class TSTimerPriority : public CSBasePriority {
public:
    // Member variables
    T m_val;

    // Member functions
    virtual bool Compare(CSBasePriority *a) {
        return this->m_val - static_cast<TSTimerPriority<T> *>(a)->m_val <= 0;
    }

};

