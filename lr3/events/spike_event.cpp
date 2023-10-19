//
// Created by Егор Федоров on 17.10.2023.
//

#include "spike_event.h"

SpikeEvent::SpikeEvent(size_t damageAmt, size_t textureID) : damageAmt(damageAmt), textureID(textureID) {

}

void SpikeEvent::eventHandler(PlayerHandler * instance) {
    instance->dealDamage(damageAmt);
}

size_t SpikeEvent::getTextureID() const {
    return textureID;
}