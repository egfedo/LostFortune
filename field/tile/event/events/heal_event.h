//
// Created by Егор Федоров on 17.10.2023.
//

#ifndef OOP_GAME_HEAL_EVENT_H
#define OOP_GAME_HEAL_EVENT_H

#include "../event_interface.h"

class HealEvent : public EventInterface {
private:
    size_t healAmt;
    uint32_t uses;
public:
    HealEvent(size_t amt, uint32_t uses);
    uint32_t eventHandler(AbstractEntity * instance, std::shared_ptr<Field> field, std::vector<std::vector<size_t>>& entityPos) final;
};


#endif //OOP_GAME_HEAL_EVENT_H
