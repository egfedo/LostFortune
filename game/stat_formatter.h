//
// Created by Егор Федоров on 26.11.2023.
//

#ifndef OOP_GAME_STAT_FORMATTER_H
#define OOP_GAME_STAT_FORMATTER_H


#include <cstdlib>
#include "../entity/player/player.h"
class PlayerHandler;

class StatContainer {
private:
    std::vector<uint32_t> generalStats;
    std::vector<bool> equipment;
    std::vector<uint32_t> consumables;

public:
    enum class MainStat {
        health, maxHealth, damage
    };
    StatContainer();
    StatContainer(std::vector<uint32_t> generalStats, std::vector<bool> equipment, std::vector<uint32_t> consumables);
    explicit StatContainer(const std::shared_ptr<PlayerHandler>& handler);
    void add(MainStat stat, uint32_t value);
    void add(Player::equipID equipment, bool state);
    void add(Player::consumeID consumable, uint32_t amount);

    uint32_t getStat(int vector, uint32_t id);

    bool operator == (const StatContainer &other);
    bool operator != (const StatContainer &other);
};

#include "../entity/player/player_handler.h"
#endif //OOP_GAME_STAT_FORMATTER_H
