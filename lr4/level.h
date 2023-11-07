//
// Created by Егор Федоров on 05.11.2023.
//

#ifndef OOP_GAME_LEVEL_H
#define OOP_GAME_LEVEL_H

#include "input_interface.h"
#include "output_interface.h"
#include "../lr3/field_builder.h"
#include "../player_handler.h"
#include "../lr3/file_wrapper.h"
#include <unistd.h>
#include <iostream>
#include <ncurses.h>

class Level {
public:
    enum class Command {
        exit,
        death,
        win
    };
    Level::Command routine(size_t id, InputInterface* input, OutputInterface* output);
};


#endif //OOP_GAME_LEVEL_H
