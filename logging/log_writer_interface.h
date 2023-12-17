//
// Created by Егор Федоров on 08.12.2023.
//

#ifndef OOP_GAME_LOG_WRITER_INTERFACE_H
#define OOP_GAME_LOG_WRITER_INTERFACE_H


#include "message/abstract_log_message.h"

class LogWriterInterface {
public:
    virtual void writeMessage(AbstractLogMessage* message) = 0;
};


#endif //OOP_GAME_LOG_WRITER_INTERFACE_H
