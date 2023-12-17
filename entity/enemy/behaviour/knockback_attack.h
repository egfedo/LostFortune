//
// Created by Егор Федоров on 10.12.2023.
//

#ifndef OOP_GAME_KNOCKBACK_ATTACK_H
#define OOP_GAME_KNOCKBACK_ATTACK_H

#include <memory>
#include "../../entity.h"

class KnockbackAttack {
private:
    size_t possibleDamage;
public:
    void interact(const std::shared_ptr<AbstractEntity>& target,
                  const std::shared_ptr<Field>& field,
                  AbstractEntity::Direction direction,
                  std::vector<std::vector<size_t>>& entityPos,
                  size_t possibleDmg);
    KnockbackAttack(size_t possibleDamage);
    KnockbackAttack();
};


#endif //OOP_GAME_KNOCKBACK_ATTACK_H
