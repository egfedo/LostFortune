//
// Created by Егор Федоров on 17.10.2023.
//

#include "spike_event.h"

SpikeEvent::SpikeEvent(size_t damageAmt) : damageAmt(damageAmt) {

}

uint32_t SpikeEvent::eventHandler(AbstractEntity * instance, std::shared_ptr<Field> field, std::vector<std::vector<size_t>>& entityPos) {
    instance->dealDamage(damageAmt);
    return 1;
}
