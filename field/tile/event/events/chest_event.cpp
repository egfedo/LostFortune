//
// Created by Егор Федоров on 09.11.2023.
//

#include "chest_event.h"

ChestEvent::ChestEvent(Player::consumeID contents, uint32_t amount) : contents(contents),
    amount(amount) {}

uint32_t ChestEvent::eventHandler(PlayerHandler *instance) {
    instance->giveConsume(contents, amount);
    return 0;
}
