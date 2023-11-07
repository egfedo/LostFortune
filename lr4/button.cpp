//
// Created by Егор Федоров on 05.11.2023.
//

#include "button.h"

#include <utility>

Button::Button(std::string text, std::pair<std::string, std::string> action) : text(std::move(text)), action(std::move(action)) {}
