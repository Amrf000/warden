#pragma once

#include <cstdint>
#include "freetype/freetype.h"

void FreeTypeInitialize();

int32_t FREETYPE_RenderGlyph(uint32_t, bool, FT_Face);

FT_Library GetFreeTypeLibrary();


