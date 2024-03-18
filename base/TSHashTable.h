// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/18.
//

#ifndef WARDEN_TSHASHTABLE_H
#define WARDEN_TSHASHTABLE_H

#include "TSGetExplicitLink.h"
#include "TSList.h"
#include "TSExplicitList.h"
#include "TSCD.h"
#include " TSGrowableArray.h"

template<typename T, typename N>
class TSHashTable {
public:
    TSHashTable()
    {
        this->field_6 = 0;
        this->field_4.ChangeLinkOffset(12);
        this->field_16 = -1;
    }
    ~TSHashTable()
    {
        this->InternalClear( 1);
        this->field_14->~TSGrowableArray();
        this->field_4->~TSList();
    }
    int Unlink(T *a2)
    {
        int result = a2->field_8;
        if (result) {
            if (a2->field_4) {
                *(_DWORD*)TSLink<ZipFileDirEntry>::NextLink(&a2->field_4, -1) = a2->field_4;
                *(_DWORD*)(a2->field_4 + 4) = a2->field_8;
                a2->field_4 = 0;
                a2->field_8 = 0;
            }
            result = a2->field_C;
            if (result) {
                *(_DWORD*)TSLink<ZipFileDirEntry>::NextLink(&a2->field_C, -1) = a2->field_C;
                result = a2->field_10;
                *(_DWORD*)(a2->field_C + 4) = result;
                a2->field_C = 0;
                a2->field_10 = 0;
            }
        }
        return result;
    }

    _DWORD *Ptr(const char *a2)
    {
        int v5 = sub_1B290(a2);
        _DWORD* v2 = *(_DWORD**)(this->m_listArray.field_8 + 12 * (this->m_initialized & v5) + 8);
        if (((unsigned char)v2 & 1) != 0 || !v2)
            return nullptr;
        while (((unsigned char)v2 & 1) == 0 && v2) {
            if (v5 == *v2) {
                const char* v3 = reinterpret_cast<const char*>(v2[5]);
                if (a2 == v3 || !sub_1A3E0(v3, a2, 0x7FFFFFFF))
                    return v2;
            }
            v2 = (_DWORD*)RawNext(
                    this->m_listArray.field_8 + 12 * (this->m_initialized & v5),
                    v2);
        }
        return nullptr;
    }
    int MonitorFullness(unsigned int a2)
    {
        unsigned int field_6 = this->field_6;
        if (this->m_initialized <= 0x1FFEu) {
            if (field_6 <= 3)
                this->field_6 = 0;
            else
                this->field_6 = field_6 - 3;
            int v3 = *(_DWORD*)(this->m_listArray.field_8 + 12 * a2 + 8);
            if ((v3 & 1) != 0 || !v3)
                v3 = 0;
            while ((v3 & 1) == 0 && v3) {
                unsigned int v5 = this->field_6 + 1;
                this->field_6 = v5;
                if (v5 > 0xD) {
                    this->field_6 = 0;
                    GrowListArray(2 * this->m_initialized + 2);
                    return 1;
                }
                v3 = RawNext(this->m_listArray.field_8 + 12 * a2, v3);
            }
        }
        return 0;
    }
    int InternalLinkNode(T *ptr, unsigned int index)
    {
        if (m_initialized == -1)
            Initialize();

        unsigned int hash = m_initialized & index;
        if (MonitorFullness(hash))
            hash = m_initialized & index;

        m_listArray[hash].LinkNode(ptr, 2, 0);
        return m_next.LinkNode(ptr, 2, 0);
    }
    int InternalClear(int a2)
    {
        this->m_initialized = 0;
        this->m_next.UnlinkAll();

        unsigned int index = 0;
        int offset = 0;
        int result = 0;
        while (index < this->m_listArray.m_elementCount) {
            while (true) {
                int listAddr = reinterpret_cast<int>(this->m_listArray.m_data) + offset;
                int linkValue = *reinterpret_cast<int*>(listAddr + 8);
                if ((linkValue & 1) != 0 || !linkValue)
                    break;
                if (a2)
                    this->m_listArray.m_data[offset].UnlinkNode(linkValue);
                else
                    this->m_next(reinterpret_cast<TSHashTable*>(this), linkValue);
            }
            ++index;
            offset += sizeof(T);
        }
        return result;
    }
    const char *Insert(T *a2, const char *a3)
    {
        unsigned int v3 = sub_1B290(a3);
        this->InternalLinkNode(a2, v3);
        a2->field_0 = v3;
        a2->field_14 = reinterpret_cast<int>(a3);
        return a3;
    }
    TSHashTable *Initialize()
    {
        this->m_initialized = 3;
        this->m_listArray.SetCount(4);
        for (unsigned int i = 0; i <= this->m_initialized; ++i) {
            this->m_listArray.m_data[i].ChangeLinkOffset(4);
        }
        return this;
    }
    int GrowListArray(unsigned int a2)
    {
        unsigned int v2 = this->m_initialized + 1;
        TSExplicitList<T, -572662307> v9;
        unsigned int v8 = v2;
        v9.ChangeLinkOffset(4);
        unsigned int v3 = 0;
        unsigned int v10 = 0;
        while (v3 < v8) {
            int v4 = *(_DWORD*)(this->m_listArray.field_8 + v10 + 8);
            if ((v4 & 1) != 0 || !v4)
                break;
            v9.LinkNode( v4, 2, 0);
            ++v3;
            v10 += 12;
        }
        this->m_listArray.SetCount(a2);
        unsigned int v5 = 0;
        unsigned int v6 = 0;
        while (v5 < a2) {
            ChangeLinkOffset(this->m_listArray.field_8 + v6, 4);
            ++v5;
            v6 += 12;
        }
        this->m_initialized = a2 - 1;
        int v10 = *(_DWORD*)v9;
        while ((v10 & 1) == 0 && v10) {
            LinkNode(this->m_listArray.field_8 + 12 * (this->m_initialized & *(_DWORD*)v10), v10, 2, 0);
            v10 = v9.RawNext(v10);
        }
    }
    int DeleteNode(T *a2)
    {
        int v2;

        v2 = this->m_next.Next(a2);
        this->Delete(a2);
        return v2;
    }
    int Delete(T *a2)
    {
        Unlink(a2);
        return (*(int (__cdecl **)(TSHashTable *, T *))this->field_0)(this, a2);
    }
private:
    TSList<T,TSGetExplicitLink<T>> m_next;
    TSGrowableArray<TSExplicitList<T,-572662307>,TSCD<TSExplicitList<T,-572662307>>> m_listArray;
    int m_initialized;
};

#endif //WARDEN_TSHASHTABLE_H
