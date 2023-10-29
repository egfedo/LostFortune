//
// Created by Егор Федоров on 22.10.2023.
//

#ifndef OOP_GAME_FIELD_BUILDER_H
#define OOP_GAME_FIELD_BUILDER_H

#include "../lr2/field.h"
#include "./events/spike_event.h"
#include "./events/portal_event.h"
#include "./events/heal_event.h"
#include <fstream>
#include <sstream>

class FieldBuilder {
public:
    enum class Level {
        first, second
    };
    static int buildField(Level level, Field &templt);
};


#endif //OOP_GAME_FIELD_BUILDER_H
