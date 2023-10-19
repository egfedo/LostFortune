//
// Created by Егор Федоров on 27.09.2023.
//

#ifndef OOP_GAME_PLAYER_H
#define OOP_GAME_PLAYER_H

#include <algorithm>
#include <map>
#include <string>
#include <set>

class Player {
private:
    size_t health;
    size_t maxHealth;
    size_t damage;

public:
    enum class equipID {
        sword, shield
    };
    enum class consumeID {
        bomb, heal, coins
    };

    size_t getHealth() const;
    void setHealth(size_t value);

    size_t getMaxHealth() const;
    void setMaxHealth(size_t value);

    size_t getDamage() const;
    void setDamage(size_t value);

    // Checks if player has a specified equipment
    bool checkEquip(equipID name);
    // Sets if player has a specified equipment or not
    void setEquip(equipID name, bool state);

    // Gets current amount of specified consumables
    size_t getConsAmt(consumeID name);
    // Sets current amount of specified consumables
    void setConsAmt(consumeID name, size_t amount);

    Player(size_t health, size_t maxHealth, size_t damage);

private:
    std::set<equipID> equipment;
    std::map<consumeID, size_t> consumables;
};


#endif //OOP_GAME_PLAYER_H
