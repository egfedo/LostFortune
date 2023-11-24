//
// Created by Егор Федоров on 05.11.2023.
//

#include "level.h"

#include <utility>

Level::Command Level::routine(InputInterface* input, OutputInterface* output) {
    size_t prevHealth = handler->getHealth();
    bool update = true;
    InputInterface::Command cmd;
    while (handler->isAlive()) {
        if (update) {
            output->displayLevel(handler->getField(), {handler->getCoord(PlayerHandler::Coord::X),
                                         handler->getCoord(PlayerHandler::Coord::Y)}, handler);
            update = false;
        }
        cmd = input->getCommandInput(false);
        if (cmd != InputInterface::Command::none)
            update = true;
        switch (cmd) {
            case InputInterface::Command::up:
                handler->move(PlayerHandler::Direction::up);
                break;
            case InputInterface::Command::down:
                handler->move(PlayerHandler::Direction::down);
                break;
            case InputInterface::Command::left:
                handler->move(PlayerHandler::Direction::left);
                break;
            case InputInterface::Command::right:
                handler->move(PlayerHandler::Direction::right);
                break;
            case InputInterface::Command::exit:
                return Command::exit;
            default:
                break;
        }
        if (handler->getHealth() < prevHealth) {
            prevHealth = handler->getHealth();
            beep();
        }
        if (handler->getCoord(PlayerHandler::Coord::X) == handler->getField()->getExit().first and handler->getCoord(PlayerHandler::Coord::Y) == handler->getField()->getExit().second) {
            output->displayLevel(handler->getField(), {handler->getCoord(PlayerHandler::Coord::X),
                                         handler->getCoord(PlayerHandler::Coord::Y)}, handler);
            usleep(500000);
            flushinp();
            return Command::win;
        }
        usleep(16000);
    }
    return Command::death;
}

Level::Level(std::shared_ptr<PlayerHandler> handler) :
    handler(std::move(handler)) {}

Level::Level(const Level &level) {
    PlayerHandler tmpHandler = *level.handler;
    handler = std::make_shared<PlayerHandler>(tmpHandler);
}

Level &Level::operator =(const Level &level) {
    Level temp(level);
    handler = std::move(temp.handler);
    return *this;
}

Level::Level() = default;
