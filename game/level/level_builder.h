//
// Created by Егор Федоров on 12.11.2023.
//

#ifndef OOP_GAME_LEVEL_BUILDER_H
#define OOP_GAME_LEVEL_BUILDER_H


#include "level.h"
#include "../../input_output/line_stream.h"
#include "sstream"
#include "../../field/field_builder.h"

class LevelBuilder {
private:
    std::map<std::string, Player::equipID> string2equip = {
            {"sword", Player::equipID::sword},
            {"shield", Player::equipID::shield},
    };
public:
    Level buildLevel(LineStream* levelStream, LineStream* fieldStream);
};


#endif //OOP_GAME_LEVEL_BUILDER_H
