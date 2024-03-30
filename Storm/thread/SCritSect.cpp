#include "storm/thread/SCritSect.h"

SCritSect::SCritSect() {
    InitializeCriticalSection(&this->m_opaqueData);
}

SCritSect::~SCritSect() {
    DeleteCriticalSection(&this->m_opaqueData);
}

void SCritSect::Enter() {
    EnterCriticalSection(&this->m_opaqueData);
}

void SCritSect::Leave() {
    LeaveCriticalSection(&this->m_opaqueData);
}
