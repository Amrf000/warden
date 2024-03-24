// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/24.
//

#ifndef WARDEN_TSHASHOBJECT_H
#define WARDEN_TSHASHOBJECT_H

#include "../TSLink.h"

#include <type_traits>


template<typename DataType, typename KeyType>
class TSHashObject {
public:
    TSHashObject() {
        this->m_linktoslot.m_prevlink = 0;
        this->m_linktoslot.m_next = 0;
        this->m_linktofull.m_prevlink = 0;
        this->m_linktofull.m_next = 0;
        this->m_key = 0;
    }

    ~TSHashObject() {
        if (this->m_linktofull.m_prevlink) {
            *this->m_linktofull.NextLink(-1) = this->m_linktofull.m_prevlink;
            this->m_linktofull.m_prevlink->m_next = this->m_linktofull.m_next;
            this->m_linktofull.m_prevlink = 0;
            this->m_linktofull.m_next = 0;
        }
        if (this->m_linktoslot.m_prevlink) {
            *this->m_linktoslot.NextLink(-1) = this->m_linktoslot.m_prevlink;
            this->m_linktoslot.m_prevlink->m_next = this->m_linktoslot.m_next;
            this->m_linktoslot.m_prevlink = 0;
            this->m_linktoslot.m_next = 0;
        }
    }

private:
    uint32_t m_hashval;
    TSLink<DataType> m_linktoslot;
    TSLink<DataType> m_linktofull;
    KeyType m_key;
};

template<typename T, typename N>
concept HashObject = std::is_base_of<TSHashObject<T, N>, T>::value;
#endif //WARDEN_TSHASHOBJECT_H
