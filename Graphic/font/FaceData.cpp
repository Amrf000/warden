#include "FaceData.h"
#include "Storm/SFile.h"

FACEDATA::~FACEDATA() {
    if (this->face) {
        FT_Done_Face(this->face);
    }

    if (this->data) {
        SFile::Unload(this->data);
    }
}
