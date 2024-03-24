//
// Created by liuyawu on 2019/5/9.
//

#ifndef ENGINE_CMEMBLOCKT_H
#define ENGINE_CMEMBLOCKT_H

#include "CMemBlock.h"

namespace NTempest {

    template <typename T>
    class CMemBlockT:public CMemBlock {
    public:
        virtual ~CMemBlockT(){}
        virtual int Release()
        {
            this->~CMemBlockT();
            return HeapRelease(this);
        }
    };
}


#endif //ENGINE_CMEMBLOCKT_H
