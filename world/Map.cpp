#include "Map.h"

Map::Map(std::istream &in) {
    char t[1024];
    in.getline(t, 1024);
    _width = strlen(t);
    strcpy(_map[0], t);
    _height = 1;
    char buf[_width];
    while (in.getline(buf, _width)) {
        strcpy(_map[_height], buf);
        _height++;
    }
}

Map::Map(Map &map) : _width(map._width), _height(map._height) {
    for (int i = 0; i < _height; i++)
        strcpy(_map[i], map._map[i]);
}

Map::Map(Map &map, size_t width, size_t height, size_t x0, size_t y0) {
    _height = height;
    _width = width;
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            _map[i][j] = map._map[i+x0][j+y0];
}

Map::~Map() {
    for (int i = 0; i < _height; i++)
        delete[] _map;
}

std::string Map::print() {
    char buf[_width*_height + _width];
    for (int i = 0, s = 0; i < _width; i++) {
        for (int j = 0; j < _height; j++) {
            buf[s++] = _map[i][j];
        }
        buf[s++] = '\n';
    }

}
