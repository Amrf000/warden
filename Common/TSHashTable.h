// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.


#ifndef WARDEN_TSHASHTABLE_H
#define WARDEN_TSHASHTABLE_H

#include "TSGetExplicitLink.h"
#include "TSList.h"
#include "TSExplicitList.h"
#include "TSCD.h"
#include "TSGrowableArray.h"
#include "HashObject/TSHashObject.h"
#include "../Storm/SStr.h"

template<typename T, typename N> requires(std::is_base_of_v<TSHashObject<T, N>, T>)
class TSHashTable {
public:
    TSHashTable() : m_fullnessIndicator(0), m_slotmask(-1) {
        this->m_fulllist.ChangeLinkOffset(12);
    }

    virtual void DeallocateNode(T *val) {
        val->~T();
        DeallocateMemory(val);
    }

    virtual T *NewNode(TSList<T, TSGetExplicitLink<T>> *a2, int a3, int a4) {
        return a2->NewNode(1, a3, a4);
    }

    virtual ~TSHashTable() {
        InternalClear(1);
        this->m_slotlistarray.~TSFixedArray();
        this->m_fulllist.~TSList();
    }

    virtual void HeapDeallocate() {
        this->InternalClear(1);
        this->m_slotlistarray->~TSFixedArray();
        this->m_fulllist->~TSList();
        DeallocateMemoryEx(this);
    }

    virtual void reset() {
        InternalClear(1);
        this->field_6 = 0;
        this->m_initialized = -1;
        this->m_slotlistarray->Clear();
    }

    T *InternalNewNode(int option, int a3, int a4) {
        int v4;
        T *v5;

        if (this->m_slotmask == -1)
            Initialize();
        v4 = this->m_slotmask & option;
        if (MonitorFullness(v4))
            v4 = this->m_slotmask & option;
        v5 = this->NewNode(&this->m_slotlistarray.data[3 * v4], a3, a4);
        this->m_fulllist.LinkNode(v5, 2, 0);
        return v5;
    }

    T *New(int *a2, T *a3, int a4, int a5) {
        T *v5;

        v5 = this->InternalNewNode(a2, a4, a5);
        v5->vtable = a2;
        if (&v5->object.m_linktofull.m_next != a3)
            v5->object.m_linktofull.m_next = *a3;
        return v5;
    }

    void Unlink(T *node) {
        if (node->object.m_key.m_fulllist) {
            if (node->object.m_key.m_prevlink) {
                *node->object.m_key.NextLink(-1) = node->object.m_key.m_prevlink;
                node->object.m_key.m_prevlink->m_fulllist = node->object.m_key.m_fulllist;
                node->object.m_key.m_prevlink = 0;
                node->object.m_key.m_fulllist = 0;
            }
            if (node->object.data.m_prevlink) {
                *node->object.data.NextLink(-1) = node->object.data.m_prevlink;
                node->object.data.m_prevlink->m_fulllist = node->object.data.m_fulllist;
                node->object.data.m_prevlink = 0;
                node->object.data.m_fulllist = 0;
            }
        }
    }

    void *Ptr(int a2, N *a3) {
        T *v3;

        if (this->m_slotmask != -1) {
            v3 = (int *) this->m_slotlistarray.data[3 * (this->m_slotmask & a2) + 2];
            if (((unsigned __int8) v3 & 1) != 0 || !v3)
                v3 = 0;
            while (((unsigned __int8) v3 & 1) == 0 && v3) {
                if (a2 == *v3 && (v3 + 5 == a3 || v3[5] == *a3))
                    return v3;
                v3 = this->m_slotlistarray.data[3 * (this->m_slotmask & a2)].RawNext(v3);
            }
        }
        return 0;
    }

    int MonitorFullness(unsigned int a2) {
        unsigned int fullnessIndicator;
        int v3;
        unsigned int v5;

        if (this->m_slotmask <= 0x1FFEu) {
            fullnessIndicator = this->m_fullnessIndicator;
            if (fullnessIndicator <= 3)
                this->m_fullnessIndicator = 0;
            else
                this->m_fullnessIndicator = fullnessIndicator - 3;
            v3 = this->m_slotlistarray.data[3 * a2 + 2];
            if ((v3 & 1) != 0 || !v3)
                v3 = 0;
            while ((v3 & 1) == 0 && v3) {
                v5 = this->m_fullnessIndicator + 1;
                this->m_fullnessIndicator = v5;
                if (v5 > 0xD) {
                    this->m_fullnessIndicator = 0;
                    GrowListArray(2 * this->m_slotmask + 2);
                    return 1;
                }
                v3 = this->m_slotlistarray.data[3 * a2].RawNext(v3);
            }
        }
        return 0;
    }

    int InternalLinkNode(T *ptr, unsigned int index) {
        unsigned int hash;
        if (this->m_slotmask == -1)
            this->Initialize();
        hash = this->m_slotmask & index;
        if (this->MonitorFullness(hash))
            hash = this->m_slotmask & index;
        this->m_slotlistarray.data[3 * hash].LinkNode(ptr, 2, 0);
        this->m_fulllist.LinkNode(ptr, 2, 0);
    }

    void InternalClear(int option) {
        unsigned int v2;
        int v3;
        T *v4;
        void *v5;

        this->m_fullnessIndicator = 0;
        this->m_fulllist.UnlinkAll();
        v2 = 0;
        v3 = 0;
        while (v2 < this->m_slotlistarray.cnt) {
            while (1) {
                v4 = &this->m_slotlistarray.data[v3];
                v5 = (void *) v4[2];
                if (((unsigned __int8) v5 & 1) != 0 || !v5)
                    break;
                if (option)
                    v4->UnlinkNode(v4[2]);
                else
                    this->DeallocateNode(v5);
            }
            ++v2;
            v3 += 3;
        }
    }

    const char *Insert(T *ptr, const char *key) {
        unsigned int hashVal;
        hashVal = SStrHashHT(key);
        InternalLinkNode(ptr, hashVal);
        ptr->m_hashVal = hashVal;
        ReMem(ptr->m_key, key);
    }

    void Initialize() {
        unsigned int v1;
        int v2;

        this->m_slotmask = 3;
        this->m_slotlistarray.SetCount(4);
        v1 = 0;
        v2 = 0;
        while (v1 <= this->m_slotmask) {
            this->m_slotlistarray.data[v2].ChangeLinkOffset(4);
            ++v1;
            v2 += 3;
        }
    }

    void GrowListArray(unsigned int newSize) {
        unsigned int v2;
        int v3;
        int v4;
        unsigned int v5;
        int v6;
        unsigned int v7;
        TSExplicitList<T, -572662307> v8;

        v7 = this->m_slotmask + 1;
        v8.ChangeLinkOffset(4);
        v2 = 0;
        v3 = 0;
        while (v2 < v7) {
            while (true) {
                v4 = this->m_slotlistarray.data[v3 + 2];
                if ((v4 & 1) != 0 || !v4)
                    break;
                v8.LinkNode(v4, 2, 0);
            }
            ++v2;
            v3 += 3;
        }
        this->m_slotlistarray.SetCount(newSize);
        v5 = 0;
        v6 = 0;
        while (v5 < newSize) {
            this->m_slotlistarray.data[v6].ChangeLinkOffset(4);
            ++v5;
            v6 += 3;
        }
        this->m_slotmask = newSize - 1;
        while (((int) v8.m_terminator.m_next & 1) == 0 && v8.m_terminator.m_next)
            this->m_slotlistarray.data[3 * (this->m_slotmask & *v8.m_terminator.m_next)].LinkNode(
                    v8.m_terminator.m_next,
                    2,
                    0);
        //TSList<KERNNODE, TSGetExplicitLink<KERNNODE>>::~TSList(&v8);
    }

    int DeleteNode(T *a2) {
        int v2;

        v2 = this->m_fulllist.Next(a2);
        this->Delete(a2);
        return v2;
    }

    void Delete(T *node) {
        this->Unlink(node);
        this->DeallocateNode(node);
    }

private:
    TSList<T, TSGetExplicitLink<T>> m_fulllist;
    int m_fullnessIndicator;
    TSGrowableArray<TSExplicitList<T, -572662307>, TSCD<TSExplicitList<T, -572662307>>> m_slotlistarray;
    int m_slotmask;
};

#endif //WARDEN_TSHASHTABLE_H
