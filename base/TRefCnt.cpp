// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/16.
//

#include "TRefCnt.h"
#include "memory.h"

TRefCnt::TRefCnt() : refCount(0) {}

//TRefCnt::TRefCnt(const TRefCnt &other) : refCount(1) {
//    other.refCount++;
//}
//
//TRefCnt &TRefCnt::operator=(const TRefCnt &other) {
//    if (this != &other) {
//        this->DecrRef();
//        other.refCount++;
//    }
//    return *this;
//}

bool TRefCnt::SafeRelease() {
    if (this == nullptr) {
        return false;
    } else {
        this->~TRefCnt();
        return true;
    }
}

TRefCnt::~TRefCnt() {

}

void TRefCnt::HeadFree() {
    if (this) {
        DeallocateMemory(this);
    }
}

void TRefCnt::DecrRef() {
    // 减少引用计数
    refCount = refCount - 1;

    // 如果引用计数变为零，则执行析构函数
    if (refCount == 0) {
        this->SafeRelease();
        return;
    }

    return;
}





