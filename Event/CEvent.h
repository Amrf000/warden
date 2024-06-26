#pragma once

#include "event/Types.h"
#include "Common/TRefCnt.h"
#include <cstdint>


class CEvent : public TRefCnt {
public:
    // Member variables
    uint32_t id;
    void *param;
};

class CCharEvent : public CEvent, public EVENT_DATA_CHAR {
public:
    // Member functions
    CCharEvent &operator=(const EVENT_DATA_CHAR &data);
};

class CKeyEvent : public CEvent, public EVENT_DATA_KEY {
public:
    // Member functions
    CKeyEvent &operator=(const EVENT_DATA_KEY &data);
};

class CMouseEvent : public CEvent, public EVENT_DATA_MOUSE {
public:
    // Member functions
    CMouseEvent &operator=(const EVENT_DATA_MOUSE &data);
};

class CSizeEvent : public CEvent, public EVENT_DATA_SIZE {
public:
    // Member functions
    CSizeEvent &operator=(const EVENT_DATA_SIZE &data);
};


