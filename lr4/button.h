//
// Created by Егор Федоров on 05.11.2023.
//

#ifndef OOP_GAME_BUTTON_H
#define OOP_GAME_BUTTON_H

#include "button_action.h"
#include <string>

class Button {
public:
    std::string text;
    std::pair<std::string, std::string> action;

    Button(std::string text, std::pair<std::string, std::string> action);
};


#endif //OOP_GAME_BUTTON_H
