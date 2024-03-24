// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/24.
//

#ifndef WARDEN_TSHASHOBJECTCHUNK_H
#define WARDEN_TSHASHOBJECTCHUNK_H

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

#endif //WARDEN_TSHASHOBJECTCHUNK_H
