#pragma once

#include "TSLink.h"
#include "TSLinkedNode.h"

template<typename T>
class TSGetLink {
public:
    TSGetLink() : m_link(nullptr) {}

    static TSLink<T> *Link(const TSLinkedNode<T> *nodeptr, ptrdiff_t linkoffset) {
        return reinterpret_cast<TSLink<T> *>(reinterpret_cast<uintptr_t>(nodeptr));
    }

    T *GetLink() const {
        return m_link;
    }

    void SetLink(T *link) {
        m_link = link;
    }

protected:
    T *m_link;
};
