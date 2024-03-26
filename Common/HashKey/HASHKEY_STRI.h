// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.



#ifndef WARDEN_HASHKEY_STRI_H
#define WARDEN_HASHKEY_STRI_H

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


#endif //WARDEN_HASHKEY_STRI_H
