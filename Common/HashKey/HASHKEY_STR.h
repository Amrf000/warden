// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/24.
//

#ifndef WARDEN_HASHKEY_STR_H
#define WARDEN_HASHKEY_STR_H


#include "../../Storm/memory.h"

class HASHKEY_STR {
public:
    HASHKEY_STR();

    HASHKEY_STR(const char *key);

    HASHKEY_STR(const HASHKEY_STR &a2);

    HASHKEY_STR &operator=(const HASHKEY_STR &that);

    bool operator==(const char *str);

protected:
    char *m_key;
};


#endif //WARDEN_HASHKEY_STR_H
