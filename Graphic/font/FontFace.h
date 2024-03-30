#pragma once

#include "gx/font/FreeType.h"
#include "gx/font/Types.h"

void FontFaceCloseHandle(HFACE);

FT_Face FontFaceGetFace(HFACE);

const char* FontFaceGetFontName(HFACE);

HFACE FontFaceGetHandle(const char*, FT_Library);


