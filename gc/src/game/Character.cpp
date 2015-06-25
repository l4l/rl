#include <stdint.h>
#include "Character.h"
#include "Stats.h"

using namespace game;

Character::Character(CharType type) : _level(0), _type(type % CHARS_NUM) {
    switch (_type) {
        case WAR:
            setStats(WAR_BASE_STATS);
            break;
        case ARCH:
            setStats(ARCH_BASE_STATS);
            break;
        case ROG:
            setStats(ROG_BASE_STATS);
            break;
        case MAGE:
            setStats(MAGE_BASE_STATS);
            break;
        case CUSTOM:
        default:
            setStats(CUSTOM_BASE_STATS);
            break;
    }
    _hp = getMaxHp();
    _mp = getMaxMp();
}

Character::Character(int type) : Character((CharType)type) {}

Character::Character(CharType type, short lvl, int *diff) :
        Character(type) {
    _level = lvl;
    addStats(diff);
}

Character Character::pasrseData (const char *bytes) {
    int iter = 0;
    int type = bytes[iter++] % CHARS_NUM;
    int diff[STATS_NUM];
    short lvl = 0;
    for (int i = 0; i < STATS_NUM; i++) {
        int t = 0;
        for (int j = 0; j < sizeof(int32_t); j++) {
            t <<= sizeof(char);
            t += *(bytes + iter);
            iter++;
        }
        diff[i] = t;
    }

    for (int j = 0; j < sizeof(short); j++) {
        lvl <<= sizeof(char);
        lvl += *(bytes + iter);
        iter++;
    }
    return Character(CharType(type) , lvl, diff);
}

inline int Character::getMaxHp() {
    return _end * HP_PER_END;
}

inline int Character::getMaxMp() {
    return _sta * MP_PER_STA;
}

void Character::setStats(int Str, int Agi, int Sta, int Int, int End) {
    _str = Str;
    _agi = Agi;
    _sta = Sta;
    _int = Int;
    _end = End;
}

void Character::setStats(int *stats) {
    setStats(stats[0], stats[1], stats[2], stats[3], stats[4]);
}

void Character::addStats(int Str, int Agi, int Sta, int Int, int End) {
    _str += Str;
    _agi += Agi;
    _sta += Sta;
    _int += Int;
    _end += End;
}

void Character::addStats(int *stats) {
    addStats(stats[0], stats[1], stats[2], stats[3], stats[4]);
}

void Character::setHpMp(int hp, int mp) {
    _hp = hp;
    _mp = mp;
}
