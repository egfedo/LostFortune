#include <iostream>
#include <ncurses.h>
#include "player/player_handler.h"
#include "field/field_builder.h"
#include "input_output/implementations/file_wrapper.h"
#include "game/game.h"
#include "input_output/implementations/test_input.h"
#include "input_output/implementations/test_output.h"
#include "input_output/implementations/file_input.h"
#include "game/menu/menu_builder.h"
#include "game/level/level_builder.h"

#define LEVEL_COUNT 2

int main() {
//    FileWrapper file("inputs.txt");
//    FileInput input(&file);
    FileWrapper file("main_menu.txt");
    Menu main = MenuBuilder::buildMenu(&file);
    file.reopen("select_menu.txt");
    Menu select = MenuBuilder::buildMenu(&file);
    file.reopen("death_menu.txt");
    Menu death = MenuBuilder::buildMenu(&file);
    file.reopen("win_menu.txt");
    Menu win = MenuBuilder::buildMenu(&file);
    std::map<std::string, Menu> menus = {
            {"main", main},
            {"select", select},
            {"death", death},
            {"win", win},
    };
    LevelBuilder levelBuilder;
    std::vector<Level> levels;
    FileWrapper fieldFile(0);
    for (size_t i = 0; i < LEVEL_COUNT; i++) {
        file.reopen("level" + std::to_string(i) + ".txt");
        fieldFile.reopen("field" + std::to_string(i) + ".txt");
        levels.push_back(levelBuilder.buildLevel(&file, &fieldFile));
    }
    TestInput input;
    TestOutput output;
    Game game{menus, levels};
    game.routine(&output, &input);
    return 0;
}
