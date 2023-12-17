//
// Created by Егор Федоров on 07.12.2023.
//

#ifndef OOP_GAME_PLAYER_LOST_MESSAGE_H
#define OOP_GAME_PLAYER_LOST_MESSAGE_H


#include "../abstract_log_message.h"

class PlayerLostMessage : public AbstractLogMessage {
private:
    std::pair<size_t, size_t> deathCoords;

    void toMessage(std::ostream& os) const final;
public:
    PlayerLostMessage(size_t x, size_t y);
};


#endif //OOP_GAME_PLAYER_LOST_MESSAGE_H
