//
// Created by Егор Федоров on 05.11.2023.
//

#include "test_input.h"

InputInterface::Command TestInput::getCommandInput(bool wait) {
    char input;
    nodelay(stdscr, !wait);
    input = getch();
    nodelay(stdscr, false);
    std::map<char, InputInterface::Command> commands = {
            {'w', InputInterface::Command::up},
            {'s', InputInterface::Command::down},
            {'a', InputInterface::Command::left},
            {'d', InputInterface::Command::right},
            {27, InputInterface::Command::exit},
            {'\n', InputInterface::Command::enter},
            {0, InputInterface::Command::none},
            {-1, InputInterface::Command::none},
    };
//    std::cout << input << "\n";
    if (commands.contains(input))
        return commands[input];
    else
        return InputInterface::Command::idle;
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
////    if (ioctl(0, I_NREAD, &n) == 0 && n > 0)
//    read(STDIN_FILENO, &ch, 1);
//    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
//    return (char)ch;
//}
