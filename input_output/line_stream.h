//
// Created by Егор Федоров on 03.11.2023.
//

#ifndef OOP_GAME_LINE_STREAM_H
#define OOP_GAME_LINE_STREAM_H

#include <iostream>

class LineStream {
public:
    virtual std::string getLine() = 0;
};


#endif //OOP_GAME_LINE_STREAM_H
