//
// Created by Егор Федоров on 08.12.2023.
//

#ifndef OOP_GAME_KEY_PRESS_COMMAND_MESSAGE_H
#define OOP_GAME_KEY_PRESS_COMMAND_MESSAGE_H


#include "../abstract_log_message.h"

class KeyPressCommandMessage : public AbstractLogMessage {
private:
    std::string key;
    std::string command;
    void toMessage(std::ostream& os) const final;
public:
    KeyPressCommandMessage(const std::string& key, const std::string& cmd);
};


#endif //OOP_GAME_KEY_PRESS_COMMAND_MESSAGE_H
