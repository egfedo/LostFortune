//
// Created by Егор Федоров on 26.11.2023.
//

#ifndef OOP_GAME_LEVELMAINSTATUPDATE_H
#define OOP_GAME_LEVELMAINSTATUPDATE_H


#include "../level_update_interface.h"

class LevelMainStatUpdate : public LevelUpdateInterface {


public:
    enum class Stat {
        health, maxHealth, damage
    };
    LevelMainStatUpdate(uint32_t change, Stat stat, bool upFlag);
    void applyUpdate(std::shared_ptr<EntityHandler> prevState, std::shared_ptr<OutputInterface> output, StatContainer format, std::shared_ptr<Logger> logger) final;

private:
    uint64_t change;
    Stat stat;
    bool upFlag;
};


#endif //OOP_GAME_LEVELMAINSTATUPDATE_H
