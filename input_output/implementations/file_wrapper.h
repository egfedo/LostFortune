//
// Created by Егор Федоров on 03.11.2023.
//

#ifndef OOP_GAME_FILE_WRAPPER_H
#define OOP_GAME_FILE_WRAPPER_H

#include <sstream>
#include <fstream>
#include "../line_stream.h"

class FileWrapper : public LineStream {
private:
    std::ifstream file;

public:
    explicit FileWrapper(size_t levelID);
    FileWrapper(const std::string& fileName);
    std::string getLine() final;
    void reopen(const std::string& fileName);
    ~FileWrapper();
};


#endif //OOP_GAME_FILE_WRAPPER_H
