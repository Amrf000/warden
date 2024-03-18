// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/17.
//

#ifndef WARDEN_TSLINKEDNODE_H
#define WARDEN_TSLINKEDNODE_H

#include "TSLink.h"

template<typename T>
class TSLinkedNode {
public:
    TSLinkedNode() {
        m_link.m_prevlink = 0;
        m_link.m_next = 0;
    }

    virtual  ~TSLinkedNode() {
        if (this->m_link.m_prevlink) {
            *this->NextLink(-1) = this->m_link.m_prevlink;
            this->m_link.m_prevlink->m_next = this->m_link.m_next;
            this->m_link.m_prevlink = 0;
            this->m_link.m_next = 0;
        }
        if (this->m_link.m_prevlink) {
            *this->NextLink(-1) = this->m_link.m_prevlink;
            this->m_link.m_prevlink->m_next = this->m_link.m_next;
            this->m_link.m_prevlink = 0;
            this->m_link.m_next = 0;
        }
    }

private:
    TSLink<T> m_link;
};

#endif //WARDEN_TSLINKEDNODE_H
