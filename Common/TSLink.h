#pragma once

#include <cstdint>

template<typename T>
class TSLink {
public:
    TSLink() {
        this->m_prevlink = nullptr;
        this->m_next = nullptr;
    }

    ~TSLink() {
        this->Unlink();
    }

    bool IsLinked() {
        return this->m_next != nullptr;
    }

    T *Next() {
        // Check for sentinel node (indicates list end)
        return reinterpret_cast<intptr_t>(this->m_next) <= 0 ? nullptr : this->m_next;
    }

    TSLink<T> *NextLink(ptrdiff_t linkoffset) {
        T *next = this->m_next;

        if (reinterpret_cast<intptr_t>(next) <= 0) {
            // End of list
            return reinterpret_cast<TSLink<T> *>(~reinterpret_cast<uintptr_t>(next));
        } else {
            ptrdiff_t offset;

            if (linkoffset < 0) {
                offset = reinterpret_cast<uintptr_t>(this) - reinterpret_cast<uintptr_t>(this->m_prevlink->m_next);
            } else {
                offset = linkoffset;
            }

            return reinterpret_cast<TSLink<T> *>(reinterpret_cast<uintptr_t>(this->m_next) + offset);
        }
    }

    T *Prev() {
        return this->m_prevlink->m_prevlink->Next();
    }

    T *TSLink<T>::RawNext() {
        return this->m_next;
    }

    void Unlink() {
        if (this->m_prevlink) {
            this->NextLink(-1)->m_prevlink = this->m_prevlink;
            this->m_prevlink->m_next = this->m_next;

            this->m_prevlink = nullptr;
            this->m_next = nullptr;
        }
    }

private:
    TSLink *m_prevlink;
    T *m_next;
};

