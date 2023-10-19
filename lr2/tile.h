//
// Created by Егор Федоров on 01.10.2023.
//

#ifndef OOP_GAME_TILE_H
#define OOP_GAME_TILE_H

class Tile;

#include <cstdlib>
#include "../lr3/event_interface.h"

class Tile {
private:
    bool passable;
    size_t textureID;
    std::shared_ptr<EventInterface> event;

public:

    Tile();
    Tile(bool passable, size_t textureID);

    bool getPassability();
    void setPassability(bool state);

    size_t getTexture();
    void setTexture(size_t id);

    std::shared_ptr<EventInterface> getEvent();
    void setEvent(std::shared_ptr<EventInterface> event);

};


#endif //OOP_GAME_TILE_H
