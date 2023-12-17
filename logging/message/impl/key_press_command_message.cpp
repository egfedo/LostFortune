//
// Created by Егор Федоров on 08.12.2023.
//

#include "key_press_command_message.h"

void KeyPressCommandMessage::toMessage(std::ostream &os) const {
    os << "Command triggered by key press. Key: " << key << ", Command: " << command;
}

KeyPressCommandMessage::KeyPressCommandMessage(const std::string &key, const std::string &cmd) {
    this->key = key;
    this->command = cmd;
}
