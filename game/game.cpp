//
// Created by Егор Федоров on 05.11.2023.
//

#include "game.h"

#include <utility>

void Game::routine(std::shared_ptr<ChangeObserver> observer, InputInterface* input) {
    gameState = State::menu;
    std::pair<std::string, std::string> cmd;
    std::string currentMenu = "main";
    Level stage;
    Level::Command exitCode;
    while (gameState != State::exit) {
        if (gameState == State::menu) {
            observer->startMenu(menus[currentMenu]);
            cmd = menus[currentMenu].routine(observer, input);
            if (cmd.first == "exit")
                gameState = State::exit;
            if (cmd.first == "menu")
                currentMenu = cmd.second;
            if (cmd.first == "level") {
                gameState = State::ingame;
                level = atoi(cmd.second.c_str());
            }
        }
        if (gameState == State::ingame) {
            stage = levels[level];
            exitCode = stage.routine(input, observer);
            switch(exitCode) {
                case Level::Command::exit:
                    currentMenu = "select";
                    gameState = State::menu;
                    break;
                case Level::Command::death:
                    currentMenu = "death";
                    gameState = State::menu;
                    break;
                case Level::Command::win:
                    if (level < levels.size() - 1)
                        level++;
                    else {
                        gameState = State::menu;
                        currentMenu = "win";
                    }
                    break;
                case Level::Command::close:
                    gameState = State::exit;
                    break;
            }
        }
    }
}

Game::Game(std::map<std::string, Menu> menus, std::vector<Level> levels) :
    menus(std::move(menus)), levels(std::move(levels)), gameState(State::menu), level(0) {}
