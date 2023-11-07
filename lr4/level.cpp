//
// Created by Егор Федоров on 05.11.2023.
//

#include "level.h"

Level::Command Level::routine(size_t id, InputInterface* input, OutputInterface* output) {
    Player player(20, 20, 5);
    FileWrapper wrapper(id);
    Field field;
    FieldBuilder::buildField(field, &wrapper);
    PlayerHandler handler(field.getEntrance().first, field.getEntrance().second, player, field);
    size_t prevHealth = player.getHealth();
    bool update = true;
    InputInterface::Command cmd;
    while (handler.isAlive()) {
        if (update) {
            output->displayLevel(field, {handler.getCoord(PlayerHandler::Coord::X),
                                         handler.getCoord(PlayerHandler::Coord::Y)}, player);
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
        if (player.getHealth() < prevHealth) {
            prevHealth = player.getHealth();
            beep();
        }
        if (handler.getCoord(PlayerHandler::Coord::X) == field.getExit().first and handler.getCoord(PlayerHandler::Coord::Y) == field.getExit().second)
            return Command::win;
        usleep(16000);
    }
    return Command::death;
}