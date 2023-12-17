//
// Created by Егор Федоров on 06.12.2023.
//

#include "InputSFML.h"
#include "../../logging/message/impl/key_press_command_message.h"
#include "../../logging/message/impl/key_press_message.h"
#include <sstream>
#include <set>

#define cmdToStr(x) \
    {InputInterface::Command::x, #x}

InputInterface::Command InputSFML::getCommandInput(bool wait) {
    if (!keyboardEvents.empty()) {
        auto& event = keyboardEvents.front();
        keyboardEvents.pop();
        if (commands.contains(event.key.code)) {
            KeyPressCommandMessage msg(mapper.keyToString(event.key.code), commandToString.at(commands[event.key.code]));
            if (logger != nullptr)
                logger->logMessage(&msg);
            return commands[event.key.code];
        }
        else {
            KeyPressMessage msg(mapper.keyToString(event.key.code));
            if (logger != nullptr)
                logger->logMessage(&msg);
            return InputInterface::Command::idle;
        }
    }
    else
        return InputInterface::Command::idle;
}

InputSFML::InputSFML(LineStream* stream, std::shared_ptr<Logger> logger) {
    this->logger = logger;
    mapper = KeyboardMapperSMFL();
    std::string key;
    std::string inputCmd;
    std::string input;
    std::stringstream ss;
    std::map<std::string, InputInterface::Command> string2cmd = {
            {"up", InputInterface::Command::up},
            {"down", InputInterface::Command::down},
            {"left", InputInterface::Command::left},
            {"right", InputInterface::Command::right},
            {"exit", InputInterface::Command::exit},
            {"enter", InputInterface::Command::enter},
            {"none", InputInterface::Command::none},
    };
    commandToString = {
            cmdToStr(up),
            cmdToStr(down),
            cmdToStr(left),
            cmdToStr(right),
            cmdToStr(exit),
            cmdToStr(enter),
            cmdToStr(none)
    };
    std::set<InputInterface::Command> inputtedCmds;
    input = stream->getLine();
    ss = std::stringstream(input);
    size_t fileSize = 0;
    ss >> fileSize;
    if (fileSize == 0)
        throw std::runtime_error("Invalid config formatting");

    for (size_t i = 0; i < fileSize; i++) {
        input = stream->getLine();
        ss = std::stringstream(input);
        ss >> key >> inputCmd;
        std::cout << key << " " << inputCmd << "\n";
        if (string2cmd.contains(inputCmd)) {
            if (mapper.stringToKey(key) != sf::Keyboard::Unknown) {
                commands[mapper.stringToKey(key)] = string2cmd[inputCmd];
                if (inputtedCmds.contains(string2cmd[inputCmd]))
                    throw std::runtime_error("Two keys assigned for same command in config");
                else
                    inputtedCmds.insert(string2cmd[inputCmd]);
            }
        }
    }
    if (inputtedCmds.size() != 6)
        throw std::runtime_error("Not enough commands assigned in config");
}

std::queue<sf::Event> &InputSFML::getKeyboardEvents() {
    return keyboardEvents;
}
