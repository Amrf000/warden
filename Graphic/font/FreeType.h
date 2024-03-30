#pragma once

#include "freetype/freetype.h"
#include <cstdint>

void FreeTypeInitialize();

int32_t FREETYPE_RenderGlyph(uint32_t, bool, FT_Face);

FT_Library GetFreeTypeLibrary();


