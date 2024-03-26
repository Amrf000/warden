// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.


#ifndef WARDEN_TSLINK_H
#define WARDEN_TSLINK_H

#include <cstdint>

template<typename T>
class TSLink {
public:
    TSLink<T> *NextLink(int linkoffset) {
        T *nextLinkOffset = this->m_next;
        if ((nextLinkOffset & 1) != 0 || !nextLinkOffset)
            return reinterpret_cast<TSLink<T> *>(nextLinkOffset & 0xFFFFFFFE);
        if (linkoffset < 0)
            linkoffset = reinterpret_cast<uintptr_t>(this) - reinterpret_cast<uintptr_t>(this->m_prevlink->m_next);
        return reinterpret_cast<TSLink<T> *>(nextLinkOffset + linkoffset);
    }

private:
    TSLink *m_prevlink;
    T *m_next;
};

#endif //WARDEN_TSLINK_H
