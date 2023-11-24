//
// Created by Егор Федоров on 22.10.2023.
//

#ifndef OOP_GAME_FIELD_BUILDER_H
#define OOP_GAME_FIELD_BUILDER_H

#include "field.h"
#include "./tile/event/events/spike_event.h"
#include "./tile/event/events/portal_event.h"
#include "./tile/event/events/heal_event.h"
#include <fstream>
#include <sstream>
#include "../input_output/line_stream.h"
#include "./tile/event/events/chest_event.h"

class FieldBuilder {
private:
    static bool checkPassability(Field &instance);
    static void floodFill(Field& temp, std::pair<size_t, size_t> coords);
public:
    static int buildField(Field &templt, LineStream* ptr);
};


#endif //OOP_GAME_FIELD_BUILDER_H
