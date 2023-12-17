//
// Created by Егор Федоров on 07.12.2023.
//

#ifndef OOP_GAME_KEYBOARDMAPPERSMFL_H
#define OOP_GAME_KEYBOARDMAPPERSMFL_H

#include <SFML/Window/Keyboard.hpp>
#include <map>
#include <string>

class KeyboardMapperSMFL {
private:
    std::map<std::string, sf::Keyboard::Key> string2key;
    std::map<sf::Keyboard::Key, std::string> key2string;
public:
    KeyboardMapperSMFL();
    sf::Keyboard::Key stringToKey(const std::string& keyString);
    std::string keyToString(sf::Keyboard::Key key);
};


#endif //OOP_GAME_KEYBOARDMAPPERSMFL_H
