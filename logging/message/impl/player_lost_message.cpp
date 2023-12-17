//
// Created by Егор Федоров on 07.12.2023.
//

#include "player_lost_message.h"

PlayerLostMessage::PlayerLostMessage(size_t x, size_t y) : deathCoords({x, y}) {}

void PlayerLostMessage::toMessage(std::ostream &os) const {
    os << "Player lost. Coords: [x: " << deathCoords.first << ", y: " << deathCoords.second << "]";
}
