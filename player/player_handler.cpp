//
// Created by Егор Федоров on 27.09.2023.
//

#include "player_handler.h"
#include <iostream>

PlayerHandler::PlayerHandler(size_t x, size_t y, Player &instance, Field& field) :
    x(x), y(y), player(instance), field(field) {}

size_t PlayerHandler::getCoord(PlayerHandler::Coord n) const {
    switch (n) {
        case PlayerHandler::Coord::X:
            return x;
        case PlayerHandler::Coord::Y:
            return y;
    }
}

void PlayerHandler::setCoord(PlayerHandler::Coord n, size_t value) {
    size_t nx, ny;
    nx = x;
    ny = y;
    switch (n) {
        case PlayerHandler::Coord::X:
            nx = value;
        case PlayerHandler::Coord::Y:
            ny = value;
    }
    nx = std::min(x, field.getWidth() - 1);
    ny = std::min(y, field.getHeight() - 1);
    updateCoords(nx, ny);
}

void PlayerHandler::setCoords(size_t x, size_t y) {
    size_t nx, ny;
    nx = std::min(x, field.getWidth() - 1);
    ny = std::min(y, field.getHeight() - 1);
    if (field.getTile(nx, ny).getPassability()) {
        this->x = nx;
        this->y = ny;
    }
}

void PlayerHandler::move(PlayerHandler::Direction dir) {
    size_t nx, ny;
    nx = x;
    ny = y;
    switch (dir) {
        case PlayerHandler::Direction::up:
            if (ny != 0)
                ny--;
            break;
        case PlayerHandler::Direction::down:
            if (ny != field.getHeight() - 1)
                ny++;
            break;
        case PlayerHandler::Direction::left:
            if (nx != 0)
                nx--;
            break;
        case PlayerHandler::Direction::right:
            if (nx != field.getWidth() - 1)
                nx++;
            break;
    }

    updateCoords(nx, ny);
}

bool PlayerHandler::isAlive() {
    return player.getHealth() > 0;
}

void PlayerHandler::dealDamage(size_t amount) {
    amount = std::min(amount, player.getHealth());
    player.setHealth(player.getHealth() - amount);
}

void PlayerHandler::heal(size_t amount) {
    player.setHealth(player.getHealth() + amount);
}

void PlayerHandler::upgradeMaxHealth(size_t amount) {
    player.setMaxHealth(player.getMaxHealth() + amount);
}

size_t PlayerHandler::getHealth() {
    return player.getHealth();
}

size_t PlayerHandler::getMaxHealth() {
    return player.getMaxHealth();
}

size_t PlayerHandler::getDamage() {
    return player.getDamage();
}

void PlayerHandler::increaseDamage(size_t value) {
    player.setDamage(player.getDamage() + value);
}

void PlayerHandler::decreaseDamage(size_t value) {
    value = std::min(value, player.getDamage());
    player.setDamage(player.getDamage() - value);
}

bool PlayerHandler::checkEquip(Player::equipID name) {
    return player.checkEquip(name);
}

void PlayerHandler::giveEquip(Player::equipID name) {
    player.setEquip(name, true);
}

void PlayerHandler::removeEquip(Player::equipID name) {
    player.setEquip(name, false);
}

size_t PlayerHandler::getConsumeAmt(Player::consumeID name) {
    return player.getConsAmt(name);
}

void PlayerHandler::giveConsume(Player::consumeID name, size_t amount) {
    player.setConsAmt(name, player.getConsAmt(name) + amount);
}

void PlayerHandler::removeConsume(Player::consumeID name, size_t amount) {
    amount = std::min(amount, player.getConsAmt(name));
    player.setConsAmt(name, player.getConsAmt(name) - amount);
}

void PlayerHandler::updateCoords(size_t nx, size_t ny) {
    if (field.getTile(nx, ny).getPassability()) {
        x = nx;
        y = ny;
        std::shared_ptr<EventInterface> ptr = field.getTile(nx, ny).getEvent();
        if (ptr != nullptr) {
            uint32_t uses = ptr->eventHandler(this);
            if (uses == 0) {
                Tile eTile = field.getTile(nx, ny);
                eTile.setEvent(nullptr);
                field.setTile(nx, ny, eTile);
            }
        }
    }
}
