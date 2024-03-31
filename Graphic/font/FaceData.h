#pragma once


#include "Common/Hashkey.h"
#include "Common/TSHashObject.h"
#include "Agile/CHandleObject.h"
#include "Types.h"
#include "freetype/freetype.h"

class FACEDATA : public CHandleObject, public TSHashObject<FACEDATA, HASHKEY_STRI> {
public:
    void *data = nullptr;
    FT_Face face = nullptr;
    HFACE selfReference;

    virtual ~FACEDATA();
};


