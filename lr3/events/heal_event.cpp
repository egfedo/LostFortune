//
// Created by Егор Федоров on 17.10.2023.
//

#include "heal_event.h"

HealEvent::HealEvent(size_t amt) : healAmt(amt) {

}

void HealEvent::eventHandler(PlayerHandler * instance) {
    instance->heal(healAmt);
}
