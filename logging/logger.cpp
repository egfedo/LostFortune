//
// Created by Егор Федоров on 08.12.2023.
//

#include "logger.h"

void Logger::addSuscriber(LogWriterInterface* newSuscriber) {
    suscribers.push_back(newSuscriber);
}

void Logger::logMessage(AbstractLogMessage *message) {
    for (auto& writer : suscribers)
        writer->writeMessage(message);
}
