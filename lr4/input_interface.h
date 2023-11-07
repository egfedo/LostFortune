//
// Created by Егор Федоров on 05.11.2023.
//

#ifndef OOP_GAME_INPUT_INTERFACE_H
#define OOP_GAME_INPUT_INTERFACE_H


class InputInterface {
public:
    enum class Command {
        none,
        idle,
        up,
        down,
        left,
        right,
        enter,
        exit

    };
//    virtual char getKeyInput() = 0;
    virtual Command getCommandInput(bool wait) = 0;
};


#endif //OOP_GAME_INPUT_INTERFACE_H
