#pragma once


class HASHKEY_STRI_P {
public:
    HASHKEY_STRI_P();

    bool operator==(const HASHKEY_STRI_P &key);

protected:
    void *m_key;
};


