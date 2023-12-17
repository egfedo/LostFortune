//
// Created by Егор Федоров on 27.09.2023.
//

#include "player_handler.h"
#include <iostream>
#include <utility>

PlayerHandler::PlayerHandler(size_t x, size_t y, Player &instance, uint32_t textureID) :
    AbstractEntity(x, y, textureID) {
    player = std::make_shared<Player>(instance);
    this->x = x;
    this->y = y;
}


bool PlayerHandler::isAlive() {
    return player->getHealth() > 0;
}

void PlayerHandler::dealDamage(size_t amount) {
    amount = std::min(amount, player->getHealth());
    if (observer != nullptr) {
        LevelMainStatUpdate upd(amount, LevelMainStatUpdate::Stat::health, false);
        observer->logLevelUpdate(std::make_shared<LevelMainStatUpdate>(upd));
    }
    player->setHealth(player->getHealth() - amount);
}

void PlayerHandler::heal(size_t amount) {
    player->setHealth(player->getHealth() + amount);
    if (observer != nullptr) {
        LevelMainStatUpdate upd(amount, LevelMainStatUpdate::Stat::health, true);
        observer->logLevelUpdate(std::make_shared<LevelMainStatUpdate>(upd));
    }
}

void PlayerHandler::upgradeMaxHealth(size_t amount) {
    player->setMaxHealth(player->getMaxHealth() + amount);
    if (observer != nullptr) {
        LevelMainStatUpdate upd(amount, LevelMainStatUpdate::Stat::maxHealth, true);
        observer->logLevelUpdate(std::make_shared<LevelMainStatUpdate>(upd));
    }
}

size_t PlayerHandler::getHealth() {
    return player->getHealth();
}

size_t PlayerHandler::getMaxHealth() {
    return player->getMaxHealth();
}

size_t PlayerHandler::getDamage() {
    return player->getDamage();
}

void PlayerHandler::increaseDamage(size_t value) {
    player->setDamage(player->getDamage() + value);
    if (observer != nullptr) {
        LevelMainStatUpdate upd(value, LevelMainStatUpdate::Stat::damage, true);
        observer->logLevelUpdate(std::make_shared<LevelMainStatUpdate>(upd));
    }
}

void PlayerHandler::decreaseDamage(size_t value) {
    value = std::min(value, player->getDamage());
    player->setDamage(player->getDamage() - value);
    if (observer != nullptr) {
        LevelMainStatUpdate upd(value, LevelMainStatUpdate::Stat::damage, false);
        observer->logLevelUpdate(std::make_shared<LevelMainStatUpdate>(upd));
    }
}

bool PlayerHandler::checkEquip(Player::equipID name) {
    return player->checkEquip(name);
}

void PlayerHandler::giveEquip(Player::equipID name) {
    player->setEquip(name, true);
}

void PlayerHandler::removeEquip(Player::equipID name) {
    player->setEquip(name, false);
}

size_t PlayerHandler::getConsumeAmt(Player::consumeID name) {
    return player->getConsAmt(name);
}

void PlayerHandler::giveConsume(Player::consumeID name, size_t amount) {
    if (observer != nullptr) {
        LevelConsumableUpdate upd(amount, name, true);
        observer->logLevelUpdate(std::make_shared<LevelConsumableUpdate>(upd));
    }
    player->setConsAmt(name, player->getConsAmt(name) + amount);
}

void PlayerHandler::removeConsume(Player::consumeID name, size_t amount) {
    amount = std::min(amount, player->getConsAmt(name));
    player->setConsAmt(name, player->getConsAmt(name) - amount);
    if (observer != nullptr) {
        LevelConsumableUpdate upd(amount, name, false);
        observer->logLevelUpdate(std::make_shared<LevelConsumableUpdate>(upd));
    }
}


PlayerHandler::PlayerHandler(size_t x, size_t y, std::shared_ptr<Player> instance,
                             std::shared_ptr<ChangeObserver> observer,
                             uint32_t textureID, size_t id) :
        AbstractEntity(x, y, std::move(observer), textureID) {
    player = std::move(instance);
    this->id = id;
    this->x = x;
    this->y = y;
    this->textureID = textureID;

}


PlayerHandler::PlayerHandler(const PlayerHandler &handler) : AbstractEntity(handler) {
    Player tmpPlayer = *handler.player;
    player = std::make_shared<Player>(tmpPlayer);
    x = handler.x;
    y = handler.y;
    textureID = handler.textureID;
    id = handler.id;
}

PlayerHandler &PlayerHandler::operator=(const PlayerHandler &handler) {
    PlayerHandler tmp(handler);
    x = tmp.x;
    y = tmp.y;
    textureID = tmp.textureID;
    id = tmp.id;
    player = std::move(tmp.player);
    observer = std::move(tmp.observer);
    return *this;
}

std::shared_ptr<AbstractEntity> PlayerHandler::getCopy() {
    Player tmp = *player;
    return std::make_shared<PlayerHandler>(x, y, std::make_shared<Player>(tmp), observer, textureID, id);
}



//PlayerHandler::PlayerHandler(size_t x, size_t y, std::shared_ptr<Player> instance, std::shared_ptr<Field> field) :
//    x(x), y(y), player(std::move(instance)), field(std::move(field)) {}
