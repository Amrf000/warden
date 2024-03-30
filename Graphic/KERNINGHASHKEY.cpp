#include "KERNINGHASHKEY.h"

KERNINGHASHKEY &KERNINGHASHKEY::operator=(const KERNINGHASHKEY &rhs) {
    if (this->code != rhs.code) {
        this->code = rhs.code;
    }

    return *this;
}

bool KERNINGHASHKEY::operator==(const KERNINGHASHKEY &rhs) {
    return this->code == rhs.code;
}
