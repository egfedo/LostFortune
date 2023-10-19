//
// Created by Егор Федоров on 01.10.2023.
//

#ifndef OOP_GAME_FIELD_H
#define OOP_GAME_FIELD_H
class Field;
#include "tile.h"
#include <utility>
#include <algorithm>

#define MIN_SIZE 5
#define DEF_WIDTH 15
#define DEF_HEIGHT 12

class Field {
private:
    Tile** array;
    size_t width, height;
    std::pair<size_t, size_t> entrance;
    std::pair<size_t, size_t> exit;

public:

    Field(size_t width, size_t height);
    Field(size_t width, size_t height, std::pair<size_t, size_t> entrance,
          std::pair<size_t, size_t> exit, Tile tile);
    Field();

    ~Field();

    Tile getTile(size_t x, size_t y);
    void setTile(size_t x, size_t y, Tile tile);

    std::pair<size_t, size_t> getEntrance();
    std::pair<size_t, size_t> getExit();

    size_t getWidth();
    size_t getHeight();

    // bebra

    Field(const Field& field);
    Field& operator = (const Field& field);

    Field(Field&& field);
    Field& operator = (Field&& field);
};


#endif //OOP_GAME_FIELD_H
