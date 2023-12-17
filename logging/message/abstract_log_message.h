//
// Created by Егор Федоров on 07.12.2023.
//

#ifndef OOP_GAME_ABSTRACT_LOG_MESSAGE_H
#define OOP_GAME_ABSTRACT_LOG_MESSAGE_H
#include <ostream>

class AbstractLogMessage {
private:
    virtual void toMessage(std::ostream& stream) const = 0;
public:
    friend std::ostream& operator<<(std::ostream& os, const AbstractLogMessage* msg);
};


#endif //OOP_GAME_ABSTRACT_LOG_MESSAGE_H
