//
// Created by Егор Федоров on 08.12.2023.
//

#include "cout_writer.h"

void CoutWriter::writeMessage(AbstractLogMessage *message) {
    std::cout << message << "\n";
}
