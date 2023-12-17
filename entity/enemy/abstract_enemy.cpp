//
// Created by Егор Федоров on 08.12.2023.
//

#include "abstract_enemy.h"

bool AbstractEnemy::isAlive() {
    return health > 0;
}

size_t AbstractEnemy::getHealth() {
    return health;
}

void AbstractEnemy::dealDamage(size_t amount) {
    size_t actualDamage = std::min(amount, health);
    health -= actualDamage;
}

void AbstractEnemy::heal(size_t amount) {
    health += amount;
    health = std::min(health, maxHealth);
}

size_t AbstractEnemy::getMaxHealth() {
    return maxHealth;
}

void AbstractEnemy::upgradeMaxHealth(size_t amount) {
    maxHealth += amount;
}

size_t AbstractEnemy::getDamage() {
    return damage;
}

void AbstractEnemy::increaseDamage(size_t value) {
    damage += value;
}

void AbstractEnemy::decreaseDamage(size_t value) {
    size_t actualVal = std::min(value, damage);
    damage -= actualVal;
}


AbstractEnemy::AbstractEnemy(size_t x, size_t y, size_t health,
                             size_t maxHealth, size_t damage,
                             const std::shared_ptr<ChangeObserver>& observer, uint32_t textureID) : AbstractEntity(x, y, observer, textureID){
    this->health = health;
    this->damage = damage;
    this->maxHealth = maxHealth;
}

