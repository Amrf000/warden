// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/18.
//

#ifndef WARDEN_TSSTATICDYNAMICARRAY_H
#define WARDEN_TSSTATICDYNAMICARRAY_H

template<typename T, int N>
class TSStaticDynamicArray {
public:
    TSStaticDynamicArray() {
        this->field_0 = 0;
        this->field_4 = 0;
        this->field_8 = 0;
    }

    ~TSStaticDynamicArray() {
        for (int result = 0; result < this->field_4; ++result);
        if (this->field_0 > 0x200u)
            return sub_B766(this->field_8);
    }

    unsigned int Add(unsigned int a2, int *a3) {
        int v4;
        unsigned int i;

        Reserve(a2, 1);
        for (i = 0; i < a2; ++i)
            sub_71D008(this->field_8 + 4 * (this->field_4 + i), a3++);
        v4 = this->field_4 + a2;
        this->field_4 = v4;
        return v4 - a2;
    }

    int Reserve(unsigned int a2, int a3) {
        int result;
        unsigned int v4;

        result = a3;
        v4 = a2 + this->field_4;
        if (v4 > this->field_0) {
            if (a3 && v4 > 0x200 && (v4 & 0x3F) != 0)
                v4 += 64 - (v4 & 0x3F);
            return ReallocData(v4);
        }
        return result;
    }

    TSStaticDynamicArray *ReallocData(unsigned int a2) {
        int v2; // esi
        unsigned int i; // eax
        void *v4; // eax
        TSStaticDynamicArray *result; // eax
        unsigned int v6; // edi
        int v7; // esi
        TSStaticDynamicArray *v8; // [esp+28h] [ebp-20h]
        unsigned int v9; // [esp+2Ch] [ebp-1Ch]

        v2 = a2;
        v8 = (TSStaticDynamicArray *) this->field_8;
        for (i = a2; i < this->field_4; ++i);
        if (a2 <= 0x200) {
            v4 = &this->field_C;
            if (v8 == (TSStaticDynamicArray *) &this->field_C) {
                result = this;
                this->field_0 = a2;
                return result;
            }
        } else if (this->field_0 > 0x200u) {
            result = (TSStaticDynamicArray *) sub_B4C8(v8, 4 * a2, "nothing", -2, 16);
            this->field_8 = (int) result;
            if (result) {
                this->field_0 = a2;
                return result;
            }
            v4 = sub_B3FE(4 * a2, (int) "nothing", -2, 0);
        } else {
            v4 = sub_B3FE(4 * a2, (int) "nothing", -2, 0);
        }
        this->field_8 = (int) v4;
        result = this;
        this->field_0 = a2;
        if (v8) {
            if (a2 >= this->field_4)
                v2 = this->field_4;
            v9 = v2;
            v6 = 0;
            v7 = 0;
            while (v6 < v9) {
                sub_71D008(this->field_8 + v7, (char *) v8 + v7);
                ++v6;
                v7 += 4;
            }
            result = (TSStaticDynamicArray *) &this->field_C;
            if (v8 != (TSStaticDynamicArray *) &this->field_C)
                return (TSStaticDynamicArray *) sub_B766((int) v8);
        }
        return result;
    }
};

#endif //WARDEN_TSSTATICDYNAMICARRAY_H
