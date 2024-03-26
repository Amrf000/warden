// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.


#ifndef WARDEN_TSCARRAY_H
#define WARDEN_TSCARRAY_H

template<typename T, int N>
class TSCArray {
public:
    TSCArray() : cnt(N) {
        T **v1 = &this->data;
        for (int i = N - 2; i != -2; --i) {
            *v1 = new T();
            v1 += sizeof(T);
        }
    }

    TSCArray(TSCArray &that) : cnt(that.cnt) {
        for (unsigned int i = 0; i < that.cnt; ++i) {
            this->data[i] = that.data[i];
        }
    }

    TSCArray &operator=(const TSCArray &that) {
        if (this != &that) {
            for (unsigned int i = 0; i < that.cnt; ++i) {
                this->data[i] = &that.data[i];
            }
            this->cnt = that.cnt;
        }
        return *this;
    }

private:
    int cnt;
    T *data;
};

#endif //WARDEN_TSCARRAY_H
