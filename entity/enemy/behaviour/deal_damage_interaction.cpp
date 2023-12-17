//
// Created by Егор Федоров on 10.12.2023.
//

#include "deal_damage_interaction.h"

void DealDamageInteraction::interact(const std::shared_ptr<AbstractEntity> &target, const std::shared_ptr<Field> &field,
                                     AbstractEntity::Direction direction, std::vector<std::vector<size_t>> &entityPos,
                                     size_t possibleDmg) {
    target->dealDamage(possibleDmg);

}

DealDamageInteraction::DealDamageInteraction(size_t damage) : damage(damage) {

}

DealDamageInteraction::DealDamageInteraction() : DealDamageInteraction(5) {}
