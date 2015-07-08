#ifndef CLIENT_CONSTS_H
#define CLIENT_CONSTS_H

#define LOG_PORT 1028
#define GAME_PORT 1212
#define HOST "151.248.125.250"

namespace login {

    #define NICK_SIZE 128
    #define PASS_SIZE 127
    #define SEND_SIZE (NICK_SIZE+PASS_SIZE+1)

    #define SEND_LOGIN true
    #define SEND_REG !SEND_LOGIN


    #define TOKEN_SIZE 36
    #define ANS_SIZE (TOKEN_SIZE + 1)

    #define ANS_OK true
    #define ANS_BAD !ANS_OK
}

#endif //CLIENT_CONSTS_H
