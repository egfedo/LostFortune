//
// Created by Егор Федоров on 17.10.2023.
//

#ifndef OOP_GAME_HEAL_EVENT_H
#define OOP_GAME_HEAL_EVENT_H

#include "../event_interface.h"

class HealEvent : public EventInterface {
private:
    size_t healAmt;
    size_t textureID;

public:
    HealEvent(size_t amt, size_t textureID);
    size_t getTextureID() const final;
    void eventHandler(PlayerHandler * instance) final;
};


#endif //OOP_GAME_HEAL_EVENT_H
