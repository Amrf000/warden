// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/24.
//

#include "HASHKEY_STRI_P.h"

HASHKEY_STRI_P::HASHKEY_STRI_P() {
    this->m_key = 0;
}

bool HASHKEY_STRI_P::operator==(const HASHKEY_STRI_P &key) {
    return this->m_key == key.m_key;
}
