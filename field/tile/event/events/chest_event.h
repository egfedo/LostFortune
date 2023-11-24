//
// Created by Егор Федоров on 09.11.2023.
//

#ifndef OOP_GAME_CHEST_EVENT_H
#define OOP_GAME_CHEST_EVENT_H

#include "../event_interface.h"

class ChestEvent : public EventInterface {
private:
    Player::consumeID contents;
    uint32_t amount;
public:
    ChestEvent(Player::consumeID contents, uint32_t amount);
    uint32_t eventHandler(PlayerHandler *instance) final;
};


#endif //OOP_GAME_CHEST_EVENT_H
