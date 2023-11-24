//
// Created by Егор Федоров on 17.10.2023.
//

#ifndef OOP_GAME_EVENT_INTERFACE_H
#define OOP_GAME_EVENT_INTERFACE_H

#include <string>

class EventInterface;
class PlayerHandler;

class EventInterface {
public:
    virtual uint32_t eventHandler(PlayerHandler* instance) = 0;
};

#include "../../../player/player_handler.h"


#endif //OOP_GAME_EVENT_INTERFACE_H
