//
// Created by Егор Федоров on 05.11.2023.
//

#include "game.h"

void Game::routine(OutputInterface* output, InputInterface* input) {
    gameState = State::menu;
    Menu mainMenu("Dead Fortune", {{"Play", {"menu", "select"}}, {"Exit", {"exit", ""}}});
    Menu selectMenu("Select level", {{"Level 1", {"level", "0"}}, {"Level 2", {"level", "1"}}, {"Back", {"menu", "main"}}});
    Menu death("Task failed", {{"Retry", {"level", "0"}}, {"Main menu", {"menu", "main"}}});
    std::map<std::string, Menu> menus = {{"main", mainMenu}, {"select", selectMenu}, {"death", death}};
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
            exitCode = stage.routine(level, input, output);
            switch(exitCode) {
                case Level::Command::exit:
                    gameState = State::menu;
                    break;
                case Level::Command::death:
                    currentMenu = "death";
                    gameState = State::menu;
                    break;
                case Level::Command::win:
                    if (level < 1)
                        level++;
                    else
                        gameState = State::exit;
                    break;
            }
        }
    }
}
