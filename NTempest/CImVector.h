// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.


#ifndef ENGINE_CIMVECTOR_H
#define ENGINE_CIMVECTOR_H

#include <cstdint>
#include <cstdlib>

namespace NTempest {
    class CImVector {
    public:
        CImVector *Set(const CImVector *that) {
            NTempest::CImVector *result;

            result = this;
            *this = *that;
            return result;
        }

//        unsigned int *operator=(unsigned int *a2) {
//            unsigned int *result;
//
//            result = (unsigned int *) this;
//            *(unsigned int *) this = *a2;
//            return result;
//        }

        NTempest::CImVector *operator=(const NTempest::CImVector *that) {
            NTempest::CImVector *result;

            result = this;
            *this = *that;
            return result;
        }

        CImVector *Set(float a2,
                       float a3,
                       float a4,
                       float a5) {
// Convert float values to [0, 255] range
            int r = static_cast<int>(fmaxf(a2 * 255.0f + 0.5f, 0.0f));
            int g = static_cast<int>(fmaxf(a3 * 255.0f + 0.5f, 0.0f));
            int b = static_cast<int>(fmaxf(a4 * 255.0f + 0.5f, 0.0f));
            int a = static_cast<int>(fmaxf(a5 * 255.0f + 0.5f, 0.0f));

            // Clamp values
            r = (r > 255) ? 255 : (r < 0) ? 0 : r;
            g = (g > 255) ? 255 : (g < 0) ? 0 : g;
            b = (b > 255) ? 255 : (b < 0) ? 0 : b;
            a = (a > 255) ? 255 : (a < 0) ? 0 : a;

            // Pack RGBA components into a single integer
            unsigned int rgba = (a << 24) | (b << 16) | (g << 8) | r;

            // Store the packed value into the CImVector object
            *this = NTempest::CImVector(rgba);

            return this;
        }

        int Gray(unsigned int value) {
            unsigned char red = value & 0xFF;
            unsigned char green = (value >> 8) & 0xFF;
            unsigned char blue = (value >> 16) & 0xFF;

            return (28 * red + 151 * green + 77 * blue) >> 8;
        }

        unsigned int Desaturate(unsigned int v3) {
            unsigned char v1 = Gray(v3);
            return (v1 << 8) | (v1 << 16) | (unsigned int) this & 0xFF000000 | v1;
        }

        unsigned int Desaturate() {
            unsigned int result;
            result = Desaturate(*(unsigned int *) this);
            *(unsigned int *) this = result;
            return result;
        }

        int B_() const {
            return (unsigned __int8) this->b;
        }

        int R_() const {
            return (unsigned __int8) this->r;
        }

        int G_() const {
            return (unsigned __int8) this->g;
        }

        int MultiplyRGB_(const CImVector *a2) {
            __int16 v2;
            __int16 v3;
            int result;
            unsigned int v5;
            __int16 v6;
            __int16 v7;
            __int16 v8;

            v5 = *(unsigned int *) this & 0xFF000000;
            v2 = this->R_();
            v6 = a2->R_();
            v7 = this->G_();
            v8 = a2->G_();
            v3 = this->B_();
            result = (unsigned __int8) ((unsigned __int16) (a2->B_() * v3 + 255) >> 8) |
                     (v8 * v7 + 255) & 0xFF00 | ((unsigned __int8) ((unsigned __int16) (v6 * v2 + 255) >> 8) << 16) |
                     v5;
            *this = (NTempest::CImVector) result;
            return result;
        }

    public:
        unsigned char b;
        unsigned char g;
        unsigned char r;
        unsigned char a;
    };
}

#endif //ENGINE_CIMVECTOR_H
