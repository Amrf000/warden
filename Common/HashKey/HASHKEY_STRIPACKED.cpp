// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.



#include "HASHKEY_STRIPACKED.h"


HASHKEY_STRIPACKED::HASHKEY_STRIPACKED() {}

HASHKEY_STRIPACKED::HASHKEY_STRIPACKED(const char *key) {
    int newLen;
    int destsize;
    char *dest;
    int v5;
    const char *v6;
    char source[256];
    char v8[256];
    const char *v9[7];

    this->m_key = 0;
    if (key && *key) {
        v8[0] = 0;
        newLen = SStrLen(key);
        v9[0] = key;
        v6 = &key[newLen];
        if (key < &key[newLen]) {
            destsize = 256;
            dest = v8;
            SStrTokenize(v9, source, 0x100u, " ", 0);
            while (source[0]) {
                v5 = SStrCopy(dest, source, destsize);
                dest += v5;
                destsize -= v5;
                if (v9[0] >= v6)
                    break;
                SStrTokenize(v9, source, 0x100u, " ", 0);
            }
        }
        this->m_key = SStrDup(v8);
    } else {
        this->m_key = 0;
    }
}