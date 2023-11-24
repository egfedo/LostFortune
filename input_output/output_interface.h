//
// Created by Егор Федоров on 05.11.2023.
//

#ifndef OOP_GAME_OUTPUT_INTERFACE_H
#define OOP_GAME_OUTPUT_INTERFACE_H

#include <string>
#include "../field/field.h"
#include "../player/player.h"

class OutputInterface {
public:
    virtual void displayMenu(std::string title, std::vector<std::string> buttons, size_t selected) = 0;
    virtual void displayLevel(Field& field, std::pair<size_t, size_t> playerLoc, Player& instance) = 0;
};


#endif //OOP_GAME_OUTPUT_INTERFACE_H
