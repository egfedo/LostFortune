//
// Created by Егор Федоров on 05.11.2023.
//

#ifndef OOP_GAME_TEST_INPUT_H
#define OOP_GAME_TEST_INPUT_H

#include "../input_interface.h"
#include <iostream>
#include <map>
#include <ncurses.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "file_wrapper.h"
#include <set>

class TestInput : public InputInterface {
private:
    std::map<char, InputInterface::Command> commands;
public:
    TestInput();
    InputInterface::Command getCommandInput(bool wait) final;
    ~TestInput();
};


#endif //OOP_GAME_TEST_INPUT_H
