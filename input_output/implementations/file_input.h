//
// Created by Егор Федоров on 07.11.2023.
//

#ifndef OOP_GAME_FILE_INPUT_H
#define OOP_GAME_FILE_INPUT_H

#include "../input_interface.h"
#include <fstream>
#include "../line_stream.h"
#include <map>
#include <ncurses.h>

class FileInput : public InputInterface {
private:
    LineStream* file;
    std::map<std::string, InputInterface::Command> cmds = {
            {"up", InputInterface::Command::up},
            {"down", InputInterface::Command::down},
            {"left", InputInterface::Command::left},
            {"right", InputInterface::Command::right},
            {"exit", InputInterface::Command::exit},
            {"enter", InputInterface::Command::enter},
    };
public:
    explicit FileInput(LineStream* file);
    Command getCommandInput(bool wait) final;
};


#endif //OOP_GAME_FILE_INPUT_H
