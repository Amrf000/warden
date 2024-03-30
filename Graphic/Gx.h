#pragma once


#include <cstdint>
#include <NTempest/CRect.h>
#include <NTempest/CImVector.h>
#include "CGxCaps.h"
#include "CGxFormat.h"
#include "Types.h"

using namespace NTempest;
extern const char **g_gxShaderProfileNames[GxShTargets_Last];

const CGxCaps &GxCaps();

bool GxCapsWindowHasFocus(int32_t);

void GxCapsWindowSize(CRect &);

void GxFormatColor(CImVector &);


