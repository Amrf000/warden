// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.



#include "HASHKEY_STR.h"
#include "../../Storm/SStr.h"

HASHKEY_STR::HASHKEY_STR() {
    this->m_key = 0;
}

HASHKEY_STR::HASHKEY_STR(const char *string) {
    this->m_key = SStrDup(string);
}

HASHKEY_STR::HASHKEY_STR(const HASHKEY_STR &a2) {
    this->m_key = SStrDup(a2.m_key);
}

HASHKEY_STR &HASHKEY_STR::operator=(const HASHKEY_STR &that) {
    if (this != &that) {
        if (this->m_key)
            DeallocateMemory(this->m_key);
        this->m_key = SStrDup(that.m_key);
    }
    return *this;
}

bool HASHKEY_STR::operator==(const char *str) {
    return SStrCmp(this->m_key, str, STORM_MAX_STR) == 0;
}