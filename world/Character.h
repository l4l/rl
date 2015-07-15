#ifndef CLIENT_CHARACTER_H
#define CLIENT_CHARACTER_H

#include <stdint.h>
#include "Stats.h"
#include "Chars.h"

class Character {
public:
    Character(game::CharType&);
    Character(int);
    Character(game::CharType, short, int*);

    Character pasrseData(const char *);

    int getMaxHp();
    int getMaxMp();

private:
    void setStats(int, int, int, int, int);
    void setStats(int*);

    void addStats(int, int, int, int, int);
    void addStats(int*);

    void setHpMp(int, int);

    game::CharType _type;
    short _level;

    int _hp;
    int _mp;

    int _str;
    int _agi;
    int _sta;
    int _int;
    int _end;
};


#endif //CLIENT_CHARACTER_H
