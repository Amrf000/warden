#pragma once

#include <cstddef>
#include <cstdint>
#include <typeinfo>
#include "TSLink.h"
#include "TSGetLink.h"
#include "../Storm/memory.h"
#include "../Storm/DebugUtils.h"

template<typename T, typename TSGetLink>
class TSList {
public:
    TSList() {
        this->InitializeTerminator();
    }

    TSList(const TSList &that) {
        this->m_terminator.nextLinkOffset = 0;
        this->m_linkoffset = that.m_linkoffset;
        this->m_terminator.prevLink = &this->m_terminator;
        this->m_terminator.nextLinkOffset = (unsigned int) &this->m_terminator | 1;
    }

    ~TSList() {
        this->UnlinkAll();
    }


    TSLink<T> *ChangeLinkOffset(ptrdiff_t linkoffset) {
        TSLink<T> *result;

        if (this->m_linkoffset != linkoffset) {
            this->UnlinkAll();
            this->m_linkoffset = linkoffset;
            this->m_terminator.prevLink = &this->m_terminator;
            result = (TSLink<T> *) ((unsigned int) &this->m_terminator | 1);
            this->m_terminator.nextLinkOffset = (int) result;
        }
        return result;
    }

    void Clear() {
        T *node;

        while ((node = this->Head())) {
            this->DeleteNode(node);
        }
    }

    T *DeleteNode(T *ptr) {
        T *next = this->Next(ptr);

        ptr->~T();
        SMemFree(ptr, __FILE__, __LINE__, 0);

        return next;
    }

    T *Head() {
        return this->m_terminator.Next();
    }

    void InitializeTerminator() {
        this->m_terminator.m_prevlink = &this->m_terminator;

        // Set sentinel node (indicates list end)
        this->m_terminator.m_next = reinterpret_cast<T *>(~reinterpret_cast<uintptr_t>(&this->m_terminator));
    }

    bool IsLinked(T *ptr) {
        return TSGetExplicitLink::Link(ptr, this->m_linkoffset)->IsLinked();
    }

    TSLink<T> *Link(const T *ptr) {
        if (ptr) {
            return TSGetExplicitLink::Link(ptr, this->m_linkoffset);
        } else {
            return &this->m_terminator;
        }
    }

    void LinkNode(T *ptr, uint32_t linktype, T *existingptr) {
        TSLink<T> *endlink;
        TSLink<T> *v5;


        if (ptr)
            endlink = (TSLink<T> *) ((uintptr_t) ptr + this->m_linkoffset);
        else
            endlink = &this->m_terminator;
        if (endlink->m_prevlink) {
            *endlink->NextLink(-1) = endlink->m_prevlink;
            endlink->m_prevlink->m_next = endlink->m_next;
            endlink->m_prevlink = 0;
            endlink->m_next = 0;
        }
        if (existingptr)
            v5 = (TSLink<T> *) (this->m_linkoffset + (uintptr_t) existingptr);
        else
            v5 = &this->m_terminator;
        if (linktype == 1) {
            endlink->m_prevlink = v5;
            endlink->m_next = v5->m_next;
            *v5->NextLink(this->m_linkoffset) = endlink;
            v5->m_next = ptr;
        } else if (linktype == 2) {
            TSLink<T> *templink = v5->m_prevlink;
            endlink->m_prevlink = v5->m_prevlink;
            endlink->m_next = templink->m_next;
            templink->m_next = ptr;
            v5->m_prevlink = endlink;
        } else {
            DebugPrint("Invalid case: %s=%u", "linktype", linktype);
        }
    }

    void LinkToHead(T *ptr) {
        this->LinkNode(ptr, 1, nullptr);
    }

    void LinkToTail(T *ptr) {
        this->LinkNode(ptr, 2, nullptr);
    }

    const char *MemFileName() const {
        return typeid(T).name();
    }

    int32_t MemLineNo() const {
        return -2;
    }

    int NewNode(uint32_t location, size_t extrabytes, uint32_t flags) {
        void *m = SMemAlloc(extrabytes + sizeof(T), this->MemFileName(), this->MemLineNo(),
                            flags | 8);
        T *node;
        if (m) {
            node = new(m) T();
        } else {
            node = nullptr;
        }
        if (location) {
            this->LinkNode(node, location, nullptr);
        }
        return node;
    }

    T *Next(const T *ptr) {
        return this->Link(ptr)->Next();
    }

    T *RawNext(const T *ptr) {
        TSLink<T> *link = this->Link(ptr);
        return link->RawNext();
    }

    void SetLinkOffset(ptrdiff_t linkoffset) {
        this->m_linkoffset = linkoffset;
        this->InitializeTerminator();
    }

    T *Tail() {
        return this->m_terminator.Prev();
    }


    void UnlinkAll() {
        T *node;

        while ((node = this->Head())) {
            this->UnlinkNode(node);
        }
    }

    void UnlinkNode(T *node) {
        TSLink<T> *link = this->Link(node);
        link->Unlink();
    }

private:
    int m_linkoffset;  // 元素数量
    TSLink<T> m_terminator;  // 第一个链接
};


