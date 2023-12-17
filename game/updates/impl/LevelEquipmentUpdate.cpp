//
// Created by Егор Федоров on 26.11.2023.
//

#include "LevelEquipmentUpdate.h"

LevelEquipmentUpdate::LevelEquipmentUpdate(bool change, Player::equipID equipment) : change(change), equipment(equipment) {

}

void
LevelEquipmentUpdate::applyUpdate(std::shared_ptr<EntityHandler> prevState, std::shared_ptr<OutputInterface> output,
                                  StatContainer format, std::shared_ptr<Logger> logger) {
    auto playerHandler = prevState->getPlayer();
    if (playerHandler->checkEquip(equipment) == change)
        return;
    if (change)
        playerHandler->giveEquip(equipment);
    else
        playerHandler->removeEquip(equipment);
    format.add(equipment, change);
}

