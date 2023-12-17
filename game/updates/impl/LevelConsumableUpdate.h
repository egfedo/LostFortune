//
// Created by Егор Федоров on 26.11.2023.
//

#ifndef OOP_GAME_UPDATEECONSUMABLE_H
#define OOP_GAME_UPDATEECONSUMABLE_H


#include "../../../entity/player/player.h"
#include "../level_update_interface.h"

class LevelConsumableUpdate : public LevelUpdateInterface {
private:
    uint32_t change;
    Player::consumeID consumable;
    bool upFlag;
public:
    LevelConsumableUpdate(uint32_t change, Player::consumeID consumable, bool upFlag);
    void applyUpdate(std::shared_ptr<EntityHandler> prevState, std::shared_ptr<OutputInterface> output, StatContainer format, std::shared_ptr<Logger> logger) final;
};


#endif //OOP_GAME_UPDATEECONSUMABLE_H
