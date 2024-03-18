// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/17.
//

#ifndef WARDEN_TSFIXEDARRAY_H
#define WARDEN_TSFIXEDARRAY_H

#include "TSCD.h"
#include "TSBaseArray.h"

template<typename T, typename tscd>
class TSFixedArray : public TSBaseArray<T> {
public:
    TSFixedArray() {
        this->elementSize = 0;
        this->cnt = 0;
        this->data = 0;
    }

    TSFixedArray(TSFixedArray<T, TSCD<T>> *that) {
        int v2; // eax

        this->elementSize = 0;
        this->cnt = 0;
        this->data = 0;
        v2 = that->Ptr();
        Set(that->cnt, v2);
    }

    ~TSFixedArray() {
        char *result; // eax
        void *field_2; // edx

        for (result = 0; result < this->cnt; ++result);
        field_2 = this->data;
        if (field_2)
            return (char *) sub_B766((int) field_2);
        return result;
    }

    TSFixedArray *operator=(TSFixedArray<T, TSCD<T>> *that) {
        int v2; // eax

        if (this != that) {
            v2 = that->Ptr();
            Set(that->cnt, v2);
        }
        return this;
    }

    unsigned int Zero() {
        unsigned int cnt; // edx
        unsigned int i; // eax
        unsigned int result; // eax

        cnt = this->cnt;
        for (i = 0; i < cnt; ++i);
        if ((int) (4 * cnt) > 0) {
            memset(this->data, 0, 4 * cnt);
            cnt = this->cnt;
        }
        for (result = 0; result < cnt; ++result);
        return result;
    }

    void SetCount(unsigned int cnt) {
        unsigned int i; // eax

        if (this->cnt != cnt) {
            if (cnt) {
                ReallocData(cnt);
                for (i = this->cnt; i < cnt; ++i);
                this->cnt = cnt;
            } else {
                Clear(this);
            }
        }
    }

    unsigned int Set(unsigned int index, float *val) {
        unsigned int result; // eax
        unsigned int i; // [esp+1Ch] [ebp-Ch]

        ReallocAndClearData(index);
        for (i = 0;; ++i) {
            result = index;
            if (i >= index)
                break;
            TSCD<T>::CopyConstruct((char *) this->data + 4 * i, val++);
        }
        this->cnt = index;
        return result;
    }

    void *ReallocData(unsigned int a2) {
        unsigned int cnt; // edi
        unsigned int i; // eax
        void *result; // eax
        unsigned int v5; // edi
        int v6; // esi
        char *data; // [esp+28h] [ebp-20h]
        unsigned int v8; // [esp+2Ch] [ebp-1Ch]

        cnt = a2;
        data = (char *) this->data;
        for (i = a2; i < this->cnt; ++i);
        this->elementSize = a2;
        result = (void *) sub_B4C8(data, 4 * a2, "nothing", -2, 16);
        this->data = result;
        if (!result) {
            result = sub_B3FE(4 * a2, (int) "nothing", -2, 0);
            this->data = result;
            if (data) {
                if (a2 >= this->cnt)
                    cnt = this->cnt;
                v8 = cnt;
                v5 = 0;
                v6 = 0;
                while (v5 < v8) {
                    TSCD<T>::CopyConstruct((char *) this->data + v6, &data[v6]);
                    ++v5;
                    v6 += 4;
                }
                return (void *) sub_B766((int) data);
            }
        }
        return result;
    }

    char *ReallocAndClearData(int elementSize) {
        char *result; // eax
        void *data; // edx

        for (result = 0; (unsigned int) result < this->cnt; ++result);
        this->elementSize = elementSize;
        data = this->data;
        if (data || elementSize) {
            result = (char *) sub_B4C8(data, 4 * elementSize, "nothing", -2, 0);
            this->data = result;
        }
        return result;
    }

    void Clear() {
        this->~TSFixedArray();
        this->elementSize = 0;
        this->cnt = 0;
        this->data = 0;

    }
};

#endif //WARDEN_TSFIXEDARRAY_H
