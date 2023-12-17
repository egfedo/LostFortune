//
// Created by Егор Федоров on 08.12.2023.
//

#ifndef OOP_GAME_FILE_WRITER_H
#define OOP_GAME_FILE_WRITER_H


#include "../log_writer_interface.h"
#include <fstream>

class FileWriter : public LogWriterInterface {
private:
    std::ofstream file;
public:
    void writeMessage(AbstractLogMessage* message) final;
    explicit FileWriter(const std::string& path);
    ~FileWriter();
};


#endif //OOP_GAME_FILE_WRITER_H
