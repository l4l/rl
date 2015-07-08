#ifndef CLIENT_TOKEN_H
#define CLIENT_TOKEN_H

#include "string"
#include "string.h"

#include "NetInf.h"

struct Token {

    Token(const Token& t) : token(t.token) {}
    Token(char c[]) : token(c) {}

    const std::string token;

    Token& operator=(Token& t) {
        Token tmp(t);
        return t;
    }

    bool operator==(Token& t) {
        return t.token == token;
    }
};

#endif //CLIENT_TOKEN_H
