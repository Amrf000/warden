// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.


#ifndef WARDEN_TSLIST_H
#define WARDEN_TSLIST_H

#include "TSLink.h"
#include "TSGetExplicitLink.h"
#include "../Storm/memory.h"
#include "../Storm/DebugUtils.h"

template<typename T, typename LinkType>
class TSList {
public:
    TSList() {
        this->m_terminator.nextLinkOffset = 0;
        this->m_linkoffset = 0;
        this->m_terminator.prevLink = &this->m_terminator;
        this->m_terminator.nextLinkOffset = (unsigned int) &this->m_terminator | 1;
    }

    TSList(const TSList &that) {
        this->m_terminator.nextLinkOffset = 0;
        this->m_linkoffset = that.m_linkoffset;
        this->m_terminator.prevLink = &this->m_terminator;
        this->m_terminator.nextLinkOffset = (unsigned int) &this->m_terminator | 1;
    }

    ~TSList() {
        UnlinkAll();

        if (this->m_terminator.prevLink) {
            *this->m_terminator.NextLink(-1) = this->m_terminator.prevLink;
            this->m_terminator.prevLink->nextLinkOffset = this->m_terminator.nextLinkOffset;
            this->m_terminator.prevLink = 0;
            this->m_terminator.nextLinkOffset = 0;
        }
    }

    int NewNode(int linktype, int a3, int a4) {
        T *MemoryWithInitialization = (T *) SMemAlloc(a3 + sizeof(T), "", -2, a4 | 8);
        if (MemoryWithInitialization)
            new(MemoryWithInitialization) T();
        if (linktype)
            LinkNode(MemoryWithInitialization, linktype, 0);
        return MemoryWithInitialization;
    }

    void LinkNode(T *node, int linktype, T *a4) {
        TSLink<T> *endlink;
        TSLink<T> *v5;


        if (node)
            endlink = (TSLink<T> *) ((uintptr_t) node + this->m_linkoffset);
        else
            endlink = &this->m_terminator;
        if (endlink->m_prevlink) {
            *endlink->NextLink(-1) = endlink->m_prevlink;
            endlink->m_prevlink->m_next = endlink->m_next;
            endlink->m_prevlink = 0;
            endlink->m_next = 0;
        }
        if (a4)
            v5 = (TSLink<T> *) (this->m_linkoffset + (uintptr_t) a4);
        else
            v5 = &this->m_terminator;
        if (linktype == 1) {
            endlink->m_prevlink = v5;
            endlink->m_next = v5->m_next;
            *v5->NextLink(this->m_linkoffset) = endlink;
            v5->m_next = node;
        } else if (linktype == 2) {
            TSLink<T> *templink = v5->m_prevlink;
            endlink->m_prevlink = v5->m_prevlink;
            endlink->m_next = templink->m_next;
            templink->m_next = node;
            v5->m_prevlink = endlink;
        } else {
            DebugPrint("Invalid case: %s=%u", "linktype", linktype);
        }
    }

    TSLink<T> *ChangeLinkOffset(int offset) {
        TSLink<T> *result;

        if (this->m_linkoffset != offset) {
            UnlinkAll();
            this->m_linkoffset = offset;
            this->m_terminator.prevLink = &this->m_terminator;
            result = (TSLink<T> *) ((unsigned int) &this->m_terminator | 1);
            this->m_terminator.nextLinkOffset = (int) result;
        }
        return result;
    }

    void UnlinkNode(T *pNode) {
        TSLink<T> *p_firstLink;

        if (pNode)
            p_firstLink = (TSLink<T> *) (this->m_linkoffset + pNode);
        else
            p_firstLink = &this->m_terminator;
        if (p_firstLink->prevLink) {
            *(p_firstLink->NextLink(-1)) = p_firstLink->prevLink;
            p_firstLink->prevLink->nextLinkOffset = p_firstLink->nextLinkOffset;
            p_firstLink->prevLink = 0;
            p_firstLink->nextLinkOffset = 0;
        }
    }

    void UnlinkAll() {
        while (true) {
            T *m_next = this->m_terminator.m_next;
            if (((uintptr_t) m_next & 1) != 0 || !m_next)
                break;
            UnlinkNode(this->m_terminator.m_next);
        }
    }

private:
    int m_linkoffset;  // 元素数量
    TSLink<T> m_terminator;  // 第一个链接
};

#endif //WARDEN_TSLIST_H
