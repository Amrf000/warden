#include "CHARCODEDESC.h"

uint32_t CHARCODEDESC::GapToNextTexture() {
    CHARCODEDESC *next = this->textureRowLink.Next();

    return next
           ? next->glyphStartPixel - this->glyphEndPixel - 1
           : 255 - this->glyphEndPixel;
}

uint32_t CHARCODEDESC::GapToPreviousTexture() {
    CHARCODEDESC *previous = this->textureRowLink.Prev();

    return previous
           ? this->glyphStartPixel - previous->glyphEndPixel - 1
           : this->glyphStartPixel;
}

void CHARCODEDESC::GenerateTextureCoords(uint32_t rowNumber, uint32_t glyphSide) {
    this->bitmapData.m_textureCoords.minY = (glyphSide * rowNumber) / 256.0f;
    this->bitmapData.m_textureCoords.minX = this->glyphStartPixel / 256.0f;
    this->bitmapData.m_textureCoords.maxY = ((glyphSide * rowNumber) + glyphSide) / 256.0f;
    this->bitmapData.m_textureCoords.maxX = (this->glyphStartPixel + this->bitmapData.m_glyphCellWidth) / 256.0f;
}
