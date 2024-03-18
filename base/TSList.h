// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/17.
//

#ifndef WARDEN_TSLIST_H
#define WARDEN_TSLIST_H

#include "TSLink.h"
#include "TSGetExplicitLink.h"

template<typename T, typename LinkType>
class TSList {
public:
    TSList()
    {
        this->m_terminator.nextLinkOffset = 0;
        this->m_linkoffset = 0;
        this->m_terminator.prevLink = &this->m_terminator;
        this->m_terminator.nextLinkOffset = (unsigned int)&this->m_terminator | 1;
    }
    TSList(TSList *that)
    {
        this->m_terminator.nextLinkOffset = 0;
        this->m_linkoffset = that->m_linkoffset;
        this->m_terminator.prevLink = &this->m_terminator;
        this->m_terminator.nextLinkOffset = (unsigned int)&this->m_terminator | 1;
    }
    ~TSList()
    {
        UnlinkAll();

        if ( this->m_terminator.prevLink )
        {
            *this->m_terminator.NextLink(-1) = this->m_terminator.prevLink;
            this->m_terminator.prevLink->nextLinkOffset = this->m_terminator.nextLinkOffset;
            this->m_terminator.prevLink = 0;
            this->m_terminator.nextLinkOffset = 0;
        }
    }
    int NewNode(int a2, int a3, int a4)
    {
        T *v4;
        T* v5;

        v4 = (T *)sub_B3FE(a3 + 128, (int)"", -2, a4 | 8);
        v5 = v4;
        if ( v4 )
            T::T(v4);
        if ( a2 )
            LinkNode(v5, a2, 0);
        return v5;
    }
    int LinkNode(T* a2, int a3, T* a4)
    {
        TSLink<T> *p_firstLink;
        int *v5;
        int result;

        if ( a2 )
            p_firstLink = (TSLink<T>*)(this->m_linkoffset + a2);
        else
            p_firstLink = &this->m_terminator;
        if ( p_firstLink->prevLink )
        {
            *p_firstLink->NextLink(-1) = p_firstLink->prevLink;
            p_firstLink->prevLink->nextLinkOffset = p_firstLink->nextLinkOffset;
            p_firstLink->prevLink = 0;
            p_firstLink->nextLinkOffset = 0;
        }
        if ( a4 )
            v5 = (int *)(this->m_linkoffset + a4);
        else
            v5 = (int *)&this->m_terminator;
        if ( a3 == 1 )
        {
            p_firstLink->prevLink = (TSLink<T> *)v5;
            p_firstLink->nextLinkOffset = v5[1];
            *v5->NextLink(this->m_linkoffset) = p_firstLink;
            result = a2;
            v5[1] = a2;
        }
        else if ( a3 == 2 )
        {
            result = *v5;
            p_firstLink->prevLink = (TSLink<T>  *)*v5;
            p_firstLink->nextLinkOffset = *(_DWORD *)(result + 4);
            *(_DWORD *)(result + 4) = a2;
            *v5 = (int)p_firstLink;
        }
        else
        {
            return sub_71BA9C("Invalid case: %s=%u", "linktype", a3);
        }
        return result;
    }
    TSLink<T> *ChangeLinkOffset(int offset)
    {
        TSLink<T> *result;

        if (this->m_linkoffset != offset )
        {
            UnlinkAll();
            this->m_linkoffset = offset;
            this->m_terminator.prevLink = &this->m_terminator;
            result = (TSLink<T> *)((unsigned int)&this->m_terminator | 1);
            this->m_terminator.nextLinkOffset = (int)result;
        }
        return result;
    }
    void UnlinkNode(T* pNode)
    {
        TSLink<T> *p_firstLink;

        if ( pNode )
            p_firstLink = (TSLink<T> *)(this->m_linkoffset + pNode);
        else
            p_firstLink = &this->m_terminator;
        if ( p_firstLink->prevLink )
        {
            *(p_firstLink->NextLink(-1)) = p_firstLink->prevLink;
            p_firstLink->prevLink->nextLinkOffset = p_firstLink->nextLinkOffset;
            p_firstLink->prevLink = 0;
            p_firstLink->nextLinkOffset = 0;
        }
    }
    TSLink<T> *UnlinkAll()
    {
        while ( 1 )
        {
            int offset = this->m_terminator.nextLinkOffset;
            if ( ((unsigned __int8)offset & 1) != 0 || !offset )
                break;
            UnlinkNode(this->m_terminator.nextLinkOffset);
        }
    }
private:
    int m_linkoffset;  // 元素数量
    TSLink<T> m_terminator;  // 第一个链接
};

#endif //WARDEN_TSLIST_H
