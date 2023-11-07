//
// Created by Егор Федоров on 05.11.2023.
//

#ifndef OOP_GAME_MENU_H
#define OOP_GAME_MENU_H

#include <iostream>
#include "output_interface.h"
#include "input_interface.h"
#include "button.h"
#include <unistd.h>

class Menu {
private:
    std::string title;
    std::vector<Button> buttons;
    size_t current;
public:
    Menu(std::string title, std::vector<Button> buttons);
    Menu() = default;
    std::pair<std::string, std::string> routine(OutputInterface* output, InputInterface* input);
};


#endif //OOP_GAME_MENU_H
