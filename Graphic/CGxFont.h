//
// Created by liuyawu on 2024/3/30.
//

#pragma once

#include "common.h"
#include <cstdint>

class CGxFont : public TSLinkedNode<CGxFont> {
public:
    // Member variables
    STORM_EXPLICIT_LIST(CGxString, m_fontStringLink) m_strings;
    TSHashTable<CHARCODEDESC, HASHKEY_NONE> m_activeCharacters;
    TSHashTable<KERNNODE, KERNINGHASHKEY> m_kernInfo;
    STORM_EXPLICIT_LIST(CHARCODEDESC, fontGlyphLink) m_activeCharacterCache;
    HFACE m_faceHandle;
    char m_fontName[260];
    uint32_t m_cellHeight = 0;
    uint32_t m_baseline;
    uint32_t m_flags;
    float m_requestedFontHeight;
    float m_pixelsPerUnit = 0.0f;
    TEXTURECACHE m_textureCache[8];
    uint32_t m_pixelSize;

    // Member functions
    ~CGxFont();
    int32_t CheckStringGlyphs(const char*);
    void Clear(void);
    void ClearGlyphs(void);
    float ComputeStep(uint32_t, uint32_t);
    float ComputeStepFixedWidth(uint32_t, uint32_t);
    float GetGlyphBearing(const CHARCODEDESC*, bool, float);
    int32_t GetGlyphData(GLYPHBITMAPDATA*, uint32_t);
    const char* GetName(void) const;
    uint32_t GetPixelSize(void);
    int32_t Initialize(const char*, uint32_t, float);
    const CHARCODEDESC* NewCodeDesc(uint32_t);
    void RegisterEvictNotice(uint32_t);
    int32_t UpdateDimensions(void);
};
