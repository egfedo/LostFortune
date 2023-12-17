//
// Created by Егор Федоров on 07.12.2023.
//

#include "new_level_message.h"

void NewLevelMessage::toMessage(std::ostream &os) const {
    os << "New level started. Field size: [width: " << fieldSize.first <<
        ", height: " << fieldSize.second << "], Starting position: [x: " <<
        startPos.first << ", y: " << startPos.second << "]";
}

NewLevelMessage::NewLevelMessage(size_t fieldWidth, size_t fieldHeight,
                                 size_t startX, size_t startY)
                                 : fieldSize({fieldWidth, fieldHeight}),
                                 startPos({startX, startY}) {}
