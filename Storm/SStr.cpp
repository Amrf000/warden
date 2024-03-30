// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/24.
//
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include "SStr.h"
#include "memory.h"
#include "DebugUtils.h"


uint8_t bytesFromUTF8[256] = {
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6
};
uint32_t offsetsFromUTF8[8] = {
        0,
        0,
        0x3080,
        0x0E2080,
        0x3C82080,
        0x0FA082080,
        0x82082080,
        0
};

int32_t s_initialized;
double s_realDigit[20][10];
void GetNextTextUpper(uint32_t* orig, const char** string, uint32_t* upper) {
    uint8_t byte = **string;
    int32_t v3 = bytesFromUTF8[byte];

    *orig = 0;
    *upper = 0;

    switch (v3) {
        case 6:
        case 5:
        case 4:
        case 3:
        case 2:
            *orig += **string;
            (*string)++;

            if (!**string) {
                return;
            }

            *orig <<= 6;

        case 1:
            *orig += **string;
            (*string)++;

        default:
            *orig -= offsetsFromUTF8[v3];

            if (*orig > 0xFFFF) {
                *orig = 0xFFFF;
            }

            uint32_t v4 = *orig;

            bool v5, v6;

            if (v3 == 1) {
                if (v4 < 0x61) {
                    *upper = v4;
                    return;
                }

                v5 = v4 < 0x7A;
                v6 = v4 == 122;

                if (!v5 && !v6) {
                    *upper = v4;
                    return;
                }

                v4 -= 32;
                *upper = v4;
                return;
            }

            if (v3 != 2) {
                *upper = v4;
                return;
            }

            if (v4 >= 0xE0 && v4 <= 0xFE) {
                v4 -= 32;
                *upper = v4;
                return;
            }

            if (v4 == 339) {
                *upper = 338;
                return;
            }

            if (v4 == 1105) {
                *upper = 1025;
                return;
            }

            if (v4 >= 0x430) {
                v5 = v4 < 0x44F;
                v6 = v4 == 1103;

                if (!v5 && !v6) {
                    *upper = v4;
                    return;
                }

                v4 -= 32;
                *upper = v4;
                return;
            }

            *upper = v4;
            return;
    }
}

void InitializeFloatDigits() {
    for (int32_t i = -1; i > -21; i--) {
        for (int32_t j = 0; j < 10; j++) {
            double v3 = 10.0;
            int32_t v4 = i < 0 ? -i : i;
            double v5 = 1.0;

            while (true) {
                if (v4 & 1) {
                    v5 *= v3;
                }

                v4 >>= 1;

                if (!v4) {
                    break;
                }

                v3 *= v3;
            }

            double v6 = i < 0 ? 1.0 / v5 : v5;

            double v7 = v6 * static_cast<double>(j);

            s_realDigit[-i - 1][j] = v7;
        }
    }
}

size_t ISStrVPrintf(const char* format, va_list va, char* dest, size_t maxchars) {
    if (!maxchars) {
        return 0;
    }

    size_t result;

    if (maxchars == STORM_MAX_STR) {
        // TODO conditional vsoprintf;
        result = vsprintf(dest, format, va);
    } else {
        // TODO conditional vsnoprintf;
        result = vsnprintf(dest, maxchars, format, va);

        if (result >= maxchars) {
            result = maxchars - 1;
            dest[result] = '\0';
        }
    }

    return result;
}

void SStrInitialize() {
    if (!s_initialized) {
        InitializeFloatDigits();
        s_initialized = 1;
    }
}

char *SStrChr(char *string, char search)
{
    char *result;

    result = (char *)string;
    if ( string )
    {
        while ( *result )
        {
            if ( search == *result )
                return result;
            ++result;
        }
    }
    else
    {
        DebugPrint("string");
        sub_1CA2E(87);
    }
    return 0;
}

const char *SStrChr(const char *string, char search) {
    STORM_ASSERT(string);
    STORM_VALIDATE(string, ERROR_INVALID_PARAMETER, nullptr);

    if (!*string) {
        return nullptr;
    }

    while (*string != search) {
        string++;

        if (!*string) {
            return nullptr;
        }
    }

    return string;
}
unsigned int SStrHashHT(const char *str) {
    char transformedStr[1024] = {0}; // 存储转换后的字符串
    unsigned int hashValue = -1640531527; // 初始哈希值
    unsigned int secondaryHashValue = -1640531527; // 次要哈希值

    // 转换字符串并计算长度
    int len = 0;
    for (; str[len] && len < 1023; ++len) {
        char currentChar = str[len];
        if ((unsigned int) currentChar - 97 <= 0x19) {
            transformedStr[len] = currentChar - 32;
        } else {
            transformedStr[len] = (currentChar != 47) ? currentChar : 92;
        }
    }

    // 对转换后的字符串进行哈希计算
    for (int i = 0; i < len; i += 12) {
        unsigned int chunkHashValue = 0;
        unsigned int chunkSecondaryHashValue = 0;

        // 计算每个12字符片段的哈希值
        for (int j = 0; j < 12 && i + j < len; ++j) {
            chunkHashValue += transformedStr[i + j];
            chunkSecondaryHashValue += transformedStr[i + j];
        }

        // 更新主要哈希值
        hashValue += chunkHashValue;
        hashValue ^= (chunkHashValue << 8);
        hashValue ^= (chunkHashValue >> 13);

        // 更新次要哈希值
        secondaryHashValue += chunkSecondaryHashValue;
        secondaryHashValue ^= (chunkSecondaryHashValue << 8);
        secondaryHashValue ^= (chunkSecondaryHashValue >> 13);
    }

    // 结合主要和次要哈希值
    hashValue ^= (secondaryHashValue >> 15);
    hashValue ^= (secondaryHashValue - (hashValue << 10));
    hashValue ^= (hashValue >> 12);

    return hashValue;
}

int dword_F30C50;

int sub_1CA2E(int a1) {
    int result;

    result = a1;
    dword_F30C50 = a1;
    return result;
}

char *SStrDup(const char *string) {
    void *dup;
    int v2;

    if (string) {
        v2 = SStrLen(string) + 1;
        dup = SMemAlloc(
                v2,
                "/Volumes/F1/usrbuild/xb/build/War3x_B6401/War3/Source/Mac/../../../StormMac/Storm Mac/SOURCE/SSTR.CPP",
                689,
                0);
        if (v2 > 0)
            memmove(dup, string, v2);
    } else {
        DebugPrint("string");
        sub_1CA2E(87);
        return 0;
    }
    return (char *) dup;
}

int sStrCmpI(const char *string1, const char *string2, int maxchars) {
    int i; // edi
    char v4; // si
    char v5; // al

    for (i = 0; i < maxchars; ++i) {
        v4 = _tolower(string1[i]);
        v5 = _tolower(string2[i]);
        if (v4 < v5)
            return -1;
        if (v4 > v5)
            return 1;
        if (!v4)
            break;
    }
    return 0;
}

int SStrCmp(const char *string1, const char *string2, size_t maxchars) {
    return strncmp(string1, string2, maxchars);
}

int SStrCmpI(const char *string1, const char *string2, int maxchars) {
    int v3;

    if (string1) {
        v3 = 1;
    } else {
        DebugPrint("string1");
        v3 = 0;
    }
    if (string2) {
        if (v3)
            return sStrCmpI(string1, string2, maxchars);
    } else {
        DebugPrint("string2");
    }
    sub_1CA2E(87);
    return string1 - string2;
}

size_t SStrLen(const char *string) {
    int i;
    int stringEnd;
    int v4;

    if (string) {
        for (i = (uintptr_t) string;; ++i) {
            stringEnd = i;
            if ((i & 3) == 0)
                break;
            if (!*(char *) i)
                return stringEnd - (uintptr_t) string;
        }
        do {
            do {
                v4 = *(uintptr_t *) i;
                i += 4;
            } while (((v4 ^ (v4 + 2130640639)) & 0x81010100) == -2130640640);
            if (!(char) v4) {
                stringEnd = i - 4;
                return stringEnd - (uintptr_t) string;
            }
            if (!BYTE1(v4)) {
                stringEnd = i - 3;
                return stringEnd - (uintptr_t) string;
            }
            if (!BYTE2(v4)) {
                stringEnd = i - 2;
                return stringEnd - (uintptr_t) string;
            }
        } while (HIBYTE(v4));
        stringEnd = i - 1;
        return stringEnd - (uintptr_t) string;
    } else {
        DebugPrint("string");
        sub_1CA2E(87);
        return 0;
    }
}

size_t SStrCopy(char *dest, const char *source, size_t destsize)
{
    char *v3; // esi
    int v4; // eax
    char *v6; // eax
    int v7; // edx
    char *v8; // eax
    char *i; // ecx
    int v10; // edx
    int v11; // eax
    char *v12; // edi
    int j; // ecx
    char v14; // al
    int v15; // edi
    int v16; // edx
    char *v17; // ecx
    const char *v18; // eax
    char *v19; // ecx
    int v20; // eax
    char *v21; // edi
    int k; // ecx
    char v23; // al
    char *v24; // [esp+14h] [ebp-24h]
    char *v25; // [esp+18h] [ebp-20h]
    char *v26; // [esp+1Ch] [ebp-1Ch]

    v3 = (char *)source;
    if ( dest )
    {
        v4 = 1;
    }
    else
    {
        DebugPrint("dest");
        v4 = 0;
    }
    if ( !source )
    {
        DebugPrint("source");
        LABEL_7:
        sub_1CA2E(87);
        return 0;
    }
    if ( !v4 )
        goto LABEL_7;
    if ( !destsize )
        return 0;
    v24 = &dest[destsize];
    v25 = &dest[destsize - 1];
    if ( destsize != 0x7FFFFFFF )
        *(v24 - 1) = 0;
    for ( i = dest; ; ++i )
    {
        v6 = i;
        if ( ((unsigned __int8)i & 3) == 0 )
            break;
        if ( !*i )
            goto LABEL_29;
    }
    do
    {
        do
        {
            v10 = *(_DWORD *)i;
            i += 4;
        }
        while ( ((v10 ^ (v10 + 2130640639)) & 0x81010100) == -2130640640 );
        if ( !(_BYTE)v10 )
        {
            v6 = i - 4;
            goto LABEL_29;
        }
        if ( !BYTE1(v10) )
        {
            v6 = i - 3;
            goto LABEL_29;
        }
        if ( !BYTE2(v10) )
        {
            v6 = i - 2;
            goto LABEL_29;
        }
    }
    while ( HIBYTE(v10) );
    v6 = i - 1;
    LABEL_29:
    v11 = v6 - v25;
    v12 = &v25[v11];
    for ( j = v11; ((unsigned __int8)v3 & 3) != 0 && j; ++j )
    {
        v7 = (int)v12;
        v14 = *v3;
        *v12++ = *v3++;
        if ( !v14 )
            return v7 - (_DWORD)dest;
    }
    v15 = j + 3;
    if ( j + 3 >= 0 )
    {
        LABEL_47:
        v20 = v15 - 3;
        v21 = &v25[v15 - 3];
        for ( k = v20; k; ++k )
        {
            v7 = (int)v21;
            v23 = *v3;
            *v21++ = *v3++;
            if ( !v23 )
                return v7 - (_DWORD)dest;
        }
        *v25 = 0;
        v7 = (int)v25;
    }
    else
    {
        v26 = v24 - 4;
        v16 = *(_DWORD *)v3;
        v3 += 4;
        v17 = &v24[v15 - 4];
        while ( ((v16 ^ (v16 + 2130640639)) & 0x81010100) == -2130640640 )
        {
            *(_DWORD *)v17 = v16;
            v17 += 4;
            v15 += 4;
            if ( v15 >= 0 )
            {
                LABEL_46:
                v25 = v26 + 3;
                goto LABEL_47;
            }
            v16 = *(_DWORD *)v3;
            v3 += 4;
        }
        v18 = v3;
        v19 = &v26[v15];
        while ( 1 )
        {
            v3 = (char *)v18;
            if ( !(_BYTE)v16 )
            {
                v7 = (int)&v26[v15];
                v26[v15] = 0;
                return v7 - (_DWORD)dest;
            }
            if ( !BYTE1(v16) )
            {
                *(_WORD *)&v26[v15] = (unsigned __int8)v16;
                v7 = (int)&v26[v15 + 1];
                return v7 - (_DWORD)dest;
            }
            if ( !BYTE2(v16) )
            {
                v8 = &v26[v15];
                *(_WORD *)v8 = v16;
                v8[2] = 0;
                v7 = (int)&v26[v15 + 2];
                return v7 - (_DWORD)dest;
            }
            *(_DWORD *)v19 = v16;
            if ( !HIBYTE(v16) )
                break;
            v18 += 4;
            v19 += 4;
            v15 += 4;
            if ( v15 >= 0 )
                goto LABEL_46;
            v16 = *(_DWORD *)v3;
        }
        v7 = (int)&v26[v15 + 3];
    }
    return v7 - (_DWORD)dest;
}

void SStrTokenize(
        const char **string,
        char *buffer,
        unsigned int bufferchars,
        const char *whitespace,
        int *quoted)
{
    int v5;
    const char *i;
    char v7;
    bool v8;
    bool v9;
    int v10;
    unsigned int v11;

    if ( string )
    {
        v5 = 1;
    }
    else
    {
        DebugPrint("string");
        v5 = 0;
    }
    if ( !*string )
    {
        DebugPrint("*string");
        v5 = 0;
    }
    if ( !buffer && bufferchars )
    {
        DebugPrint("buffer || !bufferchars");
        v5 = 0;
    }
    if ( !whitespace )
    {
        DebugPrint("whitespace");
        LABEL_12:
        sub_1CA2E(87);
        return;
    }
    if ( !v5 )
        goto LABEL_12;
    v8 = SStrChr(whitespace, 34) != 0;
    for ( i = *string; ; ++i )
    {
        v7 = *i;
        if ( !*i )
            break;
        if ( !SStrChr(whitespace, *i) )
        {
            v7 = *i;
            break;
        }
        if ( v8 && *i == 34 )
        {
            ++i;
            v9 = 1;
            v10 = 1;
            v7 = *i;
            goto LABEL_24;
        }
    }
    v9 = 0;
    v10 = 0;
    LABEL_24:
    v11 = 0;
    while ( v7 )
    {
        if ( v8 && v7 == 34 )
        {
            if ( v11 && !v9 )
                break;
            v9 = !v9;
            ++i;
            if ( !v9 )
            {
                v10 = 1;
                break;
            }
            v10 = 1;
        }
        else
        {
            if ( !v9 && SStrChr(whitespace, v7) )
            {
                ++i;
                break;
            }
            if ( bufferchars > v11 + 1 )
                buffer[v11++] = v7;
            ++i;
        }
        v7 = *i;
    }
    if ( bufferchars > v11 )
        buffer[v11] = 0;
    *string = i;
    if ( quoted )
        *quoted = v10;
}


int32_t SStrToInt(const char* string) {
    STORM_ASSERT(string);

    int32_t result = 0;
    bool negative = false;

    if (*string == '-') {
        negative = true;
        string++;
    }

    uint32_t digit;
    while ((digit = *string - '0') < 10) {
        result = digit + (10 * result);
        string++;
    }

    if (negative) {
        result = -result;
    }

    return result;
}

float SStrToFloat(const char* string) {
    STORM_ASSERT(string);

    SStrInitialize();

    double result;
    bool negative = false;

    if (*string == '-') {
        negative = true;
        string++;
    }

    double v16 = 10.0;
    double v4 = 0.0;
    uint32_t v5 = *string - '0';
    const char* v6 = string;

    if (v5 >= 10) {
        v5 = 0;
        result = static_cast<double>(v5);
    } else {
        string++;

        uint32_t v8 = *string - '0';

        if (v8 >= 10) {
            result = static_cast<double>(v5);
        } else {
            do {
                v5 = v8 + 10 * v5;
                string++;

                if (v5 >= 0x19999999) {
                    v4 = v4 * pow(10.0, string - v6) + static_cast<double>(v5);
                    v5 = 0;
                    v6 = string;
                }

                v8 = *string - '0';
            } while (v8 < 10);

            if (v4 == 0.0) {
                result = static_cast<double>(v5);
            } else {
                result = pow(10.0, string - v6) * v4 + static_cast<double>(v5);
            }
        }
    }

    if (*string == '.') {
        string++;

        uint32_t v23 = *string - '0';
        int32_t v24 = 0;

        if (v23 < 10) {
            int32_t v25 = 0;
            int32_t v26 = -1;
            double v31;

            do {
                string++;

                if (v24 < 20) {
                    v31 = s_realDigit[0][v25 + v23];
                } else {
                    v31 = pow(v16, v26) * v23;
                }

                result += v31;

                v23 = *string - '0';
                v24++;
                v26--;
                v25 += 10;
            } while (v23 < 10);
        }
    }

    if (*string == 'e' || *string == 'E') {
        const char* v32 = string + 1;

        if (*v32 == '+') {
            v32++;
        }

        result *= pow(10.0, SStrToInt(v32));
    }

    if (negative) {
        result = -result;
    }

    return static_cast<float>(result);
}

size_t SStrPrintf(char* dest, size_t maxchars, const char* format, ...) {
    va_list va;
    va_start(va, format);

    STORM_ASSERT(dest);
    STORM_ASSERT(format);

    return ISStrVPrintf(format, va, dest, maxchars);
}

uint32_t SStrPack(char* dest, const char* source, uint32_t destsize) {
    STORM_ASSERT(dest);
    STORM_ASSERT(source);

    if (!destsize) {
        return 0;
    }

    char* i;
    const char* v5;
    char v6;
    const char* j;

    for (i = dest; *i; i++)
        ;

    if (destsize == STORM_MAX_STR) {
        v6 = *source;

        for (j = source; *j; i++) {
            j++;
            *i = v6;
            v6 = *j;
        }
    } else {
        v5 = source;

        if (*source) {
            while (i < &dest[destsize - 1]) {
                *i++ = *v5++;

                if (!*v5) {
                    *i = '\0';
                    return static_cast<uint32_t>(i - dest);
                }
            }
        }
    }

    *i = '\0';
    return static_cast<uint32_t>(i - dest);
}

void SStrLower(char* string) {
    while (*string) {
        *string = static_cast<char>(tolower(*string));
        string++;
    }
}


const char* SStrChrR(const char* string, char search) {
    STORM_ASSERT(string);
    STORM_VALIDATE(string, ERROR_INVALID_PARAMETER, nullptr);

    const char* result;

    for (result = nullptr; *string; string++) {
        if (*string == search) {
            result = string;
        }
    }

    return result;
}

char* SStrChrR(char* string, char search) {
    STORM_ASSERT(string);
    STORM_VALIDATE(string, ERROR_INVALID_PARAMETER, nullptr);

    char* result;

    for (result = nullptr; *string; string++) {
        if (*string == search) {
            result = string;
        }
    }

    return result;
}

char* SStrDupA(const char* string, const char* filename, uint32_t linenumber) {
    size_t len = SStrLen(string) + 1;
    char* dup = static_cast<char*>(SMemAlloc(len, filename, linenumber, 0x0));
    memcpy(dup, string, len);

    return dup;
}

const char* SStrStr(const char* string, const char* search) {
    STORM_ASSERT(string);
    STORM_ASSERT(search);

    if (!*string) {
        return nullptr;
    }

    auto searchEnd = search;
    while (*searchEnd) {
        searchEnd++;
    }
    size_t searchLength = searchEnd - search;

    auto substring = string;

    while (SStrCmp(substring, search, searchLength)) {
        substring++;

        if (!*substring) {
            return nullptr;
        }
    }

    return substring;
}

void SStrUpper(char* string) {
    while (*string) {
        *string = static_cast<char>(toupper(*string));
        string++;
    }
}


