// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

#include "TRefCnt.h"
#include "TSHashObject.h"
#include "HASHKEY_STR.h"
#include "CStringManager.h"

class CStringRep : public TRefCnt {
public:
    CStringRep();

    ~CStringRep();

    virtual void sub_2D557C() {
        CStringRep *result = &unk_F6BCE0;
        if (this != &unk_F6BCE0) {
            this->mReferenceCnt = this->mReferenceCnt - 1;
            if (!result) {
                CStringManager *v2 = CStringManager::getInstance();
                v2->Delete(this);
            }
        }
    }

private:
    TSHashObject <CStringRep, HASHKEY_STR> mObj;
    static CStringRep unk_F6BCE0;
};