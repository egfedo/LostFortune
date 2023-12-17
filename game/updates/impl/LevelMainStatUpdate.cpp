//
// Created by Егор Федоров on 26.11.2023.
//

#include "LevelMainStatUpdate.h"
#include "../../../logging/message/impl/player_lost_message.h"

LevelMainStatUpdate::LevelMainStatUpdate(uint32_t change, LevelMainStatUpdate::Stat stat, bool upFlag) : change(change), stat(stat), upFlag(upFlag) {}

void LevelMainStatUpdate::applyUpdate(std::shared_ptr<EntityHandler> prevState, std::shared_ptr<OutputInterface> output,
                                      StatContainer format, std::shared_ptr<Logger> logger) {
    uint32_t prevStat;
    auto playerHandler = prevState->getPlayer();
    switch(stat) {
        case Stat::health:
            prevStat = playerHandler->getHealth();
            if (upFlag)
                playerHandler->heal(change);
            else
                playerHandler->dealDamage(change);
            if (playerHandler->getHealth() != prevStat)
                format.add(StatContainer::MainStat::health, playerHandler->getHealth());
            if (!playerHandler->isAlive()) {
                PlayerLostMessage msg(playerHandler->getCoord(PlayerHandler::Coord::X),
                                      playerHandler->getCoord(PlayerHandler::Coord::Y));
                logger->logMessage(&msg);
            }
            break;

        case Stat::maxHealth:
            playerHandler->upgradeMaxHealth(change);
            format.add(StatContainer::MainStat::maxHealth, playerHandler->getMaxHealth());
            break;
        case Stat::damage:
            prevStat = playerHandler->getDamage();
            if (upFlag)
                playerHandler->increaseDamage(change);
            else
                playerHandler->decreaseDamage(change);
            if (playerHandler->getDamage() != prevStat)
                format.add(StatContainer::MainStat::damage, playerHandler->getDamage());
            break;
    }
}

