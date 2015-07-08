#ifndef CLIENT_USER_H
#define CLIENT_USER_H

#include "../net/Token.hpp"
#include "Character.h"

class User {
public:
    User(const Character*, const Token*);
    User operator=(const User&);
private:
    Character *_char;
    Token *_token;
};


#endif //CLIENT_USER_H
