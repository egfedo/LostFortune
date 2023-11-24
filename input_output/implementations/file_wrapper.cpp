//
// Created by Егор Федоров on 03.11.2023.
//

#include "file_wrapper.h"

FileWrapper::FileWrapper(size_t levelID) {
    std::string filename;
    std::stringstream nameFormat;
    nameFormat << "./field" << static_cast<size_t>(levelID) << ".txt";
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
        throw std::logic_error("Unable to get line");
    return line;
}

FileWrapper::FileWrapper(const std::string& fileName) {
    std::ifstream in("./" + fileName);
    file = std::ifstream(fileName);
    if (not file.is_open())
        throw std::logic_error("Unable to open file for specified file ID");
}

void FileWrapper::reopen(const std::string &fileName) {
    file.close();
    std::ifstream in("./" + fileName);
    file = std::ifstream(fileName);
    if (not file.is_open())
        throw std::logic_error("Unable to open file for specified file ID");
}