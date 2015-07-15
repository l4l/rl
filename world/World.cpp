#include "World.h"

World::World(Map* maps, size_t size) : _num(size) {
    for (int i = 0; i < size; ++i)
        _maps[i] = new Map(maps[i]);
}

World::World(Map* maps, size_t size, std::vector<User> users) :
        World(maps, size) {
    _users = users;
}

World::~World() {
    _users.~vector();
    for (int i = 0; i < _num; ++i) {
        delete[] _maps;
    }
}
