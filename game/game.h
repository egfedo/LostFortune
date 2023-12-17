//
// Created by Егор Федоров on 05.11.2023.
//

#ifndef OOP_GAME_GAME_H
#define OOP_GAME_GAME_H

#include "../field/field_builder.h"
#include "../input_output/output_interface.h"
#include "../input_output/input_interface.h"
#include "menu/menu.h"
#include "level/level.h"

class Game {
private:
    enum class State {
        menu,
        ingame,
        exit
    };
    State gameState;
    size_t level;
    std::map<std::string, Menu> menus;
    std::vector<Level> levels;

public:
    Game(std::map<std::string, Menu> menus, std::vector<Level> levels);
    void routine(std::shared_ptr<ChangeObserver> observer, InputInterface* input);
};


#endif //OOP_GAME_GAME_H
