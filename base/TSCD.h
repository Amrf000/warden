// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/16.
//

#ifndef WARDEN_TSCD_H
#define WARDEN_TSCD_H

template<typename T>
class TSCD {
public:
    void CopyConstruct(T *destination, const T *source) {
        if (destination != nullptr) {
            *destination = (source != nullptr) ? *source : T();
        }
    }

    void Construct(T *ptr) {
        if (ptr != nullptr) {
            new(ptr) T(); // 调用 T 的默认构造函数
        }
    }
};

#endif //WARDEN_TSCD_H
