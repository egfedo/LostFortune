//
// Created by Егор Федоров on 10.12.2023.
//

#ifndef OOP_GAME_DEAL_DAMAGE_INTERACTION_H
#define OOP_GAME_DEAL_DAMAGE_INTERACTION_H

#include "../../entity.h"

class DealDamageInteraction {
private:
    size_t damage;
public:
    void interact(const std::shared_ptr<AbstractEntity>& target,
                  const std::shared_ptr<Field>& field,
                  AbstractEntity::Direction direction,
                  std::vector<std::vector<size_t>>& entityPos,
                  size_t possibleDmg);
    explicit DealDamageInteraction(size_t damage);
    DealDamageInteraction();
};


#endif //OOP_GAME_DEAL_DAMAGE_INTERACTION_H
