#pragma once

#include <cstring>
#include "common.h"
#include "NTempest.h"
#include "texture/CGxTex.h"
#include "CGxStateBom.h"
#include "CGxAppRenderState.h"
#include "const/EGxRenderState.h"
#include "CGxPushedRenderState.h"
#include "CGxFormat.h"
#include "const/EGxPrim.h"
#include "const/EGxApi.h"
#include "CGxCaps.h"
#include "CGxShader.h"
#include "CGxMatrixStack.h"
#include "CGxBuf.h"
#include "CGxPool.h"
#include "const/EGxPoolTarget.h"
#include "const/EGxShTarget.h"
#include "const/EGxMasterEnables.h"
#include "CGxVertexAttrib.h"
#include "const/EGxPoolHintBits.h"
#include "const/EGxTexWrapMode.h"
#include "const/EGxVertexBufferFormat.h"
#include "../Common/TSGetLink.h"
#include "ShaderConstants.h"
#include "../Game/CBoundingBox.h"
#include "const/EGxPoolUsage.h"
#include "const/EGxXform.h"

using namespace NTempest;

class CGxBatch;
class CGxTex;
class CGxTexFlags;
class CGxDevice {
public:
    // Static variables
    static uint32_t s_alphaRef[];
    static C3Vector s_pointScaleIdentity;
    static uint32_t s_primVtxAdjust[];
    static uint32_t s_primVtxDiv[];
    static ShaderConstants s_shadowConstants[2];
    static uint32_t s_streamPoolSize[];
    static uint32_t s_texFormatBitDepth[];
    static uint32_t s_texFormatBytesPerBlock[];
    // Static functions
    static void Log(const char* format, ...);
    static void Log(const CGxFormat& format);
    static CGxDevice* NewOpenGl();
    static uint32_t PrimCalcCount(EGxPrim primType, uint32_t count);
    // Member variables
    TSGrowableArray<CGxPushedRenderState,TSCD<CGxPushedRenderState>> m_pushedStates;
    TSGrowableArray<size_t,TSCD<size_t>> m_stackOffsets;
    TSGrowableArray<EGxRenderState,TSCD<EGxRenderState>> m_dirtyStates;
    CRect m_defWindowRect;
    CRect m_curWindowRect;
    EGxApi m_api = GxApis_Last;
    CGxFormat m_format;
    CGxCaps m_caps;
    TSHashTable<CGxShader, HASHKEY_STRI> m_shaderList[GxShTargets_Last];
    int32_t (*m_windowProc)(void* window, uint32_t message, uintptr_t wparam, intptr_t lparam) = nullptr;
    int32_t m_context = 0;
    int32_t intF5C = 0;
    int32_t m_windowVisible = 0;
    int32_t intF64 = 0;
    int32_t intF6C = 1;
    CBoundingBox m_viewport;
    C44Matrix m_projection;
    C44Matrix m_projNative;
    CGxMatrixStack m_xforms[GxXforms_Last];
    uint32_t m_appMasterEnables = 0;
    uint32_t m_hwMasterEnables = 0;
    TSList<CGxPool, TSGetLink<CGxPool>> m_poolList;
    CGxBuf* m_bufLocked[GxPoolTargets_Last];
    CGxPool* m_vertexPool = nullptr;
    CGxPool* m_indexPool = nullptr;
    CGxBuf* m_streamBufs[GxPoolTargets_Last];
    CGxVertexAttrib m_primVertexFormatAttrib[GxVertexBufferFormats_Last];
    CGxBuf* m_primVertexFormatBuf[GxVertexBufferFormats_Last];
    uint32_t m_primVertexMask = 0;
    uint32_t m_primVertexDirty = 0;
    EGxVertexBufferFormat m_primVertexFormat = GxVertexBufferFormats_Last;
    CGxBuf* m_primVertexBuf = nullptr;
    uint32_t m_primVertexSize;
    CGxBuf* m_primIndexBuf = nullptr;
    int32_t m_primIndexDirty = 0;
    TSFixedArray<CGxAppRenderState,TSCD<CGxAppRenderState>> m_appRenderStates;
    TSFixedArray<CGxStateBom,TSCD<CGxStateBom>> m_hwRenderStates;
    uint32_t m_baseMipLevel = 0; // TODO placeholder
public:
    virtual unsigned int * ITexMarkAsUpdated(int a1, unsigned int *a2)
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
    virtual void IRsSendToHw(EGxRenderState) = 0;


    virtual int   ICursorCreate(unsigned int *a1)
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

    virtual int  DeviceCreate(TRefCnt *a1)
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
    // Member functions
    CGxDevice();
    const CGxCaps& Caps() const;
    CGxBuf* BufCreate(CGxPool*, uint32_t, uint32_t, uint32_t);
    CGxBuf* BufStream(EGxPoolTarget, uint32_t, uint32_t);
    void DeviceCreatePools(void);
    void DeviceCreateStreamBufs(void);
    const CRect& DeviceCurWindow(void);
    void DeviceSetCurWindow(const CRect&);
    void DeviceSetDefWindow(CRect const&);
    const CRect& DeviceDefWindow(void);
    int32_t IDevIsWindowed();
    void IRsDirty(EGxRenderState);
    void IRsForceUpdate(void);
    void IRsForceUpdate(EGxRenderState);
    void IRsInit(void);
    void IRsSync(int32_t);
    void IShaderBind(void) ;
    void IShaderLoad(CGxShader*[], EGxShTarget, const char*, const char*, int32_t);
    void ITexBind(void);
    void ITexWHDStartEnd(CGxTex*, uint32_t&, uint32_t&, uint32_t&, uint32_t&);
    int32_t MasterEnable(EGxMasterEnables);
    CGxPool* PoolCreate(EGxPoolTarget, EGxPoolUsage, uint32_t, EGxPoolHintBits, const char*);
    void PrimIndexPtr(CGxBuf*);
    void PrimVertexFormat(CGxBuf*, CGxVertexAttrib*, uint32_t);
    void PrimVertexMask(uint32_t);
    void PrimVertexPtr(CGxBuf*, EGxVertexBufferFormat);
    void RsGet(EGxRenderState, int32_t&);
    void RsSet(EGxRenderState, int32_t);
    void RsSet(EGxRenderState, void*);
    void RsSetAlphaRef(void);
    void RsPop(void);
    void RsPush(void);
    void ShaderConstantsClear(void);
    char* ShaderConstantsLock(EGxShTarget target);
    void ShaderConstantsUnlock(EGxShTarget target, uint32_t index, uint32_t count);
    void TexMarkForUpdate(CGxTex*, const CiRect&, int32_t);
    void TexSetWrap(CGxTex* texId, EGxTexWrapMode wrapU, EGxTexWrapMode wrapV);
    void XformPop(EGxXform xf);
    void XformProjection(C44Matrix&);
    void XformProjNative(C44Matrix&);
    void XformPush(EGxXform xf);
    void XformSet(EGxXform xf, const C44Matrix& matrix);
    void XformSetViewport(float, float, float, float, float, float);
    void XformView(C44Matrix&);
    void XformViewport(float&, float&, float&, float&, float&, float&);
};



