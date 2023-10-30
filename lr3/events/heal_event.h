//
// Created by Егор Федоров on 17.10.2023.
//

#ifndef OOP_GAME_HEAL_EVENT_H
#define OOP_GAME_HEAL_EVENT_H

#include "../event_interface.h"

class HealEvent : public EventInterface {
private:
    size_t healAmt;

public:
    HealEvent(size_t amt);
    void eventHandler(PlayerHandler * instance) final;
};


#endif //OOP_GAME_HEAL_EVENT_H
