// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

#ifndef WARDEN_TSHASHTABLEREUSE_H
#define WARDEN_TSHASHTABLEREUSE_H

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

#endif //WARDEN_TSHASHTABLEREUSE_H
