#pragma once

#include "UI/CSimpleModel.h"

class CSimpleFrame;

class CSimpleModelFFX : public CSimpleModel {
public:
    // Static variables
    static int32_t s_metatable;

    // Static functions
    static CSimpleFrame *Create(CSimpleFrame *parent);

    static void CreateScriptMetaTable();

    static void RegisterScriptMethods(lua_State *L);

    static void Render(void *arg);

    // Virtual member functions
    virtual int32_t GetScriptMetaTable();

    virtual void OnFrameRender(CRenderBatch *batch, uint32_t layer);

    // Member functions
    CSimpleModelFFX(CSimpleFrame *parent);
};


