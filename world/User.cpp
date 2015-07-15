#include "User.h"

User::User(const Character *character, const Token *token) {
    _char = new Character(*character);
    _token = new Token(*token);
}

User User::operator=(const User &user) {
    return User(user._char, user._token);
}
