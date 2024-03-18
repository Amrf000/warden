// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/18.
//

#ifndef WARDEN_TSGROWABLEARRAY_H
#define WARDEN_TSGROWABLEARRAY_H

#include "TSCD.h"
#include "TSFixedArray.h"

template<typename T, typename tscd>
class TSGrowableArray : public TSFixedArray<T, tscd> {
public:
    TSGrowableArray() {
        this->field_C = 0;
    }

    TSGrowableArray(TSGrowableArray *that) : TSFixedArray<T, tscd>(that) {
        this->field_C = that->field_C;
    }

    void SetCount(unsigned int a2) {
        unsigned int v2;
        unsigned int i;
        int v4;
        int v5;

        v2 = this->field_4;
        if (v2 >= a2) {
            if (v2 > a2) {
                v4 = 0;
                v5 = v2 - a2;
                while (v5 != v4)
                    ++v4;
            }
        } else {
            Reserve(a2 - v2, 1);
            for (i = this->field_4; i < a2; ++i);
        }
        this->field_4 = a2;
    }

    void *Reserve(unsigned int a2, int a3) {
        void *result;
        unsigned int v4;
        int v5;
        unsigned int i;

        result = (void *) a3;
        v4 = a2 + this->field_4;
        if (v4 > this->field_0) {
            if (!a3)
                return ReallocData(v4);
            i = this->field_C;
            if (!i) {
                if (v4 > 0x3F) {
                    this->field_C = 64;
                    v5 = v4 & 0x3F;
                    i = 64;
                    LABEL_11:
                    if (v5)
                        v4 += i - v5;
                    return ReallocData(v4);
                }
                for (i = a2 + this->field_4; (i & (i - 1)) != 0; i &= i - 1);
                if (!i)
                    return ReallocData(v4);
            }
            v5 = v4 % i;
            goto LABEL_11;
        }
        return result;
    }

    int New() {
        int v1;
        int result;

        Reserve(1, 1);
        v1 = this->field_4;
        result = this->field_8 + 4 * v1;
        this->field_4 = v1 + 1;
        return result;
    }
};

#endif //WARDEN_TSGROWABLEARRAY_H
