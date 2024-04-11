#pragma once

#include "Graphic/Types.h"
#include "ui/Types.h"
#include <cstdint>

const char *LanguageProcess(const char *string);

int32_t StringToBlendMode(const char *string, EGxBlend &blend);

int32_t StringToFramePoint(const char *string, FRAMEPOINT &point);

int32_t StringToFrameStrata(const char *string, FRAME_STRATA &strata);


