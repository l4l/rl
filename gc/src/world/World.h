#ifndef CLIENT_WORLD_H
#define CLIENT_WORLD_H

#include "vector"

#include "Map.h"
#include "User.h"

class World {
public:
    World(Map*, size_t);
    World(Map*, size_t, std::vector<User>);
    ~World();
private:
    size_t _num;
    const Map **_maps;
    std::vector<User> _users;
};


#endif //CLIENT_WORLD_H
