//
// Created by Егор Федоров on 05.11.2023.
//

#ifndef OOP_GAME_GAME_H
#define OOP_GAME_GAME_H

#include "../lr3/field_builder.h"
#include "output_interface.h"
#include "input_interface.h"
#include "menu.h"
#include "level.h"

class Game {
private:
    enum class State {
        menu,
        ingame,
        exit
    };
    State gameState;
    size_t level;

public:
    void routine(OutputInterface* output, InputInterface* input);
};


#endif //OOP_GAME_GAME_H
