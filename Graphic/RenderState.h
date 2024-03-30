#pragma once

#include "Types.h"
#include <cstdint>

class CGxShader;

class CGxTex;

void GxRsPop(void);

void GxRsPush(void);

void GxRsSet(EGxRenderState, int32_t);

void GxRsSet(EGxRenderState, CGxShader *);

void GxRsSet(EGxRenderState, CGxTex *);

void GxRsSetAlphaRef(void);


