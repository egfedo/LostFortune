//
// Created by Егор Федоров on 05.11.2023.
//

#include "level.h"

#include <utility>

Level::Command Level::routine(InputInterface* input, OutputInterface* output) {
    Player playerCopy = player;
    Field fieldCopy = *field;
    PlayerHandler handler(fieldCopy.getEntrance().first, fieldCopy.getEntrance().second, playerCopy, fieldCopy);
    size_t prevHealth = playerCopy.getHealth();
    bool update = true;
    InputInterface::Command cmd;
    while (handler.isAlive()) {
        if (update) {
            output->displayLevel(fieldCopy, {handler.getCoord(PlayerHandler::Coord::X),
                                         handler.getCoord(PlayerHandler::Coord::Y)}, playerCopy);
            update = false;
        }
        cmd = input->getCommandInput(false);
        if (cmd != InputInterface::Command::none)
            update = true;
        switch (cmd) {
            case InputInterface::Command::up:
                handler.move(PlayerHandler::Direction::up);
                break;
            case InputInterface::Command::down:
                handler.move(PlayerHandler::Direction::down);
                break;
            case InputInterface::Command::left:
                handler.move(PlayerHandler::Direction::left);
                break;
            case InputInterface::Command::right:
                handler.move(PlayerHandler::Direction::right);
                break;
            case InputInterface::Command::exit:
                return Command::exit;
            default:
                break;
        }
        if (playerCopy.getHealth() < prevHealth) {
            prevHealth = playerCopy.getHealth();
            beep();
        }
        if (handler.getCoord(PlayerHandler::Coord::X) == field->getExit().first and handler.getCoord(PlayerHandler::Coord::Y) == field->getExit().second) {
            output->displayLevel(fieldCopy, {handler.getCoord(PlayerHandler::Coord::X),
                                         handler.getCoord(PlayerHandler::Coord::Y)}, playerCopy);
            usleep(500000);
            flushinp();
            return Command::win;
        }
        usleep(16000);
    }
    return Command::death;
}

Level::Level(Player player, std::shared_ptr<Field> field) : field(std::move(field)), player(std::move(player)) {
}

Level::Level() : player(Player(20, 20, 5)) {
}
