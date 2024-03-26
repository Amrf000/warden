// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.


#ifndef ENGINE_CGXDEVICE_H
#define ENGINE_CGXDEVICE_H

#include <cstring>
#include "common.h"
#include "NTempest.h"
#include "CGxTex.h"
#include "CGxStateBom.h"
#include "CGxAppRenderState.h"
#include "EGxRenderState.h"
#include "CGxPushedRenderState.h"

class CGxDevice {
public:
    virtual unsigned int * vfunc_CGxDevice_1(int a1, unsigned int *a2)
    {
        unsigned int *result;

        result = a2;
        if ( *a2 )
        {
            *a2 = 0;
            a2[1] = 0;
            a2[2] = 0;
            a2[3] = 0;
            a2[4] = 0;
            ++*(unsigned int *)(a1 + 108);
        }
        return result;
    }

    virtual int  vfunc_CGxDevice_3(unsigned int *a1)
    {
        int v1;
        int v2;

        *a1 = &off_E7FA48;
        v1 = 0;
        do
            ++v1;
        while ( a1[336] + 1 != v1 );
        TSGrowableArray<CGxTex *,TSCD<CGxTex *>>::SetCount(a1 + 335, 0);
        v2 = a1[347];
        if ( v2 )
            sub_B766(v2);
        TSFixedArray<CGxTex *,TSCD<CGxTex *>>::~TSFixedArray((TSFixedArray *)a1 + 113);
        TSFixedArray<CGxTex *,TSCD<CGxTex *>>::~TSFixedArray((TSFixedArray *)(a1 + 335));
        TSFixedArray<CGxStateBom,TSCD<CGxStateBom>>::~TSFixedArray(a1 + 332);
        TSFixedArray<CGxAppRenderState,TSCD<CGxAppRenderState>>::~TSFixedArray(a1 + 329);
        TSFixedArray<unsigned int,TSCD<unsigned int>>::~TSFixedArray(a1 + 31);
        TSFixedArray<EGxRenderState,TSCD<EGxRenderState>>::~TSFixedArray(a1 + 9);
        TSFixedArray<unsigned long,TSCD<unsigned long>>::~TSFixedArray(a1 + 5);
        return TSFixedArray<CGxPushedRenderState,TSCD<CGxPushedRenderState>>::~TSFixedArray(a1 + 1);
    }

    virtual int  vfunc_CGxDevice_4(TRefCnt *a1)
    {
        vtable_TRefCnt_struct *v1;
        int v2;

        a1->vptr = (vtable_TRefCnt_struct *)&off_E7FA48;
        v1 = 0;
        do
            v1 = (vtable_TRefCnt_struct *)((char *)v1 + 1);
        while ( (vtable_TRefCnt_struct *)((char *)&a1[168].vptr->vfunc_TRefCnt_1 + 1) != v1 );
        TSGrowableArray<CGxTex *,TSCD<CGxTex *>>::SetCount(&a1[167].cnt, 0);
        v2 = a1[173].cnt;
        if ( v2 )
            sub_B766(v2);
        TSFixedArray<CGxTex *,TSCD<CGxTex *>>::~TSFixedArray((TSFixedArray *)&a1[169].cnt);
        TSFixedArray<CGxTex *,TSCD<CGxTex *>>::~TSFixedArray((TSFixedArray *)&a1[167].cnt);
        TSFixedArray<CGxStateBom,TSCD<CGxStateBom>>::~TSFixedArray(&a1[166]);
        TSFixedArray<CGxAppRenderState,TSCD<CGxAppRenderState>>::~TSFixedArray(&a1[164].cnt);
        TSFixedArray<unsigned int,TSCD<unsigned int>>::~TSFixedArray(&a1[15].cnt);
        TSFixedArray<EGxRenderState,TSCD<EGxRenderState>>::~TSFixedArray(&a1[4].cnt);
        TSFixedArray<unsigned long,TSCD<unsigned long>>::~TSFixedArray(&a1[2].cnt);
        TSFixedArray<CGxPushedRenderState,TSCD<CGxPushedRenderState>>::~TSFixedArray(&a1->cnt);
        return sub_29559C(a1);
    }

    virtual int  vfunc_CGxDevice_5(unsigned int *a1, int a2, unsigned int *a3)
    {
        if ( a3 )
        {
            a1[37] = *a3;
            a1[38] = a3[1];
            a1[39] = a3[2];
            a1[40] = a3[3];
            a1[41] = a3[4];
            a1[42] = a3[5];
        }
        else
        {
            memset(a1 + 37, 0, 0x18u);
        }
        return 1;
    }

    virtual int  vfunc_CGxDevice_6(unsigned int *a1)
    {
        int v1;
        int v3;
        int i;

        v3 = a1[340];
        v1 = 4 * v3 - 4;
        for ( i = 0; v3 != i; ++i )
        {
            (*(void ( **)(unsigned int *, unsigned int))(*a1 + 180))(a1, *(unsigned int *)(a1[341] + v1));
            v1 -= 4;
        }
        return TSFixedArray<CGxTex *,TSCD<CGxTex *>>::Clear((int)(a1 + 339));
    }

    virtual int  vfunc_CGxDevice_7(unsigned int *a1, unsigned int *a2)
    {
        if ( a2 )
        {
            a1[37] = *a2;
            a1[38] = a2[1];
            a1[39] = a2[2];
            a1[40] = a2[3];
            a1[41] = a2[4];
            a1[42] = a2[5];
        }
        else
        {
            memset(a1 + 37, 0, 0x18u);
        }
        return 1;
    }

    virtual int  vfunc_CGxDevice_8(int a1, int a2)
    {
        int result;

        result = a1;
        *(unsigned int *)(a1 + 212) = a2;
        return result;
    }

    virtual int  vfunc_CGxDevice_9(int a1, int a2)
    {
        int result;

        result = a1;
        *(unsigned int *)(a1 + 216) = a2;
        return result;
    }

    virtual int  vfunc_CGxDevice_10(int a1, int a2)
    {
        int result;

        result = a1;
        *(unsigned int *)(a1 + 220) = a2;
        return result;
    }

    virtual int  vfunc_CGxDevice_12(int a1)
    {
        int result;

        result = a1;
        *(unsigned int *)(a1 + 1376) = 1;
        return result;
    }

    virtual unsigned int * vfunc_CGxDevice_13(unsigned int *a1, unsigned int *a2, unsigned int *a3, unsigned int *a4)
    {
        unsigned int *result;

        *a2 = a1[345];
        *a3 = a1[346];
        result = a4;
        *a4 = a1[347];
        return result;
    }

    virtual int  vfunc_CGxDevice_18(int a1, int a2)
    {
        return NTempest::CImVector::operator=(a1 + 224, a2);
    }

    virtual void vfunc_CGxDevice_19()
    {
        ;
    }

    virtual int  vfunc_CGxDevice_20(unsigned int *a1)
    {
        int *v1;
        int v2;
        float v3;
        float v4;
        float v5;
        __m128 v6;
        __m128 v7;
        __m128 v8;
        __m128 v9;
        __m128 v10;
        __m128 v11;
        __m128 v12;
        __m128 v13;
        int v14;
        int v15;
        int i;
        unsigned int *v17;
        __m128 v18;
        __m128 v19;
        __m128 v20;
        int v21;
        int j;
        unsigned int *v23;
        int v24;
        int result;
        unsigned __int64 v26;
        float v27;
        float v28;
        float v29;
        float v30;
        signed __int64 v31;
        signed __int64 v32;
        signed __int64 v33;
        __int64 v34;
        int v35;
        int v36;
        char v37[32];

        ++a1[22];
        qword_D6E2D8 -= *(_QWORD *)&dword_D6DEC0[2 * (((_BYTE)dword_D6DED4 + 120) & 0x7F) + 6];
        qword_D6E2E4 -= *(_QWORD *)&dword_D6DEC0[2 * (((_BYTE)dword_D6DED4 + 112) & 0x7F) + 6];
        qword_D6E2F0 -= *(_QWORD *)&dword_D6DEC0[2 * (((_BYTE)dword_D6DED4 + 96) & 0x7F) + 6];
        qword_D6E2FC -= *(_QWORD *)&dword_D6DEC0[2 * (dword_D6DED4 & 0x7F) + 6];
        v1 = (int *)sub_10FEC(v37);
        v2 = v1[1];
        dword_D6DECC = *v1;
        v26 = __PAIR64__(v2, dword_D6DECC);
        dword_D6DED0 = v2;
        qword_D6E2D8 += __PAIR64__(v2, dword_D6DECC) - qword_D6DEC4;
        v34 = qword_D6E2D8;
        v33 = qword_D6E2E4 + __PAIR64__(v2, dword_D6DECC) - qword_D6DEC4;
        qword_D6E2E4 = v33;
        v32 = qword_D6E2F0 + __PAIR64__(v2, dword_D6DECC) - qword_D6DEC4;
        qword_D6E2F0 = v32;
        v31 = qword_D6E2FC + __PAIR64__(v2, dword_D6DECC) - qword_D6DEC4;
        qword_D6E2FC = v31;
        LOBYTE(v1) = dword_D6DED4;
        *(_QWORD *)&dword_D6DEC0[2 * dword_D6DED4 + 6] = __PAIR64__(v2, dword_D6DECC) - qword_D6DEC4;
        dword_D6DED4 = ((_BYTE)v1 + 1) & 0x7F;
        qword_D6DEC4 = v26;
        if ( v34 > 1024 )
        {
            v30 = (float)v34;
            v3 = 8000000.0 / v30;
        }
        else
        {
            v3 = 99.989998;
        }
        dword_D6E2E0 = LODWORD(v3);
        if ( v33 > 1024 )
        {
            v29 = (float)v33;
            v4 = 16000000.0 / v29;
        }
        else
        {
            v4 = 99.989998;
        }
        dword_D6E2EC = LODWORD(v4);
        if ( v32 > 1024 )
        {
            v28 = (float)v32;
            v5 = 32000000.0 / v28;
        }
        else
        {
            v5 = 99.989998;
        }
        dword_D6E2F8 = LODWORD(v5);
        if ( v31 > 1024 )
        {
            v27 = (float)v31;
            v6 = (__m128)0x4CF42400u;
            v6.f32[0] = 128000000.0 / v27;
        }
        else
        {
            v6 = (__m128)0x42C7FAE1u;
        }
        dword_D6E304 = v6.i32[0];
        if ( dword_D6DEC0[0] > 8 )
        {
            if ( dword_D6DEC0[0] > 16 )
            {
                if ( dword_D6DEC0[0] <= 32 )
                    v6 = (__m128)(unsigned int)dword_D6E2F8;
            }
            else
            {
                v6 = (__m128)(unsigned int)dword_D6E2EC;
            }
        }
        else
        {
            v6 = (__m128)(unsigned int)dword_D6E2E0;
        }
        v7 = v6;
        v7.f32[0] = fmaxf(v6.f32[0] + 0.5, 0.0);
        v8.i32[0] = 1325400064;
        v9 = _mm_cmple_ss(v8, v7);
        v10.i32[0] = 1333788672;
        a1[21] = _mm_or_si128(
                _mm_add_epi32(
                        _mm_cvttps_epi32(_mm_sub_ps(v7, _mm_and_ps(v9, (__m128)0x4F000000u))),
                        _mm_slli_epi32((__m128i)v9, 0x1Fu)),
                (__m128i)_mm_cmple_ss(v10, v7)).u32[0];
        v6.f32[0] = (float)(v6.f32[0] * 100.0) + 0.0049999999;
        v11 = v6;
        v11.f32[0] = fmaxf(v6.f32[0], 0.0);
        v10.i32[0] = 1325400064;
        v12 = _mm_cmple_ss(v10, v11);
        v9.i32[0] = 1333788672;
        v13 = (__m128)_mm_or_si128(
                _mm_add_epi32(
                        _mm_cvttps_epi32(_mm_sub_ps(v11, _mm_and_ps(v12, (__m128)0x4F000000u))),
                        _mm_slli_epi32((__m128i)v12, 0x1Fu)),
                (__m128i)_mm_cmple_ss(v9, v11));
        a1[28] = v13.i32[0];
        v14 = 0;
        a1[26] = 0;
        v36 = a1[336];
        v15 = 4 * v36 - 4;
        for ( i = 0; v36 != i; ++i )
        {
            v17 = *(unsigned int **)(a1[337] + v15);
            if ( v17 )
            {
                v14 += v17[6] * v17[5] * (v17[7] == 0 ? 4 : 2);
                a1[26] = v14;
            }
            v15 -= 4;
        }
        if ( v14 < 0 )
            v13.f32[0] = (float)(v14 & 1 | ((unsigned int)v14 >> 1)) + (float)(v14 & 1 | ((unsigned int)v14 >> 1));
        else
            v13.f32[0] = (float)v14;
        v13.f32[0] = fmaxf(v13.f32[0] * 1.3, 0.0);
        v18.i32[0] = 1325400064;
        v19 = _mm_cmple_ss(v18, v13);
        v20.i32[0] = 1333788672;
        a1[26] = _mm_or_si128(
                _mm_add_epi32(
                        _mm_cvttps_epi32(_mm_sub_ps(v13, _mm_and_ps((__m128)0x4F000000u, v19))),
                        _mm_slli_epi32((__m128i)v19, 0x1Fu)),
                (__m128i)_mm_cmple_ss(v20, v13)).u32[0];
        a1[344] = 0;
        v35 = a1[340];
        v21 = 4 * v35 - 4;
        for ( j = 0; j != v35 && j != 4; ++j )
        {
            (*(void ( **)(unsigned int *, unsigned int))(*a1 + 180))(a1, *(unsigned int *)(a1[341] + v21));
            v21 -= 4;
        }
        TSGrowableArray<CGxTex *,TSCD<CGxTex *>>::SetCount(a1 + 339, v35 - j);
        v23 = a1;
        v24 = 8;
        do
        {
            v23[13] = v23[21];
            v23[21] = 0;
            ++v23;
            --v24;
        }
        while ( v24 );
        result = a1[14];
        a1[22] = result;
        return result;
    }

    virtual int  vfunc_CGxDevice_21(unsigned int *a1, int a2, int a3, int a4, int a5, int a6, int a7)
    {
        int result;

        a1[57] = a2;
        a1[58] = a3;
        a1[59] = a4;
        a1[60] = a5;
        a1[61] = a6;
        result = a7;
        a1[62] = a7;
        return result;
    }

    virtual int  vfunc_CGxDevice_22(unsigned int *a1, unsigned int *a2)
    {
        int result;

        a1[63] = *a2;
        a1[64] = a2[1];
        a1[65] = a2[2];
        a1[66] = a2[3];
        a1[67] = a2[4];
        a1[68] = a2[5];
        a1[69] = a2[6];
        a1[70] = a2[7];
        a1[71] = a2[8];
        a1[72] = a2[9];
        a1[73] = a2[10];
        a1[74] = a2[11];
        a1[75] = a2[12];
        a1[76] = a2[13];
        a1[77] = a2[14];
        result = a2[15];
        a1[78] = result;
        return result;
    }

    virtual int  vfunc_CGxDevice_23(unsigned int *a1, unsigned int *a2)
    {
        int result;

        a1[79] = *a2;
        a1[80] = a2[1];
        a1[81] = a2[2];
        a1[82] = a2[3];
        a1[83] = a2[4];
        a1[84] = a2[5];
        a1[85] = a2[6];
        a1[86] = a2[7];
        a1[87] = a2[8];
        a1[88] = a2[9];
        a1[89] = a2[10];
        result = a2[11];
        a1[90] = result;
        return result;
    }

    virtual int  vfunc_CGxDevice_24(unsigned int *a1, unsigned int *a2)
    {
        int result;

        a1[91] = *a2;
        a1[92] = a2[1];
        a1[93] = a2[2];
        a1[94] = a2[3];
        a1[95] = a2[4];
        a1[96] = a2[5];
        a1[97] = a2[6];
        a1[98] = a2[7];
        a1[99] = a2[8];
        a1[100] = a2[9];
        a1[101] = a2[10];
        result = a2[11];
        a1[102] = result;
        return result;
    }

    virtual int  vfunc_CGxDevice_25(int a1, int a2, int a3)
    {
        int result;

        result = a1;
        *(unsigned int *)(a1 + 412) = a3;
        *(unsigned int *)(a1 + 416) = a2;
        return result;
    }

    virtual int  vfunc_CGxDevice_26(int a1, int a2, int *a3)
    {
        int v3;
        int v4;
        int v5;
        int v6;
        int v7;
        unsigned int *v8;
        int result;
        int v10;
        int v11;
        int v12;
        int v13;
        int v14;
        int v15;
        int v16;

        v16 = *a3;
        v15 = a3[1];
        v14 = a3[2];
        v13 = a3[3];
        v12 = a3[4];
        v11 = a3[5];
        v10 = a3[6];
        v3 = a3[7];
        v4 = a3[8];
        v5 = a3[9];
        v6 = a3[10];
        v7 = a3[11];
        v8 = (unsigned int *)(a1 + (a2 << 6));
        v8[120] = 1065353216;
        v8[119] = v7;
        v8[118] = v6;
        v8[117] = v5;
        result = 0;
        v8[116] = 0;
        v8[115] = v4;
        v8[114] = v3;
        v8[113] = v10;
        v8[112] = 0;
        v8[111] = v11;
        v8[110] = v12;
        v8[109] = v13;
        v8[108] = 0;
        v8[107] = v14;
        v8[106] = v15;
        v8[105] = v16;
        return result;
    }

    virtual int  vfunc_CGxDevice_27(int a1, int a2)
    {
        int result;

        result = a1;
        *(unsigned int *)(a1 + 548) = a2;
        return result;
    }

    virtual int  vfunc_CGxDevice_28(int a1, int a2)
    {
        int result;

        result = a1;
        *(unsigned int *)(a1 + 552) = a2;
        return result;
    }

    virtual int  vfunc_CGxDevice_29(int a1, int a2)
    {
        int result;

        result = a2;
        *(unsigned int *)(a1 + 92) += a2;
        return result;
    }

    virtual int  vfunc_CGxDevice_30(int a1, int a2, int a3)
    {
        int result;

        result = a1;
        *(unsigned int *)(a1 + 116) = a2;
        *(unsigned int *)(a1 + 120) = a3;
        return result;
    }

    virtual int  vfunc_CGxDevice_31(unsigned int *a1)
    {
        int v1;
        unsigned int v2;
        int v3;
        int result;
        unsigned int v5;
        int v6;

        v1 = a1[24];
        v2 = a1[30];
        v3 = a1[29];
        v5 = dword_D6E338[v3];
        if ( v5 == 1 )
            v6 = v2 - dword_D6E320[v3];
        else
            v6 = v2 / v5 - dword_D6E320[v3];
        result = v1 + v6;
        a1[24] = v1 + v6;
        ++a1[25];
        return result;
    }

    virtual void vfunc_CGxDevice_32()
    {
        ;
    }

    virtual void vfunc_CGxDevice_33()
    {
        ;
    }

    virtual int  vfunc_CGxDevice_34(unsigned int *a1, int a2, int a3, unsigned int a4)
    {
        unsigned int v4;
        unsigned int v6;

        a1[23] += a2;
        v4 = dword_D6E338[a3];
        if ( v4 == 1 )
            v6 = a4 - dword_D6E320[a3];
        else
            v6 = a4 / v4 - dword_D6E320[a3];
        a1[24] += v6;
        ++a1[25];
        return 0;
    }

    virtual void vfunc_CGxDevice_35()
    {
        ;
    }

    virtual _BOOL4  vfunc_CGxDevice_36(int a1, int a2, const char *a3)
    {
        _BOOL4 result;

        CGxLight::operator=(36 * a2 + a1 + 556, a3);
        result = memcmp((const char *)(36 * a2 + a1 + 936), a3, 36) != 0;
        *(unsigned int *)(a1 + 4 * a2 + 1224) = result;
        return result;
    }

    virtual int  vfunc_CGxDevice_37(int a1, int a2, int a3)
    {
        int result;

        result = a1 + 36 * a2;
        *(unsigned int *)(result + 556) = a3;
        if ( a3 != *(unsigned int *)(result + 936) )
            *(unsigned int *)(a1 + 4 * a2 + 1224) = 1;
        return result;
    }

    virtual int  vfunc_CGxDevice_38(int a1, int a2, int a3)
    {
        int result;

        result = a1;
        *(unsigned int *)(a1 + 876) = a2;
        *(unsigned int *)(a1 + 880) = a3;
        return result;
    }

    virtual int  vfunc_CGxDevice_39(unsigned int *a1, int a2, int a3, int a4, int a5, int a6)
    {
        a1[221] = a2;
        a1[222] = a3;
        a1[223] = a4;
        a1[224] = a5;
        return NTempest::CImVector::operator=(a1 + 225, a6);
    }

    virtual int  vfunc_CGxDevice_40(int a1, char a2, char a3)
    {
        int result;

        result = *(unsigned int *)(a1 + 904) & __ROL4__(-2, a2);
        *(unsigned int *)(a1 + 904) = result | ((a3 & 1) << a2);
        return result;
    }

    virtual _BOOL4  vfunc_CGxDevice_41(int a1, unsigned int *a2)
    {
        _BOOL4 result;

        *(unsigned int *)(a1 + 908) = *a2;
        *(unsigned int *)(a1 + 912) = a2[1];
        *(unsigned int *)(a1 + 916) = a2[2];
        *(unsigned int *)(a1 + 920) = a2[3];
        *(unsigned int *)(a1 + 924) = a2[4];
        *(unsigned int *)(a1 + 928) = a2[5];
        result = memcmp((const char *)(a1 + 908), (const char *)(a1 + 1288), 24) != 0;
        *(unsigned int *)(a1 + 1312) = result;
        return result;
    }

    virtual int vfunc_CGxDevice_42()
    {
        return 0;
    }

    virtual void vfunc_CGxDevice_43()
    {
        ;
    }

    virtual void vfunc_CGxDevice_44()
    {
        ;
    }

    virtual int  vfunc_CGxDevice_45(unsigned int *a1, int a2, int a3, int a4, char a5, int a6, int a7, unsigned int *a8)
    {
        int v8;
        int v9;
        int v10;
        int v11;

        v8 = a1[32];
        v9 = sub_B3FE(
                0x38u,
                "/Volumes/F1/usrbuild/xb/build/War3x_B6401/War3/Source/Mac/../../../Engine/Source/Gx/CGxDevice/CGxDevice.cpp",
                1181,
                0);
        if ( v9 )
            sub_2CC040(v9, a2, a3, a4, a5, a6, a7);
        if ( v8 )
        {
            v10 = v8 - 1;
            v11 = *(unsigned int *)(a1[33] + 4 * (v8 - 1));
            TSGrowableArray<unsigned int,TSCD<unsigned int>>::SetCount(a1 + 31, v10);
            *(unsigned int *)(a1[337] + 4 * v11) = v9;
        }
        else
        {
            *(unsigned int *)TSGrowableArray<CGxTex *,TSCD<CGxTex *>>::New((int)(a1 + 335)) = v9;
            v11 = a1[336] - 1;
        }
        *(unsigned int *)(v9 + 52) = v11;
        *a8 = v9;
        return 1;
    }

    virtual int  vfunc_CGxDevice_46(int a1, TRefCnt *a2)
    {
        *(unsigned int *)TSGrowableArray<unsigned int,TSCD<unsigned int>>::New(a1 + 124) = a2[6].cnt;
        *(unsigned int *)(*(unsigned int *)(a1 + 1348) + 4 * a2[6].cnt) = 0;
        return sub_29559C(a2);
    }
public:
    TSGrowableArray<CGxPushedRenderState> field_TSGrowableArray_CGxPushedRenderState;
    TSGrowableArray<unsigned long> field_TSGrowableArray_unsigned_long_0;
    TSGrowableArray<EGxRenderState> field_TSGrowableArray_EGxRenderState;
    int m_data34;
    int field_38;
    int field_3c;
    int field_40;
    int field_44;
    int field_48;
    int field_4c;
    int field_50;
    int m_data54;
    int m_data58;
    int field_5c;
    int field_60;
    int field_64;
    int field_68;
    int field_CGxTex_count;
    int field_70;
    int field_74;
    int field_78;
    TSGrowableArray<unsigned int> field_TSGrowableArray_unsigned_int_0;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
    int field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    int field_D4;
    int m_dataD8;
    int field_DC;
    NTempest::CImVector field_CImVector_struc_0;
    CBoundingBox field_CBoundingBox;
    NTempest::C44Matrix field_struc_C44Matrix;
    NTempest::C34Matrix field_C34Matrix_0;
    NTempest::C34Matrix field_C34Matrix_1;
    int field_F4;
    int field_F8;
    int field_FC;
    int field_100;
    int field_104;
    int field_108;
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    int field_11C;
    int field_120;
    int field_124;
    int field_128;
    int field_12C;
    int field_130;
    int field_134;
    int field_138;
    int field_13C;
    int field_140;
    int field_144;
    int field_148;
    int field_14C;
    int field_150;
    int field_154;
    int field_158;
    int field_15c;
    int field_160;
    int field_164;
    int field_168;
    int field_16c;
    int field_170;
    int field_174;
    int field_178;
    int field_17c;
    int field_180;
    int field_184;
    int field_188;
    int field_18c;
    int field_190;
    int field_194;
    int field_198;
    int field_19c;
    int field_1a0;
    int field_1a4;
    int field_1a8;
    int field_1ac;
    int field_1b0;
    int field_1b4;
    int field_1b8;
    int field_1bc;
    int field_1c0;
    int field_1c4;
    int field_1c8;
    int field_1cc;
    int field_1d0;
    int field_1d4;
    int field_1d8;
    int field_1dc;
    int field_1e0;
    int field_1e4;
    int field_1e8;
    int field_1ec;
    int field_1f0;
    int field_1f4;
    int field_1f8;
    int field_1fc;
    int field_200;
    int field_204;
    int field_208;
    int field_20c;
    int field_210;
    int field_214;
    int field_218;
    int field_21c;
    int field_220;
    int field_224;
    int field_228;
    int field_22c;
    int field_230;
    int field_234;
    int field_238;
    int field_23c;
    int field_240;
    int field_244;
    int field_248;
    int field_24c;
    int field_250;
    int field_254;
    int field_258;
    int field_25c;
    int field_260;
    int field_264;
    int field_268;
    int field_26c;
    int field_270;
    int field_274;
    int field_278;
    int field_27c;
    int field_280;
    int field_284;
    int field_288;
    int field_28c;
    int field_290;
    int field_294;
    int field_298;
    int field_29c;
    int field_2a0;
    int field_2a4;
    int field_2a8;
    int field_2ac;
    int field_2b0;
    int field_2b4;
    int field_2b8;
    int field_2bc;
    int field_2c0;
    int field_2c4;
    int field_2c8;
    int field_2cc;
    int field_2d0;
    int field_2d4;
    int field_2d8;
    int field_2dc;
    int field_2e0;
    int field_2e4;
    int field_2e8;
    int field_2ec;
    int field_2f0;
    int field_2f4;
    int field_2f8;
    int field_2fc;
    int field_300;
    int field_304;
    int field_308;
    int field_30c;
    int field_310;
    int field_314;
    int field_318;
    int field_31c;
    int field_320;
    int field_324;
    int field_328;
    int field_32c;
    int field_330;
    int field_334;
    int field_338;
    int field_33c;
    int field_340;
    int field_344;
    int field_348;
    int field_34c;
    int field_350;
    int field_354;
    int field_358;
    int field_35c;
    int field_360;
    int field_364;
    int field_368;
    int field_36c;
    int field_370;
    int field_374;
    int field_378;
    int field_37c;
    int field_380;
    NTempest::CImVector field_CImVector_1;
    int field_388;
    CGxMat field_struc_CGxMat_0;
    int field_3a4;
    int field_3A8;
    int field_3Ac;
    int field_3B0;
    int field_3B4;
    int field_3b8;
    int field_3bc;
    int field_3c0;
    int field_3c4;
    int field_3c8;
    int field_3cc;
    int field_3d0;
    int field_3d4;
    int field_3d8;
    int field_3dc;
    int field_3e0;
    int field_3e4;
    int field_3e8;
    int field_3ec;
    int field_3f0;
    int field_3f4;
    int field_3f8;
    int field_3fc;
    int field_400;
    int field_404;
    int field_408;
    int field_40c;
    int field_410;
    int field_414;
    int field_418;
    int field_41c;
    int field_420;
    int field_424;
    int field_428;
    int field_42c;
    int field_430;
    int field_434;
    int field_438;
    int field_43c;
    int field_440;
    int field_444;
    int field_448;
    int field_44c;
    int field_450;
    int field_454;
    int field_458;
    int field_45c;
    int field_460;
    int field_464;
    int field_468;
    int field_46c;
    int field_470;
    int field_474;
    int field_478;
    int field_47c;
    int field_480;
    int field_484;
    int field_488;
    int field_48c;
    int field_490;
    int field_494;
    int field_498;
    int field_49c;
    int field_4a0;
    int field_4a4;
    int field_4a8;
    int field_4ac;
    int field_4b0;
    int field_4b4;
    int field_4b8;
    int field_4bc;
    int field_4c0;
    int field_4c4;
    int field_4c8;
    int field_4cc;
    int field_4d0;
    int field_4d4;
    int field_4d8;
    int field_4dc;
    int field_4e0;
    int field_4e4;
    int field_4e8;
    int field_4ec;
    int field_4f0;
    int field_4f4;
    int field_4f8;
    int field_4fc;
    NTempest::CImVector field_500;
    int field_504;
    CGxMat field_struc_CGxMat_1;
    int field_520;
    TSFixedArray<CGxAppRenderState> field_TSFixedArray_CGxAppRenderState;
    TSFixedArray<CGxStateBom> field_TSFixedArray_CGxStateBom;
    TSGrowableArray<CGxTex *> field_TSGrowableArray_CGxTex_ptr_0;
    TSGrowableArray<CGxTex *> field_TSGrowableArray_CGxTex_ptr_1;
    int field_55C;
    int m_data560;
    int m_data564;
    int m_data568;
    void* m_data347;
    int field_570;
    int field_574;
};


#endif //ENGINE_CGXDEVICE_H
