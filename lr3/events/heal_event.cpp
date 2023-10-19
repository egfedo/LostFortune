//
// Created by Егор Федоров on 17.10.2023.
//

#include "heal_event.h"

HealEvent::HealEvent(size_t amt, size_t textureID) : healAmt(amt), textureID(textureID) {

}

void HealEvent::eventHandler(PlayerHandler * instance) {
    instance->heal(healAmt);
}

size_t HealEvent::getTextureID() const {
    return textureID;
}
