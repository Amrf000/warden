// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.


#ifndef ENGINE_CGXDEVICEOPENGL_H
#define ENGINE_CGXDEVICEOPENGL_H
#include "CGxDevice.h"
#include <GL/gl.h>
#include "Storm.h"


class CGxDeviceOpenGl: public CGxDevice {
public:
    virtual unsigned int * vfunc_CGxDeviceOpenGl_1(unsigned int *a1, int a2)
    {
        unsigned int v2;
        unsigned int v3;
        unsigned int v4;
        unsigned int v5;
        unsigned int v6;
        size_t v7;
        int v8;
        int v9;
        unsigned int *v10;
        unsigned int v11;
        int v12;
        GLenum v13;
        unsigned int jj;
        unsigned int ll;
        unsigned int nn;
        _WORD *v17;
        unsigned int n;
        unsigned __int8 *v19;
        int *v20;
        int l;
        unsigned int *v22;
        int j;
        unsigned int v24;
        GLint v25;
        int v26;
        int v27;
        int v28;
        int v29;
        char v31;
        bool v32;
        int v33;
        unsigned int v34;
        int v35;
        int v36;
        unsigned int width;
        unsigned int height;
        GLsizei heighta;
        int format;
        int v41;
        unsigned int v42;
        unsigned int ii;
        unsigned int kk;
        unsigned int mm;
        unsigned int *v46;
        unsigned int m;
        unsigned int v48;
        unsigned int v49;
        int k;
        _WORD *v51;
        int i;
        GLint level;
        unsigned int v54;
        unsigned int *pixels;
        unsigned int v56;
        int v57[7];

        a1[343] = 1;
        if ( *(unsigned int *)a2 )
        {
            v32 = a1[55] && a1[41] > 0x10u;
            width = *(unsigned int *)(a2 + 20);
            height = *(unsigned int *)(a2 + 24);
            if ( *(unsigned int *)(a2 + 48) )
            {
                v33 = 0;
            }
            else
            {
                glGenTextures(1, (GLuint *)(a2 + 48));
                v33 = 1;
            }
            glBindTexture(0xDE1u, *(unsigned int *)(a2 + 48));
            glTexParameteri(0xDE1u, 0x2800u, dword_A7F220[*(_BYTE *)(a2 + 32) & 3]);
            glTexParameteri(0xDE1u, 0x2801u, dword_A7F210[*(_BYTE *)(a2 + 32) & 3]);
            glTexParameteri(0xDE1u, 0x2802u, (*(_BYTE *)(a2 + 32) & 4) == 0 ? 33071 : 10497);
            glTexParameteri(0xDE1u, 0x2803u, (*(_BYTE *)(a2 + 32) & 8) == 0 ? 33071 : 10497);
            v31 = *(_BYTE *)(a2 + 32);
            if ( (v31 & 3u) > 1 || (v31 & 0x10) != 0 )
            {
                v2 = *(unsigned int *)(a2 + 20);
                v3 = *(unsigned int *)(a2 + 24);
                v4 = v3;
                if ( v2 > v3 )
                    v4 = *(unsigned int *)(a2 + 20);
                v36 = 1;
                while ( v4 != 1 )
                {
                    v4 >>= 1;
                    ++v36;
                }
                v5 = a1[53];
                if ( v36 - 1 <= v5 )
                    v5 = v36 - 1;
                v34 = v5;
                width >>= v5;
                height >>= v5;
                v6 = v5 + 1;
                if ( (v31 & 0x10) == 0 )
                    v6 = v36;
                v35 = v6;
            }
            else
            {
                v34 = 0;
                v35 = 1;
                v2 = *(unsigned int *)(a2 + 20);
                v3 = *(unsigned int *)(a2 + 24);
            }
            (*(void ( **)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int *, int *))(a2 + 40))(
                    0,
                    v2,
                    v3,
                    0,
                    *(unsigned int *)(a2 + 36),
                    &v56,
                    v57);
            v7 = 4 * height * width;
            if ( a1[546] < v7 )
            {
                v8 = a1[545];
                if ( v8 )
                    sub_B766(v8);
                a1[546] = v7;
                a1[545] = sub_B3FE(
                        v7,
                        "/Volumes/F1/usrbuild/xb/build/War3x_B6401/War3/Source/Mac/../../../Engine/Source/Gx/CGxDeviceOpenGL/CGxOglTexture.cpp",
                        339,
                        0);
            }
            pixels = (unsigned int *)a1[545];
            for ( level = 0; ; ++level )
            {
                v54 = level + v34;
                if ( v35 - v34 == level )
                    break;
                (*(void ( **)(int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int *, int *))(a2 + 40))(
                        1,
                        width,
                        height,
                        v54,
                        *(unsigned int *)(a2 + 36),
                        &v56,
                        v57);
                if ( (*(_BYTE *)(a2 + 32) & 0x20) != 0 )
                    v41 = *(unsigned int *)(a2 + 28);
                else
                    v41 = 0;
                v9 = dword_A7F200[*(unsigned int *)(a2 + 28)];
                if ( v9 == 32856 || v32 )
                {
                    if ( v41 )
                    {
                        v51 = (_WORD *)v57[0];
                        v49 = 2 * ((v56 >> 1) - width);
                        v22 = pixels;
                        for ( i = 0; height != i; ++i )
                        {
                            for ( j = 0; width != j; ++j )
                            {
                                *v22++ = (*v51 >> 4) & 0xF0 | ((*v51 & 0xF0) << 8) | ((unsigned __int16)*v51 << 20) & 0xF00000 | ((unsigned __int16)*v51 << 16) & 0xF0000000;
                                ++v51;
                            }
                            v51 = (_WORD *)((char *)v51 + v49);
                        }
                    }
                    else
                    {
                        v19 = (unsigned __int8 *)v57[0];
                        v48 = 4 * ((v56 >> 2) - width);
                        v20 = (int *)pixels;
                        for ( k = 0; height != k; ++k )
                        {
                            for ( l = 0; width != l; ++l )
                            {
                                *v20++ = v19[2] | (v19[1] << 8) | (*v19 << 16) | (v19[3] << 24);
                                v19 += 4;
                            }
                            v19 += v48;
                        }
                    }
                    format = 6408;
                    v13 = 5121;
                }
                else
                {
                    v10 = pixels;
                    if ( v41 )
                    {
                        v17 = (_WORD *)v57[0];
                        v42 = 2 * ((v56 >> 1) - width);
                        for ( m = 0; height > m; ++m )
                        {
                            for ( n = 0; width > n; ++n )
                            {
                                *(_WORD *)v10 = (*v17 >> 12) | (16 * *v17);
                                v10 = (unsigned int *)((char *)v10 + 2);
                                ++v17;
                            }
                            v17 = (_WORD *)((char *)v17 + v42);
                        }
                    }
                    else
                    {
                        v46 = (unsigned int *)v57[0];
                        v11 = (v56 >> 2) - width;
                        switch ( v9 )
                        {
                            case 32854:
                                for ( ii = 0; height > ii; ++ii )
                                {
                                    for ( jj = 0; width > jj; ++jj )
                                    {
                                        *(_WORD *)v10 = (*v46 >> 8) & 0xF000 | (*v46 >> 4) & 0xF00 | (*v46 >> 28) | *v46 & 0xF0;
                                        v10 = (unsigned int *)((char *)v10 + 2);
                                        ++v46;
                                    }
                                    v46 += v11;
                                }
                                break;
                            case 32855:
                                for ( kk = 0; height > kk; ++kk )
                                {
                                    for ( ll = 0; width > ll; ++ll )
                                    {
                                        *(_WORD *)v10 = (*v46 >> 8) & 0xF800 | (*v46 >> 5) & 0x7C0 | (*v46 >> 31) | (*v46 >> 2) & 0x3E;
                                        v10 = (unsigned int *)((char *)v10 + 2);
                                        ++v46;
                                    }
                                    v46 += v11;
                                }
                                break;
                            case 32848:
                                for ( mm = 0; height > mm; ++mm )
                                {
                                    for ( nn = 0; width > nn; ++nn )
                                    {
                                        *(_WORD *)v10 = (*v46 >> 8) & 0xF800 | (*v46 >> 5) & 0x7E0 | (*v46 >> 3) & 0x1F;
                                        v10 = (unsigned int *)((char *)v10 + 2);
                                        ++v46;
                                    }
                                    v46 += v11;
                                }
                                break;
                            default:
                                sub_71BA9C("Invalid case: %s=%u", "dstFormat", v9);
                                break;
                        }
                    }
                    v12 = *(unsigned int *)(a2 + 28);
                    format = dword_A7F1F0[v12];
                    v13 = dword_A7F1E0[v12];
                }
                if ( v41 )
                    v24 = v56 >> 1;
                else
                    v24 = v56 >> 2;
                glPixelStorei(0xCF2u, v24);
                if ( v33 )
                {
                    v25 = dword_A7F200[*(unsigned int *)(a2 + 28)];
                    if ( v32 && !v41 )
                        v25 = 6408;
                    glTexImage2D(0xDE1u, level, v25, width, height, 0, format, v13, pixels);
                }
                else
                {
                    v26 = (*(int *)(a2 + 12) >> v54) + 1;
                    v27 = (*(int *)(a2 + 16) >> v54) + 1;
                    if ( v26 >= (int)height )
                        v26 = height;
                    if ( v27 >= (int)width )
                        v27 = width;
                    glTexSubImage2D(
                            0xDE1u,
                            level,
                            *(int *)(a2 + 8) >> v54,
                            *(int *)(a2 + 4) >> v54,
                            v27 - (*(int *)(a2 + 8) >> v54),
                            v26 - (*(int *)(a2 + 4) >> v54),
                            format,
                            v13,
                            pixels);
                }
                v28 = 1;
                v29 = width >> 1;
                if ( !(width >> 1) )
                    v29 = 1;
                width = v29;
                heighta = height >> 1;
                if ( heighta )
                    v28 = heighta;
                height = v28;
            }
            (*(void ( **)(int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int *, int *))(a2 + 40))(
                    2,
                    *(unsigned int *)(a2 + 20),
                    *(unsigned int *)(a2 + 24),
                    0,
                    *(unsigned int *)(a2 + 36),
                    &v56,
                    v57);
        }
        a1[343] = 0;
        return ITexMarkAsUpdated((int)a1, (unsigned int *)a2);
    }

    virtual void  vfunc_CGxDeviceOpenGl_2(int a1, int a2)
    {
        const NTempest::CImVector *v2;
        const NTempest::CImVector *v3;
        GLfloat params;
        float v5;
        float v6;
        float v7;
        NTempest::CImVector v8[3];

        v2 = *(const NTempest::CImVector **)(a1 + 1324);
        v3 = &v2[5 * a2];
        if ( a2 == 1 )
        {
            NTempest::CImVector::Set(v8, v3);
            params = (float)(unsigned __int8)v8[0].r * 0.0039215689;
            v5 = (float)(unsigned __int8)v8[0].g * 0.0039215689;
            v6 = (float)(unsigned __int8)v8[0].b * 0.0039215689;
            v7 = (float)(unsigned __int8)v8[0].a * 0.0039215689;
            glMaterialfv(0x408u, 0x1602u, &params);
        }
        else if ( a2 > 1 )
        {
            if ( a2 == 2 )
            {
                NTempest::CImVector::Set(v8, v2 + 10);
                params = (float)(unsigned __int8)v8[0].r * 0.0039215689;
                v5 = (float)(unsigned __int8)v8[0].g * 0.0039215689;
                v6 = (float)(unsigned __int8)v8[0].b * 0.0039215689;
                v7 = (float)(unsigned __int8)v8[0].a * 0.0039215689;
                glMaterialfv(0x408u, 0x1600u, &params);
            }
            else if ( a2 == 3 )
            {
                if ( *v3 )
                    glEnable(0xBA1u);
                else
                    glDisable(0xBA1u);
            }
        }
        else if ( !a2 )
        {
            if ( *(float *)v3 == 0.0 )
            {
                glDisable(0x8037u);
            }
            else
            {
                glPolygonOffset(*(float *)v3 * -16.0, -1.0);
                glEnable(0x8037u);
            }
        }
    }

    virtual int  vfunc_CGxDeviceOpenGl_3(unsigned int *a1)
    {
        int v1;
        int v2;

        *a1 = off_E804E8;
        v1 = a1[535];
        if ( v1 )
            sub_B766(v1);
        v2 = a1[545];
        if ( v2 )
            sub_B766(v2);
        if ( a1[350] )
            vfunc_CGxDeviceOpenGl_6(a1);
        TSFixedArray<unsigned short,TSCD<unsigned short>>::~TSFixedArray(a1 + 537);
        TSFixedArray<NTempest::C2Vector,TSCD<NTempest::C2Vector>>::~TSFixedArray(a1 + 381);
        TSFixedArray<NTempest::C2Vector,TSCD<NTempest::C2Vector>>::~TSFixedArray(a1 + 378);
        TSFixedArray<NTempest::CImVector,TSCD<NTempest::CImVector>>::~TSFixedArray(a1 + 375);
        TSFixedArray<NTempest::C3Vector,TSCD<NTempest::C3Vector>>::~TSFixedArray((TSFixedArray *)a1 + 124);
        TSFixedArray<NTempest::C3Vector,TSCD<NTempest::C3Vector>>::~TSFixedArray((TSFixedArray *)a1 + 123);
        return sub_2CD07E(a1);
    }

    virtual int  vfunc_CGxDeviceOpenGl_4(TRefCnt *a1)
    {
        int v1;
        int v2;

        a1->vptr = (vtable_TRefCnt_struct *)off_E804E8;
        v1 = a1[267].cnt;
        if ( v1 )
            sub_B766(v1);
        v2 = a1[272].cnt;
        if ( v2 )
            sub_B766(v2);
        if ( a1[175].vptr )
            vfunc_CGxDeviceOpenGl_6(a1);
        TSFixedArray<unsigned short,TSCD<unsigned short>>::~TSFixedArray(&a1[268].cnt);
        TSFixedArray<NTempest::C2Vector,TSCD<NTempest::C2Vector>>::~TSFixedArray(&a1[190].cnt);
        TSFixedArray<NTempest::C2Vector,TSCD<NTempest::C2Vector>>::~TSFixedArray(&a1[189]);
        TSFixedArray<NTempest::CImVector,TSCD<NTempest::CImVector>>::~TSFixedArray(&a1[187].cnt);
        TSFixedArray<NTempest::C3Vector,TSCD<NTempest::C3Vector>>::~TSFixedArray((TSFixedArray *)&a1[186]);
        TSFixedArray<NTempest::C3Vector,TSCD<NTempest::C3Vector>>::~TSFixedArray((TSFixedArray *)&a1[184].cnt);
        sub_2CD07E(a1);
        return sub_29559C(a1);
    }

    virtual int  vfunc_CGxDeviceOpenGl_5(unsigned int *a1, int a2, unsigned int *a3, int a4, int a5)
    {
        int v5;
        int v6;
        int result;
        int v8;
        int v9;
        int v10;
        int v11[18];

        vfunc_CGxDevice_5(a1, a2, a3);
        a1[368] = a5;
        v8 = sub_11082(0);
        if ( a3 )
        {
            v9 = a3[2];
            v10 = a3[3];
        }
        else
        {
            v9 = dword_D6BAAC;
            v10 = dword_D6BAA8;
        }
        if ( !a5
             && (memset(v11, 0, 0x30u),
                v11[0] = 48,
                v11[1] = 32,
                v11[2] = (int)sub_A93A6,
                v11[5] = v8,
                v11[10] = (int)"GxWindowClassOpenGl",
                (unsigned __int16)sub_28FCA0(v11)) )
        {
            v5 = sub_290008(sub_40000, "GxWindowClassOpenGl", "Gx", -2030043136, 0, 0, v9, v10, 0, 0, v8, a1);
        }
        else
        {
            v5 = 0;
        }
        a1[350] = v5;
        if ( v5 )
            sub_28F550(v5, 1);
        if ( sub_A9AB4(a1) )
        {
            v6 = unk_F6BD0C;
            if ( unk_F6BD0C >= 3u )
                v6 = 2;
            a1[43] = v6;
            a1[44] = 1;
            a1[45] = 1;
            a1[46] = 512;
            a1[47] = 0;
            a1[48] = 1;
            dword_F30E98 = a2;
            result = 1;
        }
        else
        {
            (*(void ( **)(unsigned int *))(*a1 + 20))(a1);
            result = 0;
        }
        return result;
    }

    virtual int  vfunc_CGxDeviceOpenGl_6(unsigned int *a1)
    {
        int result;

        vfunc_CGxDevice_6(a1);
        dword_F30E98 = 0;
        result = a1[350];
        if ( result )
        {
            sub_28F9AE(a1[350]);
            sub_11082(0);
            result = sub_28FE9A("GxWindowClassOpenGl");
            a1[350] = 0;
        }
        return result;
    }

    virtual int  vfunc_CGxDeviceOpenGl_7(unsigned int *a1, char *a2)
    {
        char *v2;
        char v4[32];

        v2 = a2;
        memset(v4, 0, 0x18u);
        a1[351] = a1[37];
        a1[352] = a1[38];
        a1[353] = a1[39];
        a1[354] = a1[40];
        a1[355] = a1[41];
        a1[356] = a1[42];
        if ( !a2 )
            v2 = v4;
        a1[37] = *(unsigned int *)v2;
        a1[38] = *((unsigned int *)v2 + 1);
        a1[39] = *((unsigned int *)v2 + 2);
        a1[40] = *((unsigned int *)v2 + 3);
        a1[41] = *((unsigned int *)v2 + 4);
        a1[42] = *((unsigned int *)v2 + 5);
        a1[357] = 1;
        return 1;
    }

    virtual int  vfunc_CGxDeviceOpenGl_8(int a1, int a2)
    {
        vfunc_CGxDevice_8(a1, a2);
        return sub_2E6156(a1);
    }

    virtual int  vfunc_CGxDeviceOpenGl_9(int a1, int a2)
    {
        dword_D6BAA0 = a2;
        return sub_2E285A(a2);
    }

    virtual int  vfunc_CGxDeviceOpenGl_10(int a1, int a2)
    {
        vfunc_CGxDevice_10(a1, a2);
        return sub_2E6156(a1);
    }

    virtual int  vfunc_CGxDeviceOpenGl_11(int a1)
    {
        return *(unsigned int *)(a1 + 1400);
    }

    virtual int  vfunc_CGxDeviceOpenGl_14(int a1, int a2, char *__src, int a4)
    {
        int v4;
        int v5;

        sub_2E282A();
        sub_A8C88(a1);
        v4 = sub_A8680(*(unsigned int *)(a1 + 148));
        sub_2E19F8(__src, a4, v4);
        sub_2E1808();
        v5 = sub_A9AB4(a1);
        sub_2E27FE();
        return v5;
    }

    virtual int  vfunc_CGxDeviceOpenGl_15(unsigned int *a1, unsigned int *a2)
    {
        int result;

        *a2 = a1[541];
        a2[1] = a1[542];
        a2[2] = a1[543];
        result = a1[544];
        a2[3] = result;
        return result;
    }

    virtual int  vfunc_CGxDeviceOpenGl_16(int a1, int a2)
    {
        int v2;
        int result;
        float v4;
        float v5;
        float v6;
        float v7;
        float v8;
        float v9;
        __int16 v10[4];
        int v11;
        __int16 v12;
        __int16 v13;

        v12 = 0;
        v13 = 0;
        v2 = *(unsigned int *)(a1 + 1448);
        if ( v2 )
        {
            v4 = (float)*(__int16 *)(*(unsigned int *)v2 + 36);
            v5 = (float)*(__int16 *)(*(unsigned int *)v2 + 38);
            v6 = (float)*(__int16 *)(*(unsigned int *)v2 + 40);
            *(float *)a2 = (float)*(__int16 *)(*(unsigned int *)v2 + 34);
            *(float *)(a2 + 4) = v4;
            *(float *)(a2 + 8) = v5;
            result = LODWORD(v6);
        }
        else if ( *(unsigned int *)(a1 + 1432) )
        {
            GetPort(&v11);
            SetPort(*(unsigned int *)(a1 + 1432));
            LocalToGlobal(&v12);
            SetPort(v11);
            GetPortBounds(*(unsigned int *)(a1 + 1432), v10);
            v7 = (float)(v10[1] + v13);
            v8 = (float)(v12 + v10[2]);
            v9 = (float)(v13 + v10[3]);
            *(float *)a2 = (float)(v10[0] + v12);
            *(float *)(a2 + 4) = v7;
            *(float *)(a2 + 8) = v8;
            result = LODWORD(v9);
        }
        else
        {
            *(unsigned int *)a2 = 0;
            *(unsigned int *)(a2 + 4) = 0;
            *(unsigned int *)(a2 + 8) = 0;
            result = 0;
        }
        *(unsigned int *)(a2 + 12) = result;
        return result;
    }

    virtual _BOOL4  vfunc_CGxDeviceOpenGl_17(unsigned int *a1)
    {
        if ( a1[366] )
            sub_A82DA(0, 0, 0, 0);
        return !a1[367] || a1[365];
    }

    virtual int  vfunc_CGxDeviceOpenGl_19(int a1, int a2, int a3)
    {
        int v4;
        NTempest::CImVector v5;

        vfunc_CGxDevice_19();
        NTempest::CImVector::Set(&v5, (const NTempest::CImVector *)(a1 + 224));
        v4 = sub_2E4D78(a1, 1);
        glClearColor(
                (float)(unsigned __int8)v5.r * 0.0039215689,
                (float)(unsigned __int8)v5.g * 0.0039215689,
                (float)(unsigned __int8)v5.b * 0.0039215689,
                (float)(unsigned __int8)v5.a * 0.0039215689);
        glClear((a3 != 0 ? 0x100 : 0) | (a2 != 0 ? 0x4000 : 0));
        return sub_2E4D78(a1, v4);
    }

    virtual int  vfunc_CGxDeviceOpenGl_20(int a1)
    {
        bool v1;
        __m128 v2;
        __m128 v3;
        __m128 v4;
        __m128 v5;
        __m128 v6;
        __m128 v7;
        int v8;
        char *v9;
        char *v10;
        int i;
        int v12;
        int v14;
        int v15;
        int v16;
        int v17;
        unsigned __int32 v18;
        void *__dst;
        int __len;
        char *__src;
        int j;

        v1 = *(unsigned int *)(a1 + 1376) || *(unsigned int *)(a1 + 1460);
        vfunc_CGxDevice_20((unsigned int *)a1);
        if ( v1 )
        {
            v2 = (__m128)*(unsigned int *)(a1 + 2176);
            v2.f32[0] = fmaxf(v2.f32[0], 0.0);
            v3.i32[0] = 1325400064;
            v4 = _mm_cmple_ss(v3, v2);
            v5.i32[0] = 1333788672;
            v18 = _mm_or_si128(
                    _mm_add_epi32(
                            _mm_cvttps_epi32(_mm_sub_ps(v2, _mm_and_ps(v4, (__m128)0x4F000000u))),
                            _mm_slli_epi32((__m128i)v4, 0x1Fu)),
                    (__m128i)_mm_cmple_ss(v5, v2)).u32[0];
            *(unsigned int *)(a1 + 1380) = v18;
            v6 = (__m128)*(unsigned int *)(a1 + 2172);
            v6.f32[0] = fmaxf(v6.f32[0], 0.0);
            v4.i32[0] = 1325400064;
            v7 = _mm_cmple_ss(v4, v6);
            v2.i32[0] = 1333788672;
            *(unsigned int *)(a1 + 1384) = _mm_or_si128(
                    _mm_add_epi32(
                            _mm_cvttps_epi32(_mm_sub_ps(v6, _mm_and_ps((__m128)0x4F000000u, v7))),
                            _mm_slli_epi32((__m128i)v7, 0x1Fu)),
                    (__m128i)_mm_cmple_ss(v2, v6)).u32[0];
            __len = 4 * v18;
            v8 = *(unsigned int *)(a1 + 1388);
            if ( v8 )
                sub_B766(v8);
            *(unsigned int *)(a1 + 1388) = sub_B3FE(
                    *(unsigned int *)(a1 + 1384) * __len,
                    "/Volumes/F1/usrbuild/xb/build/War3x_B6401/War3/Source/Mac/../../../Engine/Source/Gx/CGxDe"
                    "viceOpenGL/CGxOglScene.cpp",
                    127,
                    0);
            __dst = (void *)sub_B3FE(
                    __len,
                    "/Volumes/F1/usrbuild/xb/build/War3x_B6401/War3/Source/Mac/../../../Engine/Source/Gx/CGxDeviceOpenG"
                    "L/CGxOglScene.cpp",
                    128,
                    0);
            glReadBuffer(0x405u);
            glReadPixels(0, 0, *(unsigned int *)(a1 + 1380), *(unsigned int *)(a1 + 1384), 0x80E1u, 0x1401u, *(GLvoid **)(a1 + 1388));
            __src = *(char **)(a1 + 1388);
            v9 = &__src[*(unsigned int *)(a1 + 1380) * (4 * *(unsigned int *)(a1 + 1384) - 4)];
            v10 = __src;
            for ( i = 0; ; ++i )
            {
                v10 += 4;
                if ( i == *(unsigned int *)(a1 + 1384) * *(unsigned int *)(a1 + 1380) )
                    break;
                *(v10 - 1) = -1;
            }
            for ( j = 0; j != *(unsigned int *)(a1 + 1384) >> 1; ++j )
            {
                if ( __len > 0 )
                {
                    memmove(__dst, __src, __len);
                    memmove(__src, v9, __len);
                    memmove(v9, __dst, __len);
                }
                v12 = 4 * *(unsigned int *)(a1 + 1380);
                __src += v12;
                v9 -= v12;
            }
            v16 = 0;
            v14 = 163;
            sub_B766((int)__dst);
        }
        if ( *(unsigned int *)(a1 + 1468) )
        {
            if ( *(unsigned int *)(a1 + 1460) )
                sub_A82DA(1, *(unsigned int *)(a1 + 1388), *(unsigned int *)(a1 + 1380), *(unsigned int *)(a1 + 1384));
            sub_A820E();
        }
        else
        {
            aglSwapBuffers(*(AGLContext *)(a1 + 1436));
        }
        if ( *(unsigned int *)(a1 + 1428) )
        {
            vfunc_CGxDevice_7((unsigned int *)a1, (unsigned int *)(a1 + 148));
            sub_A8C88(a1);
            sub_A88B4(a1, a1 + 148, v14, v16);
            if ( !sub_A9AB4(a1) )
            {
                vfunc_CGxDevice_7((unsigned int *)a1, (unsigned int *)(a1 + 1404));
                sub_A88B4(a1, a1 + 1404, v15, v17);
                if ( !sub_A9AB4(a1) )
                    sub_71BA9C("Sorry, an error occurred while setting up OpenGL.");
            }
            *(unsigned int *)(a1 + 1428) = 0;
        }
        return sub_625C96(a1);
    }

    virtual void  vfunc_CGxDeviceOpenGl_21(unsigned int *a1, __int64 a2, __int64 a3, __int64 a4)
    {
        __m128 v4;
        __m128 v5;
        __m128 v6;
        __m128 v7;
        __m128 v8;
        __m128 v9;
        __m128 v10;
        __m128 v11;
        __m128 v12;
        __m128 v13;
        __m128 v14;
        __m128 v15;
        unsigned __int32 v16;
        unsigned __int32 v17;
        unsigned __int32 y;
        unsigned __int32 x;

        vfunc_CGxDevice_21(a1, a2, SHIDWORD(a2), a3, SHIDWORD(a3), a4, SHIDWORD(a4));
        v4 = (__m128)(unsigned int)a1[544];
        v5 = (__m128)(unsigned int)a2;
        v5.f32[0] = *(float *)&a2 * v4.f32[0];
        v6 = v5;
        v6.f32[0] = fmaxf(*(float *)&a2 * v4.f32[0], 0.0);
        v7.i32[0] = 1325400064;
        v8 = _mm_cmple_ss(v7, v6);
        v5.i32[0] = 1333788672;
        x = _mm_or_si128(
                _mm_add_epi32(
                        _mm_cvttps_epi32(_mm_sub_ps(v6, _mm_and_ps(v8, (__m128)0x4F000000u))),
                        _mm_slli_epi32((__m128i)v8, 0x1Fu)),
                (__m128i)_mm_cmple_ss(v5, v6)).u32[0];
        v9 = (__m128)(unsigned int)a1[543];
        v10 = (__m128)(unsigned int)a3;
        v10.f32[0] = *(float *)&a3 * v9.f32[0];
        v11 = v10;
        v11.f32[0] = fmaxf(*(float *)&a3 * v9.f32[0], 0.0);
        v10.i32[0] = 1325400064;
        v12 = _mm_cmple_ss(v10, v11);
        v6.i32[0] = 1333788672;
        y = _mm_or_si128(
                _mm_add_epi32(
                        _mm_cvttps_epi32(_mm_sub_ps(v11, _mm_and_ps(v12, (__m128)0x4F000000u))),
                        _mm_slli_epi32((__m128i)v12, 0x1Fu)),
                (__m128i)_mm_cmple_ss(v6, v11)).u32[0];
        v9.f32[0] = fmaxf(v9.f32[0] * *((float *)&a3 + 1), 0.0);
        v12.i32[0] = 1325400064;
        v13 = _mm_cmple_ss(v12, v9);
        v11.i32[0] = 1333788672;
        v17 = _mm_or_si128(
                _mm_add_epi32(
                        _mm_cvttps_epi32(_mm_sub_ps(v9, _mm_and_ps(v13, (__m128)0x4F000000u))),
                        _mm_slli_epi32((__m128i)v13, 0x1Fu)),
                (__m128i)_mm_cmple_ss(v11, v9)).u32[0];
        v4.f32[0] = v4.f32[0] * *((float *)&a2 + 1);
        v14 = v4;
        v14.f32[0] = fmaxf(v4.f32[0], 0.0);
        v13.i32[0] = 1325400064;
        v15 = _mm_cmple_ss(v13, v14);
        v6.i32[0] = 1333788672;
        v16 = _mm_or_si128(
                _mm_add_epi32(
                        _mm_cvttps_epi32(_mm_sub_ps(v14, _mm_and_ps((__m128)0x4F000000u, v15))),
                        _mm_slli_epi32((__m128i)v15, 0x1Fu)),
                (__m128i)_mm_cmple_ss(v6, v14)).u32[0];
        glViewport(x, y, v16 - x, v17 - y);
        glDepthRange(*(float *)&a4, *((float *)&a4 + 1));
        glScissor(x, y, v16 - x, v17 - y);
    }

    virtual int  vfunc_CGxDeviceOpenGl_22(int a1, char *a2)
    {
        int result;

        result = memcmp(a2, (const char *)(a1 + 252), 64);
        if ( result )
        {
            vfunc_CGxDevice_22((unsigned int *)a1, a2);
            result = sub_626700(a1, a2);
        }
        return result;
    }

    virtual int  vfunc_CGxDeviceOpenGl_23(float *a1, float *a2)
    {
        int result;

        if ( *a2 != a1[412] || a2[4] != a1[416] || a2[8] != a1[420] || (result = sub_5D8106(a2, a1 + 412)) != 0 )
        {
            vfunc_CGxDevice_23(a1, a2);
            *((unsigned int *)a1 + 540) = 1;
            a1[412] = *a2;
            a1[413] = a2[1];
            a1[414] = a2[2];
            a1[415] = a2[3];
            a1[416] = a2[4];
            a1[417] = a2[5];
            a1[418] = a2[6];
            a1[419] = a2[7];
            a1[420] = a2[8];
            a1[421] = a2[9];
            a1[422] = a2[10];
            a1[423] = a2[11];
            result = sub_5D8048(a2, a1 + 387);
            *((unsigned int *)a1 + 424) = result;
        }
        return result;
    }

    virtual int  vfunc_CGxDeviceOpenGl_24(float *a1, float *a2)
    {
        int result;

        if ( *a2 != a1[399] || a2[4] != a1[403] || a2[8] != a1[407] || (result = sub_5D8106(a2, a1 + 399)) != 0 )
        {
            vfunc_CGxDevice_24(a1, a2);
            *((unsigned int *)a1 + 540) = 1;
            a1[399] = *a2;
            a1[400] = a2[1];
            a1[401] = a2[2];
            a1[402] = a2[3];
            a1[403] = a2[4];
            a1[404] = a2[5];
            a1[405] = a2[6];
            a1[406] = a2[7];
            a1[407] = a2[8];
            a1[408] = a2[9];
            a1[409] = a2[10];
            a1[410] = a2[11];
            result = sub_5D8048(a2, a1 + 387);
            *((unsigned int *)a1 + 411) = result;
        }
        return result;
    }

    virtual void  vfunc_CGxDeviceOpenGl_26(int a1, int a2, int *a3)
    {
        vfunc_CGxDevice_26(a1, a2, a3);
        if ( *(unsigned int *)(a1 + 172) > 1u )
        {
            glActiveTextureARB(a2 + 33984);
            glClientActiveTextureARB(a2 + 33984);
        }
        glMatrixMode(0x1702u);
        glLoadMatrixf((const GLfloat *)((a2 << 6) + a1 + 420));
    }

    virtual int  vfunc_CGxDeviceOpenGl_29(int a1, unsigned int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14)
    {
        int v14;
        int v15;
        int v16;
        unsigned int v17;
        int v18;
        int v19;
        int v20;
        int result;

        vfunc_CGxDevice_29(a1, a2);
        if ( a2 > *(unsigned int *)(a1 + 1480) )
        {
            TSFixedArray<NTempest::C3Vector,TSCD<NTempest::C3Vector>>::SetCount(a1 + 1476, a2);
            TSFixedArray<NTempest::C3Vector,TSCD<NTempest::C3Vector>>::SetCount(a1 + 1488, a2);
            TSFixedArray<NTempest::CImVector,TSCD<NTempest::CImVector>>::SetCount(a1 + 1500, a2);
            TSFixedArray<NTempest::C2Vector,TSCD<NTempest::C2Vector>>::SetCount(a1 + 1512, a2);
            TSFixedArray<NTempest::C2Vector,TSCD<NTempest::C2Vector>>::SetCount(a1 + 1524, a2);
        }
        dword_F36E60 = a2;
        dword_F36E90 = a3;
        dword_F36E8C = a4;
        dword_F36E88 = a5;
        dword_F36E84 = a6;
        dword_F36E80 = a7;
        dword_F36E7C = a8;
        dword_F36E78 = a9;
        dword_F36E74 = a10;
        dword_F36E6C = a11;
        dword_F36E64 = a12;
        dword_F36E70 = a13;
        dword_F36E68 = a14;
        if ( !a5 )
            dword_F36E88 = (int)&dword_F36E4C;
        if ( !a7 )
            dword_F36E80 = (int)&unk_F36E40;
        if ( !dword_F36E6C )
            dword_F36E6C = (int)&dword_F36E44;
        if ( !dword_F36E70 )
            dword_F36E70 = (int)&dword_F36E44;
        *(_BYTE *)(a1 + 2091) = *(unsigned int *)(a1 + 2092) != 0;
        if ( *(_BYTE *)(a1 + 2091) )
        {
            *(unsigned int *)(a1 + 2100) = 44 * a2 + 96;
            v14 = sub_2E31FC(*(unsigned int *)(*(unsigned int *)(a1 + 2092) + 4 * (*(unsigned int *)(a1 + 548) != 0) + 36), 44 * a2 + 96);
            v15 = v14;
            *(unsigned int *)(a1 + 2096) = v14;
            if ( v14 )
            {
                v16 = dword_F36E60;
                *(unsigned int *)(a1 + 2104) = v14;
                v17 = (12 * v16 + 31) & 0xFFFFFFE0;
                v18 = v17 + v15;
                *(unsigned int *)(a1 + 2108) = v18;
                v19 = v18 + v17;
                *(unsigned int *)(a1 + 2112) = v19;
                v20 = v19 + 4 * v16;
                *(unsigned int *)(a1 + 2116) = v20;
                *(unsigned int *)(a1 + 2120) = v20 + 8 * v16;
            }
            else
            {
                *(_BYTE *)(a1 + 2091) = 0;
            }
        }
        else
        {
            *(unsigned int *)(a1 + 2096) = 0;
            *(unsigned int *)(a1 + 2100) = 0;
        }
        if ( !*(_BYTE *)(a1 + 2091) )
        {
            *(unsigned int *)(a1 + 2104) = *(unsigned int *)(a1 + 1484);
            *(unsigned int *)(a1 + 2108) = *(unsigned int *)(a1 + 1496);
            *(unsigned int *)(a1 + 2112) = *(unsigned int *)(a1 + 1508);
            *(unsigned int *)(a1 + 2116) = *(unsigned int *)(a1 + 1520);
            *(unsigned int *)(a1 + 2120) = *(unsigned int *)(a1 + 1532);
        }
        result = sub_2E4078(a1);
        *(unsigned int *)(a1 + 2124) = 0;
        if ( !*(_BYTE *)(a1 + 2091) )
        {
            result = glLockArraysEXT(0, dword_F36E60, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
            *(unsigned int *)(a1 + 2124) = 1;
        }
        return result;
    }

    virtual void  vfunc_CGxDeviceOpenGl_30(int a1, int a2, int a3, void *__src)
    {
        int v4;
        char v5;
        int v6;
        signed __int32 v7;
        unsigned int v8;
        void *v9;
        signed __int32 v10;
        int v11;
        int i;
        int v13;
        int v14;
        int v15;

        vfunc_CGxDevice_30(a1, a2, a3);
        *(unsigned int *)(a1 + 1536) = a2;
        *(unsigned int *)(a1 + 1540) = a3;
        *(unsigned int *)(a1 + 1544) = __src;
        if ( !*(_BYTE *)(a1 + 2091) )
        {
            LABEL_24:
            *(unsigned int *)(a1 + 2136) = __src;
            return;
        }
        v4 = *(unsigned int *)(a1 + 2092);
        if ( *(unsigned int *)(v4 + 52) && (a3 & 1) != 0 )
        {
            if ( a2 != 3 )
            {
                *(_BYTE *)(a1 + 2091) = 0;
                LABEL_9:
                v13 = 0;
                v14 = 0;
                v15 = 0;
                goto LABEL_10;
            }
            v13 = 1;
            v14 = 3;
            v15 = 3;
        }
        else
        {
            v13 = 0;
            v14 = 0;
            v15 = 0;
        }
        v5 = sub_2E3376(v4, *(unsigned int *)(a1 + 1540) + v15, *(unsigned int *)(a1 + 1536), __src);
        *(_BYTE *)(a1 + 2091) = v5;
        if ( !v5 )
            goto LABEL_9;
        LABEL_10:
        v6 = v15 + a3;
        *(unsigned int *)(a1 + 1540) = v15 + a3;
        if ( !*(_BYTE *)(a1 + 2091) )
            goto LABEL_24;
        v7 = 2 * v6;
        v8 = (2 * v6 + 31) & 0xFFFFFFE0;
        *(unsigned int *)(a1 + 2132) = v8;
        v9 = (void *)sub_2E31FC(*(unsigned int *)(*(unsigned int *)(a1 + 2092) + 44), v8);
        *(unsigned int *)(a1 + 2128) = v9;
        if ( v9 )
        {
            *(unsigned int *)(a1 + 2136) = v9;
            if ( v13 )
            {
                v10 = v7 - 2 * v14;
                if ( v10 > 0 )
                    memmove(v9, __src, v10);
                v11 = *(unsigned int *)(a1 + 2136) + 2 * *(unsigned int *)(a1 + 1540) - 2 * v15;
                for ( i = 0; v14 > i; *(_WORD *)(v11 + 2 * i++) = **(_WORD **)(a1 + 2136) )
                    ;
            }
            else if ( v7 > 0 )
            {
                memmove(v9, __src, v7);
            }
            glFlushVertexArrayRangeAPPLE(*(unsigned int *)(a1 + 2132), *(const GLvoid **)(a1 + 2128));
        }
        else
        {
            *(_BYTE *)(a1 + 2091) = 0;
        }
        if ( !*(_BYTE *)(a1 + 2091) )
            goto LABEL_24;
    }

    virtual void  vfunc_CGxDeviceOpenGl_31(int a1)
    {
        int v1;

        vfunc_CGxDevice_31((unsigned int *)a1);
        sub_2E5A4E(a1);
        if ( *(_BYTE *)(a1 + 2091) )
        {
            sub_2E3018(*(unsigned int *)(a1 + 2092), 1);
        }
        else
        {
            v1 = *(unsigned int *)(a1 + 2092);
            if ( v1 )
                sub_2E3018(v1, 0);
        }
        glDrawElements(dword_D6E3C0[*(unsigned int *)(a1 + 1536)], *(unsigned int *)(a1 + 1540), 0x1403u, *(const GLvoid **)(a1 + 2136));
        if ( (*(_BYTE *)(a1 + 1284) & 0x20) == 0 )
            glFinish();
    }

    virtual void vfunc_CGxDeviceOpenGl_32()
    {
        vfunc_CGxDevice_32();
    }

    virtual int  vfunc_CGxDeviceOpenGl_33(int a1)
    {
        int result;

        vfunc_CGxDevice_33();
        result = *(unsigned int *)(a1 + 2124);
        if ( result )
        {
            result = glUnlockArraysEXT(a1);
            *(unsigned int *)(a1 + 2124) = 0;
        }
        return result;
    }

    virtual int  vfunc_CGxDeviceOpenGl_34(unsigned int *a1, int a2, int a3, unsigned int a4, unsigned int *a5, unsigned int *a6)
    {
        unsigned int v6;
        int v7;

        vfunc_CGxDevice_34(a1, a2, a3, a4);
        *a5 = 0;
        *a6 = 0;
        dword_F36E60 = a2;
        a1[384] = a3;
        a1[385] = a4;
        v6 = a1[536];
        if ( v6 < a2 * sub_AAD54(a1[138]) )
        {
            a1[536] = sub_AAD54(a1[138]) * a2;
            v7 = a1[535];
            if ( v7 )
                sub_B766(v7);
            a1[535] = sub_B3FE(
                    a1[536],
                    "/Volumes/F1/usrbuild/xb/build/War3x_B6401/War3/Source/Mac/../../../Engine/Source/Gx/CGxDeviceOpenGL/CGxOglPrim_VXR.cpp",
                    1384,
                    0);
        }
        if ( a4 > a1[538] )
            TSFixedArray<unsigned short,TSCD<unsigned short>>::SetCount(a1 + 537, a4);
        *a5 = a1[535];
        *a6 = a1[539];
        return 1;
    }

    virtual void  vfunc_CGxDeviceOpenGl_35(int a1)
    {
        const NTempest::CImVector *v1;
        int i;
        int v3;
        int v4;
        int v5;
        NTempest::CImVector v6;

        vfunc_CGxDevice_35();
        sub_2E5A4E(a1);
        v1 = *(const NTempest::CImVector **)(a1 + 2140);
        v5 = dword_F36E60;
        for ( i = 0; v5 != i; ++i )
        {
            NTempest::CImVector::Set(&v6, v1 + 6);
            v1[6] = (const NTempest::CImVector)((unsigned __int8)v6.r | ((unsigned __int8)v6.g << 8) | ((unsigned __int8)v6.b << 16) | ((unsigned __int8)v6.a << 24));
            v1 += 9;
        }
        if ( *(unsigned int *)(a1 + 552) == 3 )
        {
            v3 = *(unsigned int *)(a1 + 2140);
            *(_BYTE *)(a1 + 2091) = 0;
            *(unsigned int *)(a1 + 2120) = 0;
            *(unsigned int *)(a1 + 2116) = v3 + 28;
            sub_2E3B58(a1, 1, 0);
            sub_2E3B58(a1, 0, 1);
            glVertexPointer(3, 0x1406u, 36, (const GLvoid *)v3);
            glNormalPointer(0x1406u, 36, (const GLvoid *)(v3 + 12));
            glColorPointer(4, 0x1401u, 36, (const GLvoid *)(v3 + 24));
            glTexCoordPointer(2, 0x1406u, 36, (const GLvoid *)(v3 + 28));
            glEnableClientState(0x8075u);
            glEnableClientState(0x8076u);
            glEnable(0xB57u);
            v4 = *(unsigned int *)(a1 + 2092);
            if ( v4 )
                sub_2E3018(v4, 0);
            glDrawElements(dword_D6E3C0[*(unsigned int *)(a1 + 1536)], *(unsigned int *)(a1 + 1540), 0x1403u, *(const GLvoid **)(a1 + 2156));
            if ( (*(_BYTE *)(a1 + 1284) & 0x20) == 0 )
                glFinish();
        }
    }

    virtual int  vfunc_CGxDeviceOpenGl_45(unsigned int *a1, int a2, int a3, int a4, char a5, int a6, int a7, unsigned int *a8)
    {
        int v8;

        v8 = vfunc_CGxDevice_45(a1, a2, a3, a4, a5, a6, a7, a8);
        if ( (*(int ( **)(unsigned int *))(*a1 + 64))(a1) && v8 )
            (*(void ( **)(unsigned int *, unsigned int))*a1)(a1, *a8);
        return v8;
    }

    virtual int  vfunc_CGxDeviceOpenGl_46(int a1, int a2)
    {
        glFinish();
        if ( *(unsigned int *)(a2 + 48) )
            glDeleteTextures(1, (const GLuint *)(a2 + 48));
        return vfunc_CGxDevice_46(a1, (TRefCnt *)a2);
    }

    virtual int  vfunc_CGxDeviceOpenGl_47(int a1)
    {
        return *(unsigned int *)(a1 + 1400);
    }

    virtual int  vfunc_CGxDeviceOpenGl_48(int a1)
    {
        int v1;
        TRefCnt *v2;
        int v4;
        int v5[7];

        if ( !dword_F30E7C )
            return OsOutputDebugString(" can't explore VXR support until app init complete");
        v5[0] = 1;
        v1 = sub_D4786();
        if ( v1 )
        {
            if ( sub_D4692(v1, "opengl.config", 1) )
            {
                OsOutputDebugString("Read opengl.config OK");
                sub_D4B9C(v1, "OPTIONS", "EnableVertexAcceleration", v5, 0);
                OsOutputDebugString("EnableVertexAcceleration = %d", v5[0]);
            }
            else
            {
                OsOutputDebugString("No opengl.config found");
            }
            sub_D382A(v1);
        }
        else
        {
            OsOutputDebugString("Create Profile failed");
        }
        if ( !v5[0] )
            return OsOutputDebugString(" deactivated VXR support (2)");
        if ( !dword_F6BD04 || !dword_F6BD00 )
            return OsOutputDebugString(" deactivated VXR support (1)");
        v4 = 0;
        v2 = (TRefCnt *)sub_295564(56);
        sub_2E387E(v2, dword_D6BAC0, &v4);
        *(unsigned int *)(a1 + 2092) = v2;
        if ( v4 )
            return OsOutputDebugString(" activated VXR support");
        if ( v2 )
        {
            sub_2E32FC(v2);
            sub_29559C(v2);
        }
        *(unsigned int *)(a1 + 2092) = 0;
        return OsOutputDebugString(" error activating VXR support");
    }
};


#endif //ENGINE_CGXDEVICEOPENGL_H
