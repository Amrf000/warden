#pragma once

#include "CGxCaps.h"
#include "CGxFormat.h"
#include "Types.h"
#include <cstdint>

class CRect;

extern const char **g_gxShaderProfileNames[GxShTargets_Last];

const CGxCaps &GxCaps();

bool GxCapsWindowHasFocus(int32_t);

void GxCapsWindowSize(CRect &);

void GxFormatColor(CImVector &);


