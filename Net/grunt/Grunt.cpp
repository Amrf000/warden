#include "net/grunt/Grunt.h"

const char *Grunt::g_LoginResultStringNames[] = {
        "LOGIN_OK",
        "LOGIN_INVALID_CHALLENGE_MESSAGE",
        "LOGIN_SRP_ERROR",
        "LOGIN_INVALID_PROOF_MESSAGE",
        "LOGIN_BAD_SERVER_PROOF",
        "LOGIN_INVALID_RECODE_MESSAGE",
        "LOGIN_BAD_SERVER_RECODE_PROOF",
        "LOGIN_UNKNOWN_ACCOUNT",
        "LOGIN_UNKNOWN_ACCOUNT_PIN",
        "LOGIN_UNKNOWN_ACCOUNT_CALL",
        "LOGIN_INCORRECT_PASSWORD",
        "LOGIN_FAILED",
        "LOGIN_SERVER_DOWN",
        "LOGIN_BANNED",
        "LOGIN_BADVERSION",
        "LOGIN_ALREADYONLINE",
        "LOGIN_NOTIME",
        "LOGIN_DBBUSY",
        "LOGIN_SUSPENDED",
        "LOGIN_PARENTALCONTROL",
        "LOGIN_LOCKED_ENFORCED",
        "DISCONNECTED",
        "LOGIN_ACCOUNT_CONVERTED",
        "LOGIN_ANTI_INDULGENCE",
        "LOGIN_EXPIRED",
        "LOGIN_TRIAL_EXPIRED",
        "LOGIN_NO_GAME_ACCOUNT",
        "LOGIN_AUTH_OUTAGE",
        "LOGIN_GAME_ACCOUNT_LOCKED",
        "LOGIN_NO_BATTLENET_MANAGER",
        "LOGIN_NO_BATTLENET_APPLICATION",
        "LOGIN_MALFORMED_ACCOUNT_NAME",
        "LOGIN_USE_GRUNT",
        "LOGIN_TOO_FAST",
        "LOGIN_CHARGEBACK",
        "LOGIN_IGR_WITHOUT_BNET",
        "LOGIN_UNLOCKABLE_LOCK",
        "LOGIN_CONVERSION_REQUIRED",
        "LOGIN_UNABLE_TO_DOWNLOAD_MODULE",
        "LOGIN_NO_GAME_ACCOUNTS_IN_REGION",
        "LOGIN_ACCOUNT_LOCKED",
};

const char *Grunt::g_LoginStateStringNames[] = {
        "LOGIN_STATE_INITIALIZED",
        "LOGIN_STATE_CONNECTING",
        "LOGIN_STATE_HANDSHAKING",
        "LOGIN_STATE_AUTHENTICATING",
        "LOGIN_STATE_AUTHENTICATED",
        "LOGIN_STATE_FAILED",
        "LOGIN_STATE_DOWNLOADFILE",
        "LOGIN_STATE_FIRST_SECURITY",
        "LOGIN_STATE_PIN",
        "LOGIN_STATE_PIN_WAIT",
        "LOGIN_STATE_MATRIX",
        "LOGIN_STATE_MATRIX_WAIT",
        "LOGIN_STATE_TOKEN",
        "LOGIN_STATE_TOKEN_WAIT",
        "LOGIN_STATE_CHECKINGVERSIONS",
        "RESPONSE_CONNECTED",
        "LOGIN_STATE_DISCONNECTED",
        "LOGIN_STATE_SURVEY",
};
