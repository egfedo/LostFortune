//
// Created by Егор Федоров on 05.11.2023.
//

#ifndef OOP_GAME_LEVEL_H
#define OOP_GAME_LEVEL_H

#include "../../input_output/input_interface.h"
#include "../../entity/player/player_handler.h"
#include "../change_observer.h"
#include "../../entity/entity_handler.h"
#include <unistd.h>
#include <iostream>
#include <ncurses.h>

class Level {
private:
    std::shared_ptr<EntityHandler> handler;

public:
    enum class Command {
        exit,
        death,
        win,
        close
    };
    explicit Level(std::shared_ptr<EntityHandler> handler);
    Level();
    Level::Command routine(InputInterface* input, const std::shared_ptr<ChangeObserver>& observer);

    Level(const Level& level);
    Level& operator = (const Level& field);
};


#endif //OOP_GAME_LEVEL_H
