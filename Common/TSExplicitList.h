// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.


#ifndef WARDEN_TSEXPLICITLIST_H
#define WARDEN_TSEXPLICITLIST_H

#include "TSGetExplicitLink.h"
#include "TSList.h"

template<typename T, int N>
class TSExplicitList : public TSList<T, TSGetExplicitLink<T>> {
public:
    TSExplicitList() {
        this->m_linkoffset = N;
        this->m_terminator.m_prevlink = &this->m_terminator;
        this->m_terminator.m_next = (T *) ((uintptr_t) &this->m_terminator | 1);
    }

    TSExplicitList(const TSExplicitList &that) : TSList<T, TSGetExplicitLink<T>>(that) {
    }
};

#endif //WARDEN_TSEXPLICITLIST_H
