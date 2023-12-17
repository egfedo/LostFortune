//
// Created by Егор Федоров on 06.12.2023.
//

#ifndef OOP_GAME_INPUTSFML_H
#define OOP_GAME_INPUTSFML_H


#include "../input_interface.h"
#include "../line_stream.h"
#include "../../util/KeyboardMapperSMFL.h"
#include "../../logging/logger.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <queue>

class InputSFML : public InputInterface {
private:
    std::queue<sf::Event> keyboardEvents;
    std::map<sf::Keyboard::Key, InputInterface::Command> commands;
    KeyboardMapperSMFL mapper;
    std::map<InputInterface::Command, std::string> commandToString;
    std::shared_ptr<Logger> logger;
public:
    Command getCommandInput(bool wait) final;
    InputSFML(LineStream* stream, std::shared_ptr<Logger> logger);
    std::queue<sf::Event>& getKeyboardEvents();
};


#endif //OOP_GAME_INPUTSFML_H
