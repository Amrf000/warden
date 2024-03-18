// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/16.
//

#ifndef WARDEN_TREFCNT_H
#define WARDEN_TREFCNT_H


class TRefCnt {
public:
    TRefCnt();

//    TRefCnt(const TRefCnt &other);
//
//    TRefCnt &operator=(const TRefCnt &other);

    virtual bool SafeRelease();

    virtual ~TRefCnt();

    virtual void HeadFree();

    void DecrRef();

private:
    int refCount;
};


#endif //WARDEN_TREFCNT_H
