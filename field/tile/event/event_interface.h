//
// Created by Егор Федоров on 17.10.2023.
//

#ifndef OOP_GAME_EVENT_INTERFACE_H
#define OOP_GAME_EVENT_INTERFACE_H

#include <string>

class EventInterface;
class AbstractEntity;
class Field;

class EventInterface {
public:
    virtual uint32_t eventHandler(AbstractEntity* instance, std::shared_ptr<Field> field, std::vector<std::vector<size_t>>& entityPos) = 0;
};

#include "../../../entity/entity.h"
#include "../../field.h"

#endif //OOP_GAME_EVENT_INTERFACE_H
