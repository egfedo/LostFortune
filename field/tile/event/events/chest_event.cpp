//
// Created by Егор Федоров on 09.11.2023.
//

#include "chest_event.h"
#include "../../../../entity/player/player_handler.h"

ChestEvent::ChestEvent(Player::consumeID contents, uint32_t amount) : contents(contents),
    amount(amount) {}

uint32_t ChestEvent::eventHandler(AbstractEntity *instance, std::shared_ptr<Field> field, std::vector<std::vector<size_t>>& entityPos) {
    if(auto player = dynamic_cast<PlayerHandler*>(instance)) {
        player->giveConsume(contents, amount);
        return 0;
    }
    else
        return 1;
}

Player::consumeID ChestEvent::consumeType() const {
    return contents;
}
