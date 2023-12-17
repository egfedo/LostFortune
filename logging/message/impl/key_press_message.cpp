//
// Created by Егор Федоров on 08.12.2023.
//

#include "key_press_message.h"

KeyPressMessage::KeyPressMessage(const std::string &key) {
    this->key = key;
}

void KeyPressMessage::toMessage(std::ostream &os) const {
    os << "Key pressed without triggering command. Key: " << key;
}
