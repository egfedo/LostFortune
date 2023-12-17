//
// Created by Егор Федоров on 08.12.2023.
//

#ifndef OOP_GAME_COUT_WRITER_H
#define OOP_GAME_COUT_WRITER_H


#include "../log_writer_interface.h"
#include <iostream>

class CoutWriter : public LogWriterInterface {
public:
    void writeMessage(AbstractLogMessage* message) final;
};


#endif //OOP_GAME_COUT_WRITER_H
