// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.



#include "HASHKEY_STRI.h"
#include "../../Storm/SStr.h"

HASHKEY_STRI::HASHKEY_STRI() {
    this->m_key = 0;
}

HASHKEY_STRI::HASHKEY_STRI(const HASHKEY_STRI &that) {
    this->m_key = SStrDup(that.m_key);
}

HASHKEY_STRI::HASHKEY_STRI(const char *string) {
    this->m_key = SStrDup(string);
}

HASHKEY_STRI &HASHKEY_STRI::operator=(const char *str) {
    static_cast<HASHKEY_STR &>(*this) = str;
    return *this;
}

bool HASHKEY_STRI::operator==(const char *str) {
    return SStrCmpI(this->m_key, str, STORM_MAX_STR) == 0;
}