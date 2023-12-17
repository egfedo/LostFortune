#include <iostream>
#include <ncurses.h>
#include "entity/player/player_handler.h"
#include "field/field_builder.h"
#include "input_output/implementations/file_wrapper.h"
#include "game/game.h"
#include "input_output/implementations/test_input.h"
#include "input_output/implementations/test_output.h"
#include "input_output/implementations/file_input.h"
#include "game/menu/menu_builder.h"
#include "game/level/level_builder.h"
#include "input_output/implementations/OutputSFML.h"
#include "input_output/implementations/InputSFML.h"
#include "logging/message/impl/new_level_message.h"
#include "logging/impl/cout_writer.h"
#include "logging/impl/file_writer.h"
#include <SFML/Graphics.hpp>
#define LEVEL_COUNT 2

int main() {
    CoutWriter coutWriter;
    FileWriter fileWriter("../log.txt");
    Logger logger;
    std::cout << "Logging to cout? [y/n] ";
    char setting;
    std::cin >> setting;
    if (setting == 'y' || setting == 'Y')
        logger.addSuscriber(&coutWriter);
    std::cout << "Logging to file? [y/n] ";
    std::cin >> setting;
    if (setting == 'y' || setting == 'Y')
        logger.addSuscriber(&fileWriter);
//    FileWrapper file("inputs.txt");
//    FileInput input(&file);
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Lost Fortune", sf::Style::Titlebar | sf::Style::Close);
    FileWrapper file("keyboard_config.txt");
    InputSFML input(&file, std::make_shared<Logger>(logger));
    OutputSFML output(window, input.getKeyboardEvents());
    file.reopen("main_menu.txt");
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
//    TestInput input;
//    TestOutput output;
    ChangeObserver observer(std::make_shared<OutputSFML>(output), std::make_shared<Logger>(logger));

    Game game{menus, levels};
    game.routine(std::make_shared<ChangeObserver>(observer), &input);
    return 0;
}
