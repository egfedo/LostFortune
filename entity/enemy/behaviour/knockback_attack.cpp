//
// Created by Егор Федоров on 10.12.2023.
//

#include "knockback_attack.h"

void KnockbackAttack::interact(const std::shared_ptr<AbstractEntity>& target,
                               const std::shared_ptr<Field>& field,
                               AbstractEntity::Direction direction,
                               std::vector<std::vector<size_t>>& entityPos,
                               size_t possibleDmg) {
    if (target->move(direction, field, entityPos) != AbstractEntity::MoveResult::success) {
        target->dealDamage(possibleDmg);
    }
}

KnockbackAttack::KnockbackAttack(size_t possibleDamage) : possibleDamage(possibleDamage) {}

KnockbackAttack::KnockbackAttack() : KnockbackAttack(5) {

}
