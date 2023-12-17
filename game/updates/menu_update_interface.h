//
// Created by Егор Федоров on 27.11.2023.
//

#ifndef OOP_GAME_MENU_UPDATE_INTERFACE_H
#define OOP_GAME_MENU_UPDATE_INTERFACE_H

class Menu;

#include <memory>

class OutputInterface;

class MenuUpdateInterface {
public:
    virtual void applyUpdate(std::shared_ptr<Menu> prevState, std::shared_ptr<OutputInterface> output) = 0;
};

#include "../menu/menu.h"

#endif //OOP_GAME_MENU_UPDATE_INTERFACE_H
