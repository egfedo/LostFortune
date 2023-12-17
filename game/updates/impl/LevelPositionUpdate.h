//
// Created by Егор Федоров on 26.11.2023.
//

#ifndef OOP_GAME_LEVELPOSITIONUPDATE_H
#define OOP_GAME_LEVELPOSITIONUPDATE_H


#include "../level_update_interface.h"

class LevelPositionUpdate : public LevelUpdateInterface {
private:
    std::pair<uint32_t, uint32_t> newCoords;
    size_t entityID;
public:
    LevelPositionUpdate(std::pair<uint32_t, uint32_t> newCoords, size_t entityID);
    void applyUpdate(std::shared_ptr<EntityHandler> prevState, std::shared_ptr<OutputInterface> output, StatContainer format, std::shared_ptr<Logger> logger) final;
};


#endif //OOP_GAME_LEVELPOSITIONUPDATE_H
