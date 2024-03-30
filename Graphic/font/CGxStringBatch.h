#pragma once

#include "gx/font/CGxString.h"
#include <cstdint>
#include <storm/Hash.h>
#include <storm/List.h>

class CGxBuf;
class CGxFont;
class CGxPool;

class BATCHEDRENDERFONTDESC : public TSHashObject<BATCHEDRENDERFONTDESC, HASHKEY_PTR> {
    public:
        // Static variables
        static bool s_billboarded;
        static CGxBuf* s_indexBuf;
        static CGxPool* s_indexPool;

        // Static functions
        static void Initialize(void);
        static void InitializeIndexBuff(void);
        CGxVertexPCT* UnlockVertexPtrAndRender(CGxBuf*&, int32_t);

        // Member variables
        CGxFont* m_face = nullptr;
        STORM_EXPLICIT_LIST(CGxString, m_batchedStringLink) m_strings;

        // Member functions
        void RenderBatch(void);
};

class CGxStringBatch : public TSLinkedNode<CGxStringBatch> {
    public:
        // Member variables
        TSHashTable<BATCHEDRENDERFONTDESC, HASHKEY_PTR> m_fontBatch;
        uint32_t m_flags = 0x0;

        // Member functions
        ~CGxStringBatch();
        void AddString(CGxString*);
        void RenderBatch(void);
};


