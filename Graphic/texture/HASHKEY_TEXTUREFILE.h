// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit. 
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan. 
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna. 
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus. 
// Vestibulum commodo. Ut rhoncus gravida arcu. 



#ifndef WARDEN_HASHKEY_TEXTUREFILE_H
#define WARDEN_HASHKEY_TEXTUREFILE_H


#include "../../Storm/memory.h"
#include "../../Storm/SStr.h"
#include "cgx.h"

class HASHKEY_TEXTUREFILE {
public:
    HASHKEY_TEXTUREFILE(const char *key, CGxTexFlags texFlags) {
        this->m_filename = SStrDup(key);
        this->m_texFlags = texFlags;
    }

    HASHKEY_TEXTUREFILE *operator=(const HASHKEY_TEXTUREFILE &that) {
        if (this->m_filename)
            DeallocateMemory((void *) this->m_filename);
        this->m_filename = SStrDup(that.m_filename);
        this->m_texFlags = that.m_texFlags;
        return this;
    }

    bool operator==(const HASHKEY_TEXTUREFILE &that) {
        return (this->m_texFlags & 0x3F) == (that.m_texFlags & 0x3F) &&
               !SStrCmpI(this->m_filename, that.m_filename, 260);
    }

private:
    char *m_filename;
    CGxTexFlags m_texFlags;
};


#endif //WARDEN_HASHKEY_TEXTUREFILE_H
