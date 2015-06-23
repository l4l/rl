#ifndef CLIENT_LOGINANSWER_H
#define CLIENT_LOGINANSWER_H

#include "../Consts.h"

namespace login {

struct LoginAnswer {

    // ANS_OK, ANS_BAD
    bool answer = ANS_BAD;

    char *token = nullptr;
};

}

#endif //CLIENT_LOGINANSWER_H
