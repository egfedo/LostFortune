//
// Created by Егор Федоров on 11.11.2023.
//

#include "menu_builder.h"

Menu MenuBuilder::buildMenu(LineStream *stream) {
    std::string line;
    std::stringstream input;
    std::string menuName;
    std::vector<Button> buttons;
    std::pair<std::string, std::string> buttonCmd;
    std::string buttonName;
    size_t menuLen = 0;
    line = stream->getLine();
    input = std::stringstream(line);
    input >> menuLen;
    if (menuLen == 0)
        throw std::runtime_error("Wrong formatting for menu file");
    menuName = stream->getLine();

    for (size_t i = 0; i < menuLen; i++) {
        buttonName = stream->getLine();
        line = stream->getLine();
        input = std::stringstream(line);
        input >> buttonCmd.first >> buttonCmd.second;
        buttons.emplace_back(buttonName, buttonCmd);
    }
    return {menuName, buttons};
}
