#pragma once

#include "TSLink.h"

template<typename T>
class TSLinkedNode {
public:
    TSLinkedNode() {
        this->m_link.m_prevlink = 0;
        this->m_link.m_next = 0;
    }

    virtual  ~TSLinkedNode() {
        this->Unlink()();
    }

    T *Next() {
        return this->m_link.Next();
    }

    T *Prev() {
        return this->m_link.Prev();
    }

    void Unlink() {
        this->m_link.Unlink();
    }

private:
    TSLink<T> m_link;
};


