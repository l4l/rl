#ifndef CLIENT_LOGINSEND_H
#define CLIENT_LOGINSEND_H

#include "NetInf.h"

namespace login {

struct LoginSend {

    // SEND_LOGIN - log in; SEND_REG - register
    bool loginFlag;

    char user[NICK_SIZE];
    char pass[PASS_SIZE];
};

};
#endif //CLIENT_LOGINSEND_H
