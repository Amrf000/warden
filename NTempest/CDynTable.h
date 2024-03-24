//
// Created by liuyawu on 2019/5/9.
//

#ifndef ENGINE_CDYNTABLE_H
#define ENGINE_CDYNTABLE_H

#include "CMemBlockT.h"

namespace NTempest {
    template <typename T>
    class CDynTable:public CMemBlockT<T> {
    public:
        virtual ~CDynTable(){}
        virtual int Release()
        {
            this->~CMemBlockT();
            HeapRelease(this);
        }
    };
}

#endif //ENGINE_CDYNTABLE_H
