//
// Created by Егор Федоров on 26.11.2023.
//

#include "LevelPositionUpdate.h"
#include "../../../logging/message/impl/player_win_message.h"

#include <utility>

void
LevelPositionUpdate::applyUpdate(std::shared_ptr<EntityHandler> prevState, std::shared_ptr<OutputInterface> output,
                                 StatContainer format, std::shared_ptr<Logger> logger) {
    std::shared_ptr<AbstractEntity> entity = prevState->getEntity(entityID);
    if (entity->getCoord(AbstractEntity::Coord::X) != newCoords.first || entity->getCoord(AbstractEntity::Coord::Y) != newCoords.second) {
        entity->setCoords(newCoords.first, newCoords.second, prevState->getField(), prevState->getEntityPos());
        if (auto playerHandler = std::dynamic_pointer_cast<PlayerHandler>(entity)) {
            auto exit = prevState->getField()->getExit();
            if (newCoords.first == exit.first && newCoords.second == exit.second) {
                PlayerWinMessage msg(playerHandler->getHealth(),
                                     playerHandler->getMaxHealth(),
                                     playerHandler->getDamage(),
                                     playerHandler->getConsumeAmt(Player::consumeID::coins));
                logger->logMessage(&msg);
            }
        }
    }
}

LevelPositionUpdate::LevelPositionUpdate(std::pair<uint32_t, uint32_t> newCoords,
                                         size_t entityID) :
                                         newCoords(std::move(newCoords)), entityID(entityID) {}
