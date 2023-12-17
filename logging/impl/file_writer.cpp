//
// Created by Егор Федоров on 08.12.2023.
//

#include "file_writer.h"

void FileWriter::writeMessage(AbstractLogMessage *message) {
    file << message << "\n";
}

FileWriter::FileWriter(const std::string &path) {
    file.open(path);
}

FileWriter::~FileWriter() {
    file.close();
}
