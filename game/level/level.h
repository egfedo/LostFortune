//
// Created by Егор Федоров on 05.11.2023.
//

#ifndef OOP_GAME_LEVEL_H
#define OOP_GAME_LEVEL_H

#include "../../input_output/input_interface.h"
#include "../../input_output/output_interface.h"
#include "../../field/field_builder.h"
#include "../../player/player_handler.h"
#include "../../input_output/implementations/file_wrapper.h"
#include <unistd.h>
#include <iostream>
#include <ncurses.h>

class Level {
private:
    std::shared_ptr<PlayerHandler> handler;

public:
    enum class Command {
        exit,
        death,
        win
    };
    Level(std::shared_ptr<PlayerHandler> handler);
    Level();
    Level::Command routine(InputInterface* input, OutputInterface* output);

    Level(const Level& level);
    Level& operator = (const Level& field);
};


#endif //OOP_GAME_LEVEL_H
