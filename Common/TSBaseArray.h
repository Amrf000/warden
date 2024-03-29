#pragma once


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
    int capacity;
    int cnt;
    void *data;
};

