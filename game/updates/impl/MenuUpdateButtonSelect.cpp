//
// Created by Егор Федоров on 27.11.2023.
//

#include "MenuUpdateButtonSelect.h"

MenuUpdateButtonSelect::MenuUpdateButtonSelect(InputInterface::Command direction) : direction(direction){}

void MenuUpdateButtonSelect::applyUpdate(std::shared_ptr<Menu> prevState, std::shared_ptr<OutputInterface> output) {
    size_t prevPostion = prevState->getCurrent();
    prevState->moveCurrent(direction, nullptr);
    size_t newPosition = prevState->getCurrent();
    if (newPosition != prevPostion) {
    }
}
