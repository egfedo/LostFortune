//
// Created by Егор Федоров on 26.11.2023.
//

#include "LevelConsumableUpdate.h"

LevelConsumableUpdate::LevelConsumableUpdate(uint32_t change, Player::consumeID consumable, bool upFlag) : change(change), consumable(consumable), upFlag(upFlag) {

}

void
LevelConsumableUpdate::applyUpdate(std::shared_ptr<EntityHandler> prevState, std::shared_ptr<OutputInterface> output,
                                   StatContainer format, std::shared_ptr<Logger> logger) {
    auto playerHandler = prevState->getPlayer();
    uint32_t prevValue = playerHandler->getConsumeAmt(consumable);
    if (upFlag)
        playerHandler->giveConsume(consumable, change);
    else
        playerHandler->removeConsume(consumable, change);
    if (prevValue != playerHandler->getConsumeAmt(consumable))
        format.add(consumable, playerHandler->getConsumeAmt(consumable));
}