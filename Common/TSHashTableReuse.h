#pragma once

#include "TSHashTable.h"
#include "TSHashObjectChunk.h"

template<typename T, typename N>
class TSHashTableReuse : public TSHashTable<T, N> {
public:
    TSHashTableReuse() {
        this->m_chunkSize = 16;
        this->m_reuseList.ChangeLinkOffset(4);
    }

    ~TSHashTableReuse() {
        this->Destructor();
    }

    void Destructor() {
        this->m_chunkList.Clear();
        this->m_reuseList.Clear();
        this->m_chunkSize = 16;
    }

    void Destroy() {
        this->InternalClear(0);
        this->Destructor();
    }

protected:
    TSExplicitList<T, -572662307> m_reuseList;
    int m_chunkSize;
    TSExplicitList<TSHashObjectChunk<T, N>, 16> m_chunkList;
};


