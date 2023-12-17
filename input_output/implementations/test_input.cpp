//
// Created by Егор Федоров on 05.11.2023.
//

#include "test_input.h"

InputInterface::Command TestInput::getCommandInput(bool wait) {
    char input;
    nodelay(stdscr, !wait);
    input = getch();
    nodelay(stdscr, false);
//    std::cout << input << "\n";
    if (commands.contains(input))
        return commands[input];
    else
        return InputInterface::Command::idle;
}

TestInput::TestInput() {
    FileWrapper wrapper("keyboard_config.txt");
    int charN;
    std::string inputCmd;
    std::string input;
    std::stringstream ss;
    std::map<std::string, InputInterface::Command> string2cmd = {
            {"up", InputInterface::Command::up},
            {"down", InputInterface::Command::down},
            {"left", InputInterface::Command::left},
            {"right", InputInterface::Command::right},
            {"exit", InputInterface::Command::exit},
            {"enter", InputInterface::Command::enter},
            {"none", InputInterface::Command::none},
    };
    std::set<InputInterface::Command> inputtedCmds;
    input = wrapper.getLine();
    ss = std::stringstream(input);
    size_t fileSize = 0;
    ss >> fileSize;
    if (fileSize == 0)
        throw std::runtime_error("Invalid config formatting");

    for (size_t i = 0; i < fileSize; i++) {
        input = wrapper.getLine();
        ss = std::stringstream(input);
        ss >> charN;
        ss >> inputCmd;
//        std::cout << charN << " " << inputCmd << "\n";
        if (string2cmd.contains(inputCmd)) {
            commands[(char)charN] = string2cmd[inputCmd];
            if (inputtedCmds.contains(string2cmd[inputCmd]))
                throw std::runtime_error("Two keys assigned for same command in config");
            else
                inputtedCmds.insert(string2cmd[inputCmd]);
        }
    }
    if (inputtedCmds.size() != 6)
        throw std::runtime_error("Not enough commands assigned in config");
    commands[0] = InputInterface::Command::none;
    commands[-1] = InputInterface::Command::none;

//    initscr();
//    noecho();
//    keypad(stdscr, true);
}

TestInput::~TestInput() {
    endwin();
}

//char TestInput::getch(bool wait) {
//    struct termios oldt, newt;
//    int ch;
//    tcgetattr( STDIN_FILENO, &oldt );
//    newt = oldt;
//    newt.c_lflag &= ~( ICANON | ECHO );
//    newt.c_cc[VMIN] = wait ? 1 : 0; // bytes until read unblocks.
//    newt.c_cc[VTIME] = 0; // timeout.
//    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
//    if (ioctl(0, I_NREAD, &n) == 0 && n > 0)
//    read(STDIN_FILENO, &ch, 1);
//    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
//    return (char)ch;
//}
