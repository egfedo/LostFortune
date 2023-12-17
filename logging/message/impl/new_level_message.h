//
// Created by Егор Федоров on 07.12.2023.
//

#ifndef OOP_GAME_NEW_LEVEL_MESSAGE_H
#define OOP_GAME_NEW_LEVEL_MESSAGE_H


#include "../abstract_log_message.h"

class NewLevelMessage : public AbstractLogMessage {
private:
    std::pair<size_t, size_t> fieldSize;
    std::pair<size_t, size_t> startPos;

    void toMessage(std::ostream& os) const final;
public:
    NewLevelMessage(size_t fieldWidth, size_t fieldHeight, size_t startX, size_t startY);
};


#endif //OOP_GAME_NEW_LEVEL_MESSAGE_H
