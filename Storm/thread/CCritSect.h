#ifndef STORM_THREAD_C_CRIT_SECT_HPP
#define STORM_THREAD_C_CRIT_SECT_HPP

#include <cstdint>
#include <windows.h>


class CCritSect {
public:
    // Member functions
    CCritSect();

    ~CCritSect();

    void Enter();

    void Enter(int32_t forWriting);

    void Leave();

    void Leave(int32_t fromWriting);

private:
    // Member variables
    CRITICAL_SECTION m_critsect;
};

#endif
