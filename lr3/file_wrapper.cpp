//
// Created by Егор Федоров on 03.11.2023.
//

#include "file_wrapper.h"

FileWrapper::FileWrapper(size_t fileID) {
    std::string filename;
    std::stringstream nameFormat;
    nameFormat << "./level" << static_cast<size_t>(fileID) << ".txt";
    filename = nameFormat.str();
    std::ifstream in(filename);
    file = std::ifstream(filename);
    if (not file.is_open())
        throw std::logic_error("Unable to open file for specified file ID");
}

FileWrapper::~FileWrapper() {
    file.close();
}

std::string FileWrapper::getLine() {
    std::string line;
    if (not std::getline(file, line))
        throw std::logic_error("Unable to get line (not enough lines for width inputted)");
    return line;
}
