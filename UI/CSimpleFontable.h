#pragma once

#include "UI/Types.h"
#include "Common/TSLink.h"


class CSimpleFont;

class CSimpleFontStringAttributes;

class CSimpleFontable {
public:
    // Member variables
    CSimpleFont *m_fontObject = nullptr;
    uint32_t m_fontableFlags = FLAG_COMPLETE_UPDATE;
    TSLink <CSimpleFontable> m_fontableLink;

    // Virtual member functions
    virtual ~CSimpleFontable();

    virtual void FontObjectUpdated(CSimpleFontStringAttributes &attributes) = 0;

    // Member functions
    CSimpleFont *GetFontObject();

    void SetFontObject(CSimpleFont *fontObject);
};


