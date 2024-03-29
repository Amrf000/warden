#pragma once

#include "TSCD.h"
#include "TSFixedArray.h"

template<typename T, typename tscd>
class TSGrowableArray : public TSFixedArray<T, tscd> {
public:
    TSGrowableArray() : incrementBatchSize(0) {

    }

    TSGrowableArray(const TSGrowableArray &that) : TSFixedArray<T, tscd>(that),
                                                   incrementBatchSize(that.incrementBatchSize) {
    }

    void Add(unsigned int lengthOfData, T *data) {
        this->Reserve(lengthOfData, true);
        for (unsigned int i = 0; i < lengthOfData; ++i)
            tscd::CopyConstruct(&this->data[this->cnt + i], data++);
        this->cnt += lengthOfData;
    }

    void GrowToFit(unsigned int newCnt, bool clean) {
        unsigned int cnt = this->cnt;
        if (cnt <= newCnt) {
            Reserve(newCnt - cnt + 1, 1);
            if (clean) {
                if ((sizeof(T) * (newCnt - cnt + 1)) <= 0) {

                } else {
                    memset(&this->data[cnt], 0, sizeof(T) * (newCnt - cnt + 1));
                }
            }
            this->cnt = newCnt + 1;
        }
    }

    void SetCount(unsigned int newCnt) {
        unsigned int cnt = this->cnt;
        if (cnt >= newCnt) {
        } else {
            this->Reserve(newCnt - cnt, true);
        }
        this->cnt = newCnt;
    }

    void Reserve(int addSize, bool positive) {
        unsigned int newCnt = addSize + this->cnt;
        if (newCnt > this->capacity) {
            if (!positive) {
                this->ReallocData(newCnt);
                return;
            }

            unsigned int batchSize = this->incrementBatchSize;
            if (!batchSize) {
                if (newCnt > 0x3F) {
                    this->incrementBatchSize = 64;
                    newCnt += (64 - (newCnt & 0x3F)) & 0x3F;
                } else {
                    while (newCnt & (newCnt - 1))
                        newCnt &= newCnt - 1;
                }
            } else {
                newCnt += batchSize - (newCnt % batchSize);
            }
        }

        this->ReallocData(newCnt);
    }

    T *New() {
        this->Reserve(1, true);
        unsigned int cnt = this->cnt;
        auto ret = &this->data[cnt];
        this->cnt = cnt + 1;
        return ret;
    }

private:
    int incrementBatchSize;
};


