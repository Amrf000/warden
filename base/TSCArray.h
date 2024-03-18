// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/17.
//

#ifndef WARDEN_TSCARRAY_H
#define WARDEN_TSCARRAY_H

template<typename T,int N>
class TSCArray{
public:
    TSCArray()
    {
        T **v1;
        int i;

        this->field_0 = 8;
        v1 = &this->field_4;
        for ( i = 6; i != -2; --i )
        {
            T::T((T *)v1);
            v1 += 5;
        }
    }
    TSCArray(TSCArray<T,N> *that)
    {
        int i;
        unsigned int v3;
        TSCArray *v4;
        unsigned int j;

        for ( i = 3; i != -1; --i )
            ;
        v3 = that->field_0;
        v4 = this;
        for ( j = 0; j < v3; ++j )
        {
            v4->field_4 = (T *)*((_DWORD *)&that->field_4 + j);
            v4 = (TSCArray *)((char *)v4 + 4);
        }
        this->field_0 = v3;
    }
    TSCArray *operator=(TSCArray<T,N> *that)
    {
        unsigned int v2;
        TSCArray *v3;
        unsigned int i;

        if ( this != that )
        {
            v2 = that->field_0;
            v3 = this;
            for ( i = 0; ; ++i )
            {
                v3 = (TSCArray *)((char *)v3 + 1);
                if ( i >= v2 )
                    break;
                HIBYTE(v3->field_0) = *((_BYTE *)&that->field_4 + i);
            }
            this->field_0 = v2;
        }
        return this;
    }
private:
    int field_0;
    T* field_4;
};
#endif //WARDEN_TSCARRAY_H
