//
// Created by Егор Федоров on 05.11.2023.
//

#include "menu.h"

#include <utility>

Menu::Menu(std::string title, std::vector<Button> buttons) :
    title(std::move(title)), buttons(std::move(buttons)), current(0) {}

std::pair<std::string, std::string> Menu::routine(OutputInterface* output, InputInterface* input) {
    InputInterface::Command cmd;
    std::vector<std::string> buttonTexts;
    buttonTexts.reserve(buttons.size());
    for(const auto& bt : buttons)
        buttonTexts.push_back(bt.text);
    while (true) {
        output->displayMenu(title, buttonTexts, current);
//        usleep(16000);
        cmd = input->getCommandInput(true);
        switch (cmd) {
            case InputInterface::Command::up:
                if (current != 0)
//                    std::cout << "\a";
                    current--;
                break;
            case InputInterface::Command::down:
                if (current != buttons.size() - 1)
//                    std::cout << "\a";
                    current++;
                break;
            case InputInterface::Command::exit:
                return {"exit", ""};
            case InputInterface::Command::enter:
//                std::cout << "\a";
                return buttons[current].action;
            default:
                break;
        }
    }
    return {"", ""};
}
