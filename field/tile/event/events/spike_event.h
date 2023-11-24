//
// Created by Егор Федоров on 17.10.2023.
//


#ifndef OOP_GAME_SPIKE_EVENT_H
#define OOP_GAME_SPIKE_EVENT_H

#include "../event_interface.h"

class SpikeEvent : public EventInterface {
private:
    size_t damageAmt;
public:
    SpikeEvent(size_t damageAmt);
    uint32_t eventHandler(PlayerHandler * instance) final;
};


#endif //OOP_GAME_SPIKE_EVENT_H
