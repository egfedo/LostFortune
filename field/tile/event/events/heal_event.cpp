//
// Created by Егор Федоров on 17.10.2023.
//

#include "heal_event.h"

HealEvent::HealEvent(size_t amt, uint32_t uses) : healAmt(amt), uses(uses) {

}

uint32_t HealEvent::eventHandler(PlayerHandler * instance) {
    instance->heal(healAmt);
    uses--;
    return uses;
}
