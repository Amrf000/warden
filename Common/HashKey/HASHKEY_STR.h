#pragma once


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


