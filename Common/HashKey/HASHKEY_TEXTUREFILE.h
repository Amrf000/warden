// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/24.
//

#ifndef WARDEN_HASHKEY_TEXTUREFILE_H
#define WARDEN_HASHKEY_TEXTUREFILE_H


#include "../../Storm/memory.h"
#include "../../Storm/SStr.h"
#include "../cgx/CGxTexFlags.h"

class HASHKEY_TEXTUREFILE {
public:
    HASHKEY_TEXTUREFILE(const char *key, CGxTexFlags texFlags) {
        this->m_key = SStrDup(key);
        this->m_tex_flags = texFlags;
    }

    HASHKEY_TEXTUREFILE *operator=(const HASHKEY_TEXTUREFILE &that) {
        if (this->m_key)
            DeallocateMemory((void *) this->m_key);
        this->m_key = SStrDup(that.m_key);
        this->m_tex_flags = that.m_tex_flags;
        return this;
    }

    bool operator==(const HASHKEY_TEXTUREFILE &that) {
        return (this->m_tex_flags & 0x3F) == (that.m_tex_flags & 0x3F) && !SStrCmpI(this->m_key, that.m_key, 260);
    }

private:
    char *m_key;
    CGxTexFlags m_tex_flags;
};


#endif //WARDEN_HASHKEY_TEXTUREFILE_H
