//
// Created by Егор Федоров on 08.12.2023.
//

#ifndef OOP_GAME_LOGGER_H
#define OOP_GAME_LOGGER_H

#include <vector>
#include "log_writer_interface.h"

class Logger {
private:
    std::vector<LogWriterInterface*> suscribers;
public:
    Logger() = default;
    void addSuscriber(LogWriterInterface* newSuscriber);
    void logMessage(AbstractLogMessage* message);
};


#endif //OOP_GAME_LOGGER_H
