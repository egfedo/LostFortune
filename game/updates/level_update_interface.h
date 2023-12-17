//
// Created by Егор Федоров on 26.11.2023.
//

#ifndef OOP_GAME_LEVEL_UPDATE_INTERFACE_H
#define OOP_GAME_LEVEL_UPDATE_INTERFACE_H


class LevelUpdateInterface;
class StatContainer;
class OutputInterface;
class PlayerHandler;
class EntityHandler;
#include <memory>
#include "../../logging/logger.h"


class LevelUpdateInterface {
public:
    virtual void applyUpdate(std::shared_ptr<EntityHandler> prevState, std::shared_ptr<OutputInterface> output, StatContainer format, std::shared_ptr<Logger> logger) = 0;
};

#include "../stat_formatter.h"
#include "../../input_output/output_interface.h"
#include "../../entity/player/player_handler.h"
#include "../../entity/entity_handler.h"

#endif //OOP_GAME_LEVEL_UPDATE_INTERFACE_H
