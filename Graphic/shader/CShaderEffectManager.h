#pragma once

#include <storm/Hash.h>

class CShaderEffect;

class CShaderEffectManager {
    public:
        // Static variables
        static TSHashTable<CShaderEffect, HASHKEY_STRI> s_shaderList;

        // Static functions
        static CShaderEffect* CreateEffect(const char* effectKey);
        static CShaderEffect* GetEffect(const char* effectKey);
};


