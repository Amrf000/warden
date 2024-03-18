// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/17.
//

#ifndef WARDEN_TSBASEARRAY_H
#define WARDEN_TSBASEARRAY_H

template<typename T>
class TSBaseArray {
public:
    void *Ptr() {
        return this->data;
    }

    T *operator[](int index) {
        return (int) this->data + sizeof(T) * index;
    }

private:
    int elementSize;
    int cnt;
    void *data;
};

#endif //WARDEN_TSBASEARRAY_H
