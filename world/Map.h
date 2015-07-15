#ifndef CLIENT_MAP_H
#define CLIENT_MAP_H

#include "istream"
#include "string.h"

class Map {
public:
    Map(std::istream&);
    Map(Map&);
    Map(Map&, size_t width, size_t height, size_t x0, size_t y0);
    ~Map();

    std::string print();
private:
    size_t _width;
    size_t _height;
    char **_map;
};


#endif //CLIENT_MAP_H
