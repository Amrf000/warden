#pragma once


#include "freetype/freetype.h"
#include "Types.h"

void FontFaceCloseHandle(HFACE);

FT_Face FontFaceGetFace(HFACE);

const char *FontFaceGetFontName(HFACE);

HFACE FontFaceGetHandle(const char *, FT_Library);


