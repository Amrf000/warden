// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/18.
//

#ifndef WARDEN_TSEXPLICITLIST_H
#define WARDEN_TSEXPLICITLIST_H

#include "TSGetExplicitLink.h"
#include "TSList.h"

template<typename T, int N>
class TSExplicitList : public TSList<T, TSGetExplicitLink<T>> {
public:
    TSExplicitList() {
        this->field_0 = -572662307;
        this->field_4 = (int) &this->field_4;
        this->field_8 = (unsigned int) &this->field_4 | 1;
    }

    TSExplicitList(TSExplicitList *that) : TSList<T, TSGetExplicitLink<T>>(that) {
    }
};

#endif //WARDEN_TSEXPLICITLIST_H
