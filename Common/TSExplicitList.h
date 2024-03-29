#pragma once

#include "TSGetExplicitLink.h"
#include "TSList.h"

template<typename T, size_t offset>
class TSExplicitList : public TSList<T, TSGetExplicitLink<T>> {
public:
    TSExplicitList() : TSList<T, TSGetExplicitLink<T>>() {
        this->SetLinkOffset(offset);
    }

    TSExplicitList(const TSExplicitList &that) : TSList<T, TSGetExplicitLink<T>>(that) {
    }
};


