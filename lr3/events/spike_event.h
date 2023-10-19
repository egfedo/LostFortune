//
// Created by Егор Федоров on 17.10.2023.
//


#ifndef OOP_GAME_SPIKE_EVENT_H
#define OOP_GAME_SPIKE_EVENT_H

#include "../event_interface.h"

class SpikeEvent : public EventInterface {
private:
    size_t damageAmt;
    size_t textureID;
public:
    SpikeEvent(size_t damageAmt, size_t textureID);
    size_t getTextureID() const override;
    void eventHandler(PlayerHandler * instance) override;
};


#endif //OOP_GAME_SPIKE_EVENT_H
