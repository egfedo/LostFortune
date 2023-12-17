//
// Created by Егор Федоров on 05.11.2023.
//

#include "menu.h"

#include <utility>

Menu::Menu(std::string title, std::vector<Button> buttons) :
    title(std::move(title)), buttons(std::move(buttons)), current(0) {}

std::pair<std::string, std::string> Menu::routine(std::shared_ptr<ChangeObserver> observer, InputInterface* input) {
    InputInterface::Command cmd;
    while (true) {
        if(observer->executeMenuUpdates())
            return {"exit", ""};
        usleep(16000);
        cmd = input->getCommandInput(true);
        switch (cmd) {
            case InputInterface::Command::up:
            case InputInterface::Command::down:
                moveCurrent(cmd, observer);
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

std::string Menu::getTitle() {
    return title;
}

std::vector<Button> Menu::getButtons() {
    return {buttons};
}

size_t Menu::getCurrent() {
    return current;
}

void Menu::moveCurrent(InputInterface::Command dir, std::shared_ptr<ChangeObserver> observer) {
    if (observer != nullptr) {
        MenuUpdateButtonSelect upd(dir);
        observer->logMenuUpdate(std::make_shared<MenuUpdateButtonSelect>(upd));
    }

    switch (dir) {
        case InputInterface::Command::up:
            if (current != 0)
                current--;
            break;
        case InputInterface::Command::down:
            if (current != buttons.size() - 1)
                current++;
            break;
        default:
            break;
    }
}
