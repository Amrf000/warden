#include "GLYPHBITMAPDATA.h"
#include "Storm.h"


GLYPHBITMAPDATA::~GLYPHBITMAPDATA() {
    if (this->m_data) {
        SMemFree(this->m_data, __FILE__, __LINE__, 0x0);
    }

    this->m_data = nullptr;
}

void GLYPHBITMAPDATA::CopyFrom(GLYPHBITMAPDATA *data) {
    if (this->m_data) {
        SMemFree(this->m_data, __FILE__, __LINE__, 0);
    }

    this->m_data = nullptr;
    *this = *data;
    data->m_data = nullptr;
}
