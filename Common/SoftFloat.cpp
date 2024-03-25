// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/26.
//

#include "SoftFloat.h"


unsigned int *SoftFloatFromInt(unsigned int *a1, unsigned int a2) {
    signed int v2; // edi
    unsigned int v3; // eax
    unsigned int v5; // [esp+4h] [ebp-Ch]

    if (a2) {
        v2 = a2;
        if ((int) a2 <= -1)
            v2 = -a2;
        if (v2) {
            _BitScanReverse(&v3, v2);
            v5 = v3 ^ 0x1F;
        } else {
            v5 = 32;
        }
        *a1 = ((158 - v5) << 23) | a2 & 0x80000000 |
              ((v2 >> (8 - v5)) & ((int) (v5 - 8) >> 31) | ~((int) (v5 - 8) >> 31) & (v2 << (v5 - 8))) & 0x7FFFFF;
    } else {
        *a1 = 0;
    }
    return a1;
}

unsigned int *softFloatSubtract(unsigned int *a1, unsigned int *a2, unsigned int *a3) {
    signed int v3; // esi
    int v4; // ecx
    int v5; // edi
    int v6; // eax
    int v7; // edx
    signed int v8; // eax
    signed int v9; // esi
    int v10; // eax
    signed int v11; // edi
    unsigned int v12; // eax
    unsigned int v14; // [esp+4h] [ebp-14h]
    unsigned int v15; // [esp+8h] [ebp-10h]
    int v16; // [esp+Ch] [ebp-Ch]

    v3 = *a3 + 0x80000000;
    v4 = *a2;
    v15 = *a2 & 0x7F800000;
    if (!v15)
        goto LABEL_16;
    v16 = v3 & 0x7F800000;
    if ((v3 & 0x7F800000) == 0)
        goto LABEL_15;
    v5 = ((v4 >> 31) ^ ((2 * (v4 & 0x7FFFFF)) | 0x1000000)) - (v4 >> 31);
    v6 = ((v3 >> 31) ^ ((2 * (v3 & 0x7FFFFF)) | 0x1000000)) - (v3 >> 31);
    v7 = v16 - v15;
    if ((int) (v16 - v15) > 0) {
        if (v7 <= 192937983) {
            v5 >>= (unsigned int) v7 >> 23;
            v15 = v3 & 0x7F800000;
            goto LABEL_8;
        }
        LABEL_16:
        *a1 = v3;
        return a1;
    }
    if (v7 <= -192937984) {
        LABEL_15:
        *a1 = v4;
        return a1;
    }
    v6 >>= (v15 - v16) >> 23;
    LABEL_8:
    v8 = v5 + v6;
    if (v8) {
        v14 = v8 & 0x80000000;
        v9 = v8;
        v10 = -v8;
        if (v9 <= -1)
            v9 = v10;
        if (v9) {
            _BitScanReverse(&v12, v9);
            v11 = 8 - (v12 ^ 0x1F);
        } else {
            v11 = -24;
        }
        *a1 = ((v9 << -(char) v11) & (v11 >> 31) | ~(v11 >> 31) & (v9 >> v11)) & 0x7FFFFF |
              ((v11 << 23) + v15 - 0x800000) | v14;
    } else {
        *a1 = 0;
    }
    return a1;
}

unsigned int *softFloatSqrt(unsigned int *a1, unsigned int *a2) {
    signed int v2; // esi
    unsigned int v3; // ecx
    unsigned int v4; // edx
    unsigned int v5; // esi
    int v6; // edi
    int v8; // [esp+1Ch] [ebp-1Ch]
    int v9; // [esp+24h] [ebp-14h] BYREF
    unsigned int v10; // [esp+28h] [ebp-10h] BYREF
    int v11[3]; // [esp+2Ch] [ebp-Ch] BYREF

    v2 = *a2;
    if ((~((int) *a2 >> 31) & (2 * *a2)) != 0) {
        v8 = (unsigned __int8) (v2 >> 23) - 127;
        v3 = ((v2 & 0x7FFFFFu) >> 15) | ((v2 & 0x7FFFFF) << 8) | 0x80000000;
        v4 = 0;
        v5 = 0;
        v6 = 16;
        do {
            v4 = (v3 >> 30) | (4 * v4);
            v3 *= 4;
            v5 *= 2;
            if (v4 > v5) {
                v4 = v4 - v5 - 1;
                v5 += 2;
            }
            --v6;
        } while (v6);
        v10 = ((46341 * ((v5 >> 1) - 46340)) >> 8) | 0x3F800000;
        v9 = (v8 << 31 >> 31) & 0x3504F3 | ((((v8 << 31 >> 31) + v8) / 2 + 127) << 23);
        softFloatMultiply((unsigned int *) v11, &v9, &v10);
        *a1 = v11[0];
    } else {
        *a1 = 0;
    }
    return a1;
}

unsigned int *softFloatReciprocal(unsigned int *a1, unsigned int *a2) {
    int v2; // ecx
    unsigned int v4; // [esp+10h] [ebp-14h]

    v4 = *a2;
    v2 = 2122317824
         - (v4 & 0x7F800000)
         + dword_A7B400[(*a2 & 0x7FFFFF) >> 13]
         - ((((v4 << 19 >> 26) | (v4 << 6) & 0x7FFFF | (v4 << 19))
             * (unsigned __int64) (unsigned int) (dword_A7B400[(*a2 & 0x7FFFFF) >> 13]
                                                  - dword_A7B400[((*a2 & 0x7FFFFF) >> 13) + 1])) >> 32);
    *a1 = ~((v2 - (int) &loc_800000) >> 31) & (v2 | *a2 & 0x80000000);
    return a1;
}

unsigned int *softFloatMultiply(unsigned int *a1, unsigned int *a2, unsigned int *a3) {
    unsigned int v3; // esi
    unsigned int v4; // edi
    unsigned int v5; // ecx
    int v6; // eax
    unsigned int v8; // [esp+8h] [ebp-10h]
    unsigned int v9; // [esp+Ch] [ebp-Ch]

    v8 = (*a3 ^ *a2) & 0x80000000;
    v3 = *a2 & 0x7F800000;
    v9 = *a3 & 0x7F800000;
    v4 = *a3 & 0x7FFFFF;
    v5 = *a2 & 0x7FFFFF;
    if (v5 && v4) {
        v6 = (((v4 << 8) | 0x80000000) * (unsigned __int64) ((v5 << 8) | 0x80000000)) >> 32;
        *a1 = ~((int) (v9 + v3 - 0x40000000) >> 31) & ((v9 + v3 + ((unsigned int) v6 >> 31 << 23) - 1065353216) | v8 |
                                                       ((unsigned int) v6 >> (v6 < 0) >> 7) & 0x7FFFFF);
    } else if (v3 && v9) {
        *a1 = ~((int) (v3 + v9 - 0x40000000) >> 31) & ((v3 + v9 - 1065353216) | v8 | v5 | v4);
    } else {
        *a1 = 0;
    }
    return a1;
}

unsigned int *softFloatInverseSqrt(unsigned int *a1, unsigned int *a2) {
    int v3[3]; // [esp+1Ch] [ebp-Ch] BYREF

    softFloatSqrt((unsigned int *) v3, a2);
    softFloatReciprocal(a1, (unsigned int *) v3);
    return a1;
}

unsigned int *softFloatDiv(unsigned int *a1, unsigned int *a2, unsigned int *a3) {
    int v4[3]; // [esp+1Ch] [ebp-Ch] BYREF

    if (*a2 == *a3) {
        *a1 = 1065353216;
    } else {
        softFloatReciprocal((unsigned int *) v4, a3);
        softFloatMultiply(a1, a2, (unsigned int *) v4);
    }
    return a1;
}

unsigned int *softFloatAdd(unsigned int *ret, float *value1, float *value2) {
    signed int v3; // ecx
    signed int v4; // esi
    int v5; // edi
    int v6; // eax
    int v7; // edx
    signed int v8; // eax
    signed int v9; // esi
    int v10; // eax
    signed int v11; // edi
    unsigned int v12; // eax
    unsigned int v14; // [esp+4h] [ebp-14h]
    int v15; // [esp+8h] [ebp-10h]
    int v16; // [esp+Ch] [ebp-Ch]

    v3 = *(_DWORD *) value1;
    v15 = *(_DWORD *) value1 & 0x7F800000;
    if (!v15) {
        v4 = *(_DWORD *) value2;
        goto LABEL_17;
    }
    v4 = *(_DWORD *) value2;
    v16 = *(_DWORD *) value2 & 0x7F800000;
    if (!v16)
        goto LABEL_15;
    v5 = ((v3 >> 31) ^ ((2 * (v3 & 0x7FFFFF)) | 0x1000000)) - (v3 >> 31);
    v6 = ((v4 >> 31) ^ ((2 * (v4 & 0x7FFFFF)) | 0x1000000)) - (v4 >> 31);
    v7 = v16 - v15;
    if (v16 - v15 > 0) {
        if (v7 <= 192937983) {
            v5 >>= (unsigned int) v7 >> 23;
            v15 = *(_DWORD *) value2 & 0x7F800000;
            goto LABEL_8;
        }
        LABEL_17:
        *ret = v4;
        return ret;
    }
    if (v7 <= -192937984) {
        LABEL_15:
        *ret = v3;
        return ret;
    }
    v6 >>= (unsigned int) (v15 - v16) >> 23;
    LABEL_8:
    v8 = v5 + v6;
    if (v8) {
        v14 = v8 & 0x80000000;
        v9 = v8;
        v10 = -v8;
        if (v9 <= -1)
            v9 = v10;
        if (v9) {
            _BitScanReverse(&v12, v9);
            v11 = 8 - (v12 ^ 0x1F);
        } else {
            v11 = -24;
        }
        *ret = ((v9 << -(char) v11) & (v11 >> 31) | ~(v11 >> 31) & (v9 >> v11)) & 0x7FFFFF |
               ((v11 << 23) + v15 - 0x800000) | v14;
    } else {
        *ret = 0;
    }
    return ret;
}
