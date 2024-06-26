#pragma once

#include "net/grunt/Grunt.h"
#include "net/Types.h"

class CDataStore;

class LoginResponse;

class Grunt::ClientResponse {
public:
    virtual bool Connected(const NETADDR &addr) = 0;

    virtual bool OnlineIdle() = 0;

    virtual void GetLogonMethod() = 0;

    virtual void GetVersionProof(const uint8_t *versionChallenge) = 0;

    virtual void SetPinInfo(bool enabled, uint32_t a3, const uint8_t *a4) = 0;

    virtual void
    SetMatrixInfo(bool enabled, uint8_t a3, uint8_t a4, uint8_t a5, uint8_t a6, bool a7, uint8_t a8, uint64_t a9,
                  const uint8_t *a10, uint32_t a11) = 0;

    virtual void SetTokenInfo(bool enabled, uint8_t required) = 0;

    virtual void LogonResult(Result result, const uint8_t *sessionKey, uint32_t sessionKeyLen, uint16_t flags) = 0;

    virtual void RealmListResult(CDataStore *msg) = 0;

    virtual LOGIN_STATE NextSecurityState(LOGIN_STATE state) = 0;

    virtual int32_t GetServerId() = 0;

    virtual void GetRealmList() = 0;

    virtual void Logon(const char *a2, const char *a3) = 0;

    virtual void ProveVersion(const uint8_t *versionChecksum) = 0;

    virtual void Logoff() = 0;

    virtual void Init(LoginResponse *loginResponse) = 0;

    virtual int32_t GetLoginServerType() = 0;
};


