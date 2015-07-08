#ifndef CLIENT_LOGINER_H
#define CLIENT_LOGINER_H

#include "LoginAnswer.h"
#include "LoginSend.h"
#include "LoginAnswer.h"
#include "string"

char* transfer(const std::string host, short port,
               const std::string user, const std::string pass, bool isLogin);

#endif //CLIENT_LOGINER_H
