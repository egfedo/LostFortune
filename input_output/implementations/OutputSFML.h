//
// Created by Егор Федоров on 04.12.2023.
//

#ifndef OOP_GAME_OUTPUTSFML_H
#define OOP_GAME_OUTPUTSFML_H

#include <SFML/Graphics.hpp>
#include "../output_interface.h"
#include "../../util/TextureStorageSFML.h"
#include <queue>

class OutputSFML : public OutputInterface {
private:
    sf::RenderWindow& window;
    std::queue<sf::Event>& keyboardEvents;
    std::string menuTitle;
    TextureStorageSFML storage;
public:

    explicit OutputSFML(sf::RenderWindow& window, std::queue<sf::Event>& keyboardEvents);
    void displayMenu(std::string title, std::vector<Button> buttons, size_t selected) final;
    void displayLevel(const std::shared_ptr<Field>& field,
                      std::vector<std::shared_ptr<AbstractEntity>> entities,
                      const std::shared_ptr<PlayerHandler>& handler,
                      std::vector<std::vector<size_t>> entityPos) final;
    void refreshScreen() final;
    bool pollEvents() final;
};


#endif //OOP_GAME_OUTPUTSFML_H
