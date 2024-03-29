


#include "HASHKEY_STRI_P.h"

HASHKEY_STRI_P::HASHKEY_STRI_P() {
    this->m_key = 0;
}

bool HASHKEY_STRI_P::operator==(const HASHKEY_STRI_P &key) {
    return this->m_key == key.m_key;
}
