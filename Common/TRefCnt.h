#pragma once

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



