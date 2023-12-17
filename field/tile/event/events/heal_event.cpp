//
// Created by Егор Федоров on 17.10.2023.
//

#include "heal_event.h"

HealEvent::HealEvent(size_t amt, uint32_t uses) : healAmt(amt), uses(uses) {

}

uint32_t HealEvent::eventHandler(AbstractEntity * instance, std::shared_ptr<Field> field, std::vector<std::vector<size_t>>& entityPos) {
    instance->heal(healAmt);
    uses--;
    return uses;
}
