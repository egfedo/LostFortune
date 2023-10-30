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
private:
    static bool checkPassability(Field &instance);
    static void floodFill(Field& temp, std::pair<size_t, size_t> coords);
public:
    static int buildField(size_t level, Field &templt);
};


#endif //OOP_GAME_FIELD_BUILDER_H
