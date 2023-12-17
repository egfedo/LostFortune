//
// Created by Егор Федоров on 07.12.2023.
//

#include "player_win_message.h"

PlayerWinMessage::PlayerWinMessage(size_t health, size_t maxHealth, size_t damage, size_t coins) {
    stats.push_back(health);
    stats.push_back(maxHealth);
    stats.push_back(damage);
    stats.push_back(coins);
}

void PlayerWinMessage::toMessage(std::ostream &os) const {
    os << "Player won. Stats: [health: " << stats[0] << ", max health: " << stats[1] <<
        ", damage: " << stats[2] << ", coins: " << stats[3] << "]";
}
