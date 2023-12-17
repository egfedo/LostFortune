//
// Created by Егор Федоров on 05.11.2023.
//

#ifndef OOP_GAME_MENU_H
#define OOP_GAME_MENU_H

class Menu;

#include <iostream>
#include "../../input_output/output_interface.h"
#include "../../input_output/input_interface.h"
#include "button.h"
#include <unistd.h>
#include "../updates/impl/MenuUpdateButtonSelect.h"

class Menu {
private:
    std::string title;
    std::vector<Button> buttons;
    size_t current;
public:
    Menu(std::string title, std::vector<Button> buttons);
    Menu() = default;
    std::pair<std::string, std::string> routine(std::shared_ptr<ChangeObserver> observer, InputInterface* input);
    std::string getTitle();
    std::vector<Button> getButtons();
    size_t getCurrent();
    void moveCurrent(InputInterface::Command dir, std::shared_ptr<ChangeObserver> observer);
};


#endif //OOP_GAME_MENU_H
