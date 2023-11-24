//
// Created by Егор Федоров on 11.11.2023.
//

#ifndef OOP_GAME_MENU_BUILDER_H
#define OOP_GAME_MENU_BUILDER_H

#include "menu.h"
#include "../../input_output/line_stream.h"
#include <sstream>

class MenuBuilder {
public:
    static Menu buildMenu(LineStream* stream);
};


#endif //OOP_GAME_MENU_BUILDER_H
