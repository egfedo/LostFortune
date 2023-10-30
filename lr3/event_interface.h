//
// Created by Егор Федоров on 17.10.2023.
//

#ifndef OOP_GAME_EVENT_INTERFACE_H
#define OOP_GAME_EVENT_INTERFACE_H

class EventInterface;

#include "../player_handler.h"

class EventInterface {
public:
    virtual void eventHandler(PlayerHandler* instance) = 0;
};


#endif //OOP_GAME_EVENT_INTERFACE_H
