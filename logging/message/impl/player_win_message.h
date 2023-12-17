//
// Created by Егор Федоров on 07.12.2023.
//

#ifndef OOP_GAME_PLAYER_WIN_MESSAGE_H
#define OOP_GAME_PLAYER_WIN_MESSAGE_H


#include "../abstract_log_message.h"

class PlayerWinMessage : public AbstractLogMessage {
private:
    std::vector<size_t> stats;

    void toMessage(std::ostream& os) const final;
public:
    PlayerWinMessage(size_t health, size_t maxHealth, size_t damage, size_t coins);
};


#endif //OOP_GAME_PLAYER_WIN_MESSAGE_H
