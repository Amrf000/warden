//
// Created by liuyawu on 2019/5/10.
//

#ifndef ENGINE_CMATH_H
#define ENGINE_CMATH_H

namespace NTempest {


class CMath {
public:
    float * sincos_(CMath *this, float a2, float *a3)
    {
        long double v3;
        float *result;

        *(float *)LODWORD(a2) = sinf(*(float *)&this);
        v3 = cosf(*(float *)&this);
        result = a3;
        *a3 = v3;
        return result;
    }

    __int32  fint_n(CMath *this)
    {
        __m128 v1;
        __m128 v2;
        __m128 v3;
        __m128 v4;
        __int32 result;
        __m128 v6;
        __m128 v7;
        __m128 v8;
        __m128 v9;
        __m128 v10;

        v1 = (__m128)(unsigned int)this;
        if ( *(float *)&this <= 0.0 )
        {
            v6 = (__m128)0x3F000000u;
            v6.f32[0] = 0.5 - *(float *)&this;
            v7 = v6;
            v7.f32[0] = fmaxf(0.5 - *(float *)&this, 0.0);
            v8.i32[0] = 1325400064;
            v9 = _mm_cmple_ss(v8, v7);
            v10.i32[0] = 1333788672;
            result = -_mm_or_si128(
                    _mm_add_epi32(
                            _mm_cvttps_epi32(_mm_sub_ps(v7, _mm_and_ps((__m128)0x4F000000u, v9))),
                            _mm_slli_epi32((__m128i)v9, 0x1Fu)),
                    (__m128i)_mm_cmple_ss(v10, v7)).i32[0];
        }
        else
        {
            v1.f32[0] = fmaxf(*(float *)&this + 0.5, 0.0);
            v2.i32[0] = 1325400064;
            v3 = _mm_cmple_ss(v2, v1);
            v4.i32[0] = 1333788672;
            result = _mm_or_si128(
                    _mm_add_epi32(
                            _mm_cvttps_epi32(_mm_sub_ps(v1, _mm_and_ps((__m128)0x4F000000u, v3))),
                            _mm_slli_epi32((__m128i)v3, 0x1Fu)),
                    (__m128i)_mm_cmple_ss(v4, v1)).u32[0];
        }
        return result;
    }

    __int32  fint_mi(CMath *this)
    {
        __m128 v1;
        __m128 v2;
        __m128 v3;
        __m128 v4;
        __int32 result;
        __m128 v6;
        __m128 v7;
        __m128 v8;
        __m128 v9;
        __m128 v10;

        v1 = (__m128)(unsigned int)this;
        if ( *(float *)&this <= 0.0 )
        {
            v6 = (__m128)0x3F7FFF58u;
            v6.f32[0] = 0.99998999 - *(float *)&this;
            v7 = v6;
            v7.f32[0] = fmaxf(0.99998999 - *(float *)&this, 0.0);
            v8.i32[0] = 1325400064;
            v9 = _mm_cmple_ss(v8, v7);
            v10.i32[0] = 1333788672;
            result = -_mm_or_si128(
                    _mm_add_epi32(
                            _mm_cvttps_epi32(_mm_sub_ps(v7, _mm_and_ps((__m128)0x4F000000u, v9))),
                            _mm_slli_epi32((__m128i)v9, 0x1Fu)),
                    (__m128i)_mm_cmple_ss(v10, v7)).i32[0];
        }
        else
        {
            v1.f32[0] = fmaxf(*(float *)&this, 0.0);
            v2.i32[0] = 1325400064;
            v3 = _mm_cmple_ss(v2, v1);
            v4.i32[0] = 1333788672;
            result = _mm_or_si128(
                    _mm_add_epi32(
                            _mm_cvttps_epi32(_mm_sub_ps(v1, _mm_and_ps((__m128)0x4F000000u, v3))),
                            _mm_slli_epi32((__m128i)v3, 0x1Fu)),
                    (__m128i)_mm_cmple_ss(v4, v1)).u32[0];
        }
        return result;
    }

    double * sincos_(int64_t this, double *__x_8, double *__x_12)
    {
        long double v3;
        double *result;
        long double v5;
        long double v6;

        *(QWORD *)&v5 = this;
        *__x_8 = sin(v5);
        *(QWORD *)&v6 = this;
        v3 = cos(v6);
        result = __x_12;
        *__x_12 = v3;
        return result;
    }
}
};


#endif //ENGINE_CMATH_H
