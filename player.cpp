//
// Created by Егор Федоров on 27.09.2023.
//

#include "player.h"

size_t Player::getHealth() const {
    return health;
}

void Player::setHealth(size_t value) {
    health = std::min(value, maxHealth);
}

size_t Player::getMaxHealth() const {
    return maxHealth;
}

void Player::setMaxHealth(size_t value) {
    maxHealth = value;
}

size_t Player::getDamage() const {
    return damage;
}

void Player::setDamage(size_t value) {
    damage = value;
}

bool Player::checkEquip(equipID name) {
    return equipment.count(name);
}

void Player::setEquip(equipID name, bool state) {
    if (state)
        equipment.insert(name);
    else
        equipment.erase(name);
}

size_t Player::getConsAmt(consumeID name) {
    if (consumables.contains(name))
        return consumables[name];
    else
        return 0;
}

void Player::setConsAmt(consumeID name, size_t amount) {
    consumables[name] = amount;
}

Player::Player(size_t health, size_t maxHealth, size_t damage) : health(health),
    maxHealth(maxHealth), damage(damage) {}
