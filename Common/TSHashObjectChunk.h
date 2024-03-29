#pragma once

#include "TSCD.h"
#include "TSGrowableArray.h"
#include "TSLink.h"

template<typename T, typename N>
class TSHashObjectChunk {
public:
    TSHashObjectChunk() {
        this->m_link.m_prevlink = 0;
        this->m_link.m_next = 0;
    }

    ~TSHashObjectChunk() {
        if (this->m_link.m_prevlink) {
            *this->m_link.NextLink(-1) = this->m_link.m_prevlink;
            this->m_link.m_prevlink->m_next = this->m_link.m_next;
            this->m_link.m_prevlink = 0;
            this->m_link.m_next = 0;
        }
    }

protected:
    TSGrowableArray<T, TSCD<T>> m_array;
    TSLink<T> m_link;
};

