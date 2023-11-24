//
// Created by Егор Федоров on 05.11.2023.
//

#include "game.h"

#include <utility>

void Game::routine(OutputInterface* output, InputInterface* input) {
    gameState = State::menu;
    std::pair<std::string, std::string> cmd;
    std::string currentMenu = "main";
    Level stage;
    Level::Command exitCode;
    while (gameState != State::exit) {
        if (gameState == State::menu) {
            cmd = menus[currentMenu].routine(output, input);
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
            exitCode = stage.routine(input, output);
            switch(exitCode) {
                case Level::Command::exit:
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
            }
        }
    }
}

Game::Game(std::map<std::string, Menu> menus, std::vector<Level> levels) :
    menus(std::move(menus)), levels(std::move(levels)), gameState(State::menu), level(0) {}
