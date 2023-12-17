//
// Created by Егор Федоров on 08.12.2023.
//

#ifndef OOP_GAME_KEY_PRESS_MESSAGE_H
#define OOP_GAME_KEY_PRESS_MESSAGE_H


#include "../abstract_log_message.h"

class KeyPressMessage : public AbstractLogMessage {
private:
    std::string key;

    void toMessage(std::ostream& os) const final;

public:
    KeyPressMessage(const std::string& key);
};


#endif //OOP_GAME_KEY_PRESS_MESSAGE_H
