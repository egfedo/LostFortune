//
// Created by Егор Федоров on 05.11.2023.
//

#ifndef OOP_GAME_TEST_OUTPUT_H
#define OOP_GAME_TEST_OUTPUT_H

#include "../output_interface.h"
#include <iostream>
#include "../../lr3/events/spike_event.h"
#include "../../lr3/events/heal_event.h"
#include "../../lr3/events/portal_event.h"
#include <ncurses.h>
#include <sstream>

class TestOutput : public OutputInterface {
public:
    void displayMenu(std::vector<std::string> buttons, size_t selected) final;
    void displayLevel(Field& field, std::pair<size_t, size_t> playerLoc, Player& instance) final;
};


#endif //OOP_GAME_TEST_OUTPUT_H
