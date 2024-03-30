#pragma once

#include "Types.h"
#include <cstdint>
#include <NTempest/C2iVector.h>

using namespace NTempest;

typedef void (*BLIT_FUNCTION)(const C2iVector &, const void *, uint32_t, void *, uint32_t);

void Blit(const C2iVector &, BlitAlpha, const void *, uint32_t, BlitFormat, void *, uint32_t, BlitFormat);

BlitFormat GxGetBlitFormat(EGxTexFormat);


