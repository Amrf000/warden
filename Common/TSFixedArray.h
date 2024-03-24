


// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

#ifndef WARDEN_TSFIXEDARRAY_H
#define WARDEN_TSFIXEDARRAY_H

#include "TSCD.h"
#include "TSBaseArray.h"
#include "../Storm/memory.h"

template<typename T, typename tscd>
class TSFixedArray : public TSBaseArray<T> {
public:
    TSFixedArray() {
        this->capacity = 0;
        this->cnt = 0;
        this->data = 0;
    }

    TSFixedArray(const TSFixedArray &that) {
        this->capacity = 0;
        this->cnt = 0;
        this->data = 0;
        Set(that.cnt, that.Ptr());
    }

    ~TSFixedArray() {
        if (this->data)
            DeallocateMemory(this->data);
    }

    TSFixedArray &operator=(const TSFixedArray &that) {
        if (this != &that) {
            Set(that.cnt, that.Ptr());
        }
        return *this;
    }

    void Zero() {
        if (sizeof(T) * this->cnt > 0) {
            memset(this->data, 0, sizeof(T) * this->cnt);
        }
    }

    virtual void SetCount(unsigned int newCnt) {
        if (this->cnt != newCnt) {
            if (newCnt) {
                ReallocData(newCnt);
                this->cnt = newCnt;
            } else {
                Clear(this);
            }
        }
    }

    unsigned int Set(unsigned int lenOfData, T *data) {
        ReallocAndClearData(lenOfData);
        for (unsigned int i = 0; i < lenOfData; ++i)
            tscd::CopyConstruct(&this->data[i], data++);
        this->cnt = lenOfData;
    }

    void ReallocData(unsigned int newCnt) {
        unsigned int cnt = newCnt;
        T *data = this->data;
        this->capacity = newCnt;
        void *v4 = ReallocMemoryEx(data, sizeof(T) * newCnt, "nothing", -2, 16);
        this->data = v4;
        if (!v4) {
            this->data = SMemAlloc(sizeof(T) * newCnt, "nothing", -2, 0);
            if (data) {
                if (newCnt >= this->cnt)
                    cnt = this->cnt;
                unsigned int v8 = cnt;
                unsigned int v5 = 0;
                int v6 = 0;
                while (v5 < v8) {
                    tscd::CopyConstruct(&this->data[v6], &data[v6]);
                    ++v5;
                    v6 += sizeof(T);
                }
                DeallocateMemory(data);
            }
        }
    }

    void ReallocAndClearData(int elementSize) {
        this->capacity = elementSize;
        void *data = this->data;
        if (data || elementSize) {
            this->data = ReallocMemoryEx(data, sizeof(T) * elementSize, "nothing", -2, 0);
        }
    }

    void Clear() {
        this->~TSFixedArray();
        this->capacity = 0;
        this->cnt = 0;
        this->data = 0;
    }
};

#endif 
