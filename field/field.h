//
// Created by Егор Федоров on 01.10.2023.
//

#ifndef OOP_GAME_FIELD_H
#define OOP_GAME_FIELD_H

class Field;
#include "tile/tile.h"
#include <utility>
#include <algorithm>
#include "tile/event/events/heal_event.h"
#include "tile/event/events/spike_event.h"
#include "tile/event/events/portal_event.h"
#include "tile/event/events/chest_event.h"

#define MIN_SIZE 5
#define DEF_WIDTH 20
#define DEF_HEIGHT 17

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

    Field(const Field& field);
    Field& operator = (const Field& field);

    Field(Field&& field);
    Field& operator = (Field&& field);
};


#endif //OOP_GAME_FIELD_H