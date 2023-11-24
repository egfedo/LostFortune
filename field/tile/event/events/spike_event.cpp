//
// Created by Егор Федоров on 17.10.2023.
//

#include "spike_event.h"

SpikeEvent::SpikeEvent(size_t damageAmt) : damageAmt(damageAmt) {

}

uint32_t SpikeEvent::eventHandler(PlayerHandler * instance) {
    instance->dealDamage(damageAmt);
    return 1;
}
