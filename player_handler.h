//
// Created by Егор Федоров on 27.09.2023.
//

#ifndef OOP_GAME_PLAYER_HANDLER_H
#define OOP_GAME_PLAYER_HANDLER_H

class PlayerHandler;

#include <cstddef>
#include "player.h"
#include "lr2/field.h"

class PlayerHandler {
private:
    size_t x;
    size_t y;
    Player& player;
    Field& field;

    void updateCoords(size_t nx, size_t ny);

public:
    enum class Direction {
        up,
        down,
        left,
        right
    };

    enum class Coord {X, Y};

    PlayerHandler(size_t x, size_t y, Player& instance, Field& field);
    ~PlayerHandler() = default;

    size_t getCoord(Coord n) const;
    void setCoord(Coord n, size_t value);
    void setCoords(size_t x, size_t y);

    void move(Direction dir);

    bool isAlive();
    size_t getHealth();
    void dealDamage(size_t amount);
    void heal(size_t amount);

    size_t getMaxHealth();
    void upgradeMaxHealth(size_t amount);

    size_t getDamage();
    void increaseDamage(size_t value);
    void decreaseDamage(size_t value);

    bool checkEquip(Player::equipID name);
    void giveEquip(Player::equipID name);
    void removeEquip(Player::equipID name);

    size_t getConsumeAmt(Player::consumeID name);
    void giveConsume(Player::consumeID name, size_t amount);
    void removeConsume(Player::consumeID name, size_t amount);
};


#endif //OOP_GAME_PLAYER_HANDLER_H
