#pragma once


#include <windows.h>


class SCritSect {
public:
    // Member variables

    CRITICAL_SECTION m_opaqueData;

    // Member functions
    SCritSect();

    ~SCritSect();

    void Enter();

    void Leave();
};


