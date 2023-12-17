//
// Created by Егор Федоров on 05.11.2023.
//

#include "level.h"

#include <utility>

Level::Command Level::routine(InputInterface* input, const std::shared_ptr<ChangeObserver>& observer) {
    EntityHandler tmp = *handler;
    observer->startLevel(std::make_shared<EntityHandler>(tmp));
    handler->setObserver(observer);
    InputInterface::Command cmd;

    bool finished;
    while (handler->getPlayer()->isAlive()) {
        if(observer->executeLevelUpdates())
            return Command::close;
//        if (update) {
//            output->displayLevel(handler->getField(), {handler->getCoord(PlayerHandler::Coord::X),
//                                         handler->getCoord(PlayerHandler::Coord::Y)}, handler);
//            update = false;
//        }
        finished = false;
        cmd = input->getCommandInput(false);
        switch (cmd) {
            case InputInterface::Command::up:
                finished = handler->movePlayer(PlayerHandler::Direction::up);
                break;
            case InputInterface::Command::down:
                finished = handler->movePlayer(PlayerHandler::Direction::down);
                break;
            case InputInterface::Command::left:
                finished = handler->movePlayer(PlayerHandler::Direction::left);
                break;
            case InputInterface::Command::right:
                finished = handler->movePlayer(PlayerHandler::Direction::right);
                break;
            case InputInterface::Command::exit:
                return Command::exit;
            default:
                break;
        }

        handler->moveEnemies();

        if (finished) {
//            output->displayLevel(handler->getField(), {handler->getCoord(PlayerHandler::Coord::X),
//                                         handler->getCoord(PlayerHandler::Coord::Y)}, handler);
            observer->executeLevelUpdates();
            usleep(500000);
            flushinp();
            return Command::win;
        }
        usleep(16000);
    }
    observer->executeLevelUpdates();
    usleep(750000);
    return Command::death;
}

Level::Level(std::shared_ptr<EntityHandler> handler) :
    handler(std::move(handler)) {}

Level::Level(const Level &level) {
    EntityHandler tmpHandler = *level.handler;
    handler = std::make_shared<EntityHandler>(tmpHandler);
}

Level &Level::operator =(const Level &level) {
    Level temp(level);
    handler = std::move(temp.handler);
    return *this;
}

Level::Level() = default;
