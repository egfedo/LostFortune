//
// Created by Егор Федоров on 07.12.2023.
//

#include "abstract_log_message.h"

std::ostream &operator<<(std::ostream &os, const AbstractLogMessage *msg) {
    msg->toMessage(os);
    return os;
}
