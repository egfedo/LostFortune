//
// Created by Егор Федоров on 26.11.2023.
//

#ifndef OOP_GAME_LEVELEQUIPMENTUPDATE_H
#define OOP_GAME_LEVELEQUIPMENTUPDATE_H


#include "../../../entity/player/player.h"
#include "../level_update_interface.h"

class LevelEquipmentUpdate : public LevelUpdateInterface {
private:
    bool change;
    Player::equipID equipment;
public:
    LevelEquipmentUpdate(bool change, Player::equipID equipment);
    void applyUpdate(std::shared_ptr<EntityHandler> prevState, std::shared_ptr<OutputInterface> output, StatContainer format, std::shared_ptr<Logger> logger) final;
};


#endif //OOP_GAME_LEVELEQUIPMENTUPDATE_H
