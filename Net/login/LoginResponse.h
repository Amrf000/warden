#pragma once

#include "net/Types.h"
#include "Common/TSFixedArray.h"


class CDataStore;

class LoginResponse {
public:
    // Member variables
    TSFixedArray <REALM_INFO> m_realmList;
    uint32_t uint10;
    LOGIN_STATE m_loginState;
    LOGIN_RESULT m_loginResult;

    // Virtual member functions
    virtual int32_t GetLoginServerType() = 0;

    virtual void LoginServerStatus(LOGIN_STATE state, LOGIN_RESULT result, const char *addrStr, const char *stateStr,
                                   const char *resultStr, uint8_t flags) = 0;

    virtual void RealmEnumCallback(uint32_t a2) = 0;

    // Member functions
    void HandleRealmData(uint32_t a2, CDataStore *msg);

    void UpdateLoginStatus(LOGIN_STATE state, LOGIN_RESULT result, const char *addrStr, uint16_t flags);
};


