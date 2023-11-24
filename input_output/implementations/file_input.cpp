//
// Created by Егор Федоров on 07.11.2023.
//

#include "file_input.h"

InputInterface::Command FileInput::getCommandInput(bool wait) {
    char input;
    nodelay(stdscr, !wait);
    input = getch();
    nodelay(stdscr, false);
    std::string line;
    if (input == 10) {
        line = file->getLine();
        if (cmds.contains(line))
            return cmds[line];
        else
            return InputInterface::Command::idle;
    }
    else
        return InputInterface::Command::none;
}

FileInput::FileInput(LineStream *file) : file(file) {}
