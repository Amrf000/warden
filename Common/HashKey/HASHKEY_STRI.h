#pragma once

#include "../../Storm/memory.h"
#include "HASHKEY_STR.h"

class HASHKEY_STRI : public HASHKEY_STR {
public:
    HASHKEY_STRI();

    HASHKEY_STRI(const HASHKEY_STRI &that);

    HASHKEY_STRI(const char *__src);

    HASHKEY_STRI &operator=(const char *str);

    bool operator==(const char *str);
};


