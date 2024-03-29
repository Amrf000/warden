#pragma once

#include "common.h"
#include <cstdint>

class CEvent : public TRefCnt {
public:
    CEvent(unsigned int eventId, void *eventData);

    CEvent(const CEvent &other);

    CEvent &operator=(const CEvent &other);

    virtual ~CEvent();

    virtual void HeadFree();

private:
    uint32_t eventId;
    void *eventData;
};


