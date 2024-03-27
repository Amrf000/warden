// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

#pragma once

#include "agile.h"
#include "common.h"
#include "HASHKEY_TEXTUREFILE.h"


class CTexture : public CHandleObject, public TSHashObject<CTexture, HASHKEY_TEXTUREFILE> {
public:
    // Static variables
    static EGxTexFilter s_filterMode;
    static int32_t s_maxAnisotropy;
    // Member variables
    uint32_t unk1;
    uint16_t flags = 0;
    uint8_t bestMip = 0;
    uint8_t alphaBits = 0;
    CStatus loadStatus;
    CAsyncObject *asyncObject = nullptr;
    CGxTex *gxTex = nullptr;
    EGxTexTarget gxTexTarget = GxTex_2d;
    uint16_t gxWidth = 0;
    uint16_t gxHeight = 0;
    EGxTexFormat gxTexFormat = GxTex_Unknown;
    EGxTexFormat dataFormat = GxTex_Unknown;
    CGxTexFlags gxTexFlags = CGxTexFlags(GxTex_Linear, 0, 0, 0, 0, 0, 1);
    void *atlas = nullptr; // TODO CTextureAtlas
    int32_t atlasBlockIndex = 0;
    uint32_t unk2[2];
    char filename[260];


    virtual void Release() {

    }

    virtual int HeapRelease() {
        ::HeapRelease(this);
    }

    virtual void SafeHeapRelease() {
        if (this)
            this->HeapRelease();
    }

    virtual int ObjectId() = 0;

    virtual void Width() = 0;

    virtual void Height() = 0;
};

