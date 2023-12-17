//
// Created by Егор Федоров on 04.12.2023.
//

#include "OutputSFML.h"
#include <sstream>
#include "../../field/tile/event/events/heal_event.h"
#include "../../field/tile/event/events/spike_event.h"
#include "../../field/tile/event/events/portal_event.h"
#include "../../field/tile/event/events/chest_event.h"

void OutputSFML::displayMenu(std::string title, std::vector<Button> buttons, size_t selected) {
    window.clear();
    sf::Text titleText(title, storage.getFont(TextureStorageSFML::general), 128);
    float pos = 640 - (titleText.getGlobalBounds().width / 2);
    titleText.setPosition(pos, 100);
    sf::Text buttonText("", storage.getFont(TextureStorageSFML::general), 64);
    window.draw(titleText);
    float buttonOffset = 100 + titleText.getGlobalBounds().height + 150;
    for (size_t i = 0; i < buttons.size(); i++) {
        buttonText.setString(buttons[i].text);
        pos = 640 - (buttonText.getGlobalBounds().width / 2);
        buttonText.setPosition(pos, buttonOffset);
        if (i == selected)
            buttonText.setStyle(sf::Text::Style::Underlined);
        else
            buttonText.setStyle(sf::Text::Style::Regular);
        window.draw(buttonText);
        buttonOffset += buttonText.getGlobalBounds().height + 100;
    }
    window.display();
}


void OutputSFML::displayLevel(const std::shared_ptr<Field>& field,
                              std::vector<std::shared_ptr<AbstractEntity>> entities,
                              const std::shared_ptr<PlayerHandler>& handler,
                              std::vector<std::vector<size_t>> entityPos) {
    window.clear();
    sf::Vector2f tilePos = {320, 56};
    sf::Sprite sprite{storage.getTexture(TextureStorageSFML::wall)};
    sf::Sprite player{storage.getTexture(TextureStorageSFML::boris)};
    sprite.setScale(2, 2);
    player.setScale(2, 2);
    for (size_t i = 0; i < field->getHeight(); i++) {
        for (size_t j = 0; j < field->getWidth(); j++) {

            if ((std::pow((int)handler->getCoord(AbstractEntity::Coord::X) - (int)j, 2) +
                    std::pow((int)handler->getCoord(AbstractEntity::Coord::Y) - (int)i, 2)) - 49 > 0.0001) {
                tilePos.x += 32;
                continue;
            }
            if (field->getTile(j, i).getTexture() == 2) {
                sprite.setTexture(storage.getTexture(TextureStorageSFML::wall));
                sprite.setPosition(tilePos);
                window.draw(sprite);
            }
            if (entityPos[j][i] != 0) {
                switch(entities[entityPos[j][i]-1]->getTextureID()) {
                    case 1:
                        sprite.setTexture(storage.getTexture(TextureStorageSFML::boris));
                        break;
                    case 2:
                        sprite.setTexture(storage.getTexture(TextureStorageSFML::ribbit));
                        break;
                    case 3:
                        sprite.setTexture(storage.getTexture(TextureStorageSFML::godfather));
                        break;
                    default:
                        sprite.setTexture(storage.getTexture(TextureStorageSFML::coin_icon));
                }
                sprite.setPosition(tilePos);
                window.draw(sprite);
            } else if (field->getTile(j, i).getEvent() != nullptr) {
                auto ptr = field->getTile(j, i).getEvent().get();
                if (typeid(*ptr) == typeid(HealEvent)) {
                    sprite.setTexture(storage.getTexture(TextureStorageSFML::heal));
                }
                if (typeid(*ptr) == typeid(SpikeEvent)) {
                    sprite.setTexture(storage.getTexture(TextureStorageSFML::spike));
                }
                if (typeid(*ptr) == typeid(PortalEvent)) {
                    sprite.setTexture(storage.getTexture(TextureStorageSFML::portal));
                }
                if (typeid(*ptr) == typeid(ChestEvent)) {
                    auto chest = std::dynamic_pointer_cast<ChestEvent>(field->getTile(j, i).getEvent());
                    switch(chest->consumeType()) {
                        case Player::consumeID::coins:
                            sprite.setTexture(storage.getTexture(TextureStorageSFML::coin_item));
                            break;
                        default:
                            sprite.setTexture(storage.getTexture(TextureStorageSFML::chest));
                    }

                }
                sprite.setPosition(tilePos);
                window.draw(sprite);
            }
            if ((std::pow((int)handler->getCoord(AbstractEntity::Coord::X) - (int)j, 2) +
                 std::pow((int)handler->getCoord(AbstractEntity::Coord::Y) - (int)i, 2)) - 36 > 0.0001) {
                sprite.setTexture(storage.getTexture(TextureStorageSFML::strong_fog));
                sprite.setPosition(tilePos);
                window.draw(sprite);
            } else if ((std::pow((int)handler->getCoord(AbstractEntity::Coord::X) - (int)j, 2) +
                 std::pow((int)handler->getCoord(AbstractEntity::Coord::Y) - (int)i, 2)) - 27 > 0.0001) {
                sprite.setTexture(storage.getTexture(TextureStorageSFML::fog));
                sprite.setPosition(tilePos);
                window.draw(sprite);
            }
            else if ((std::pow((int)handler->getCoord(AbstractEntity::Coord::X) - (int)j, 2) +
                      std::pow((int)handler->getCoord(AbstractEntity::Coord::Y) - (int)i, 2)) - 17 > 0.0001) {
                sprite.setTexture(storage.getTexture(TextureStorageSFML::weak_fog));
                sprite.setPosition(tilePos);
                window.draw(sprite);
            }
//            std::pair<float, float> vec = {(float)j - (float)handler->getCoord(AbstractEntity::Coord::X), (float)i - (float)handler->getCoord(AbstractEntity::Coord::Y)};
//            std::pair<float, float> last = {-1, -1};
//            std::
//            for (float multiplier = 10; multiplier > 0; multiplier -= 1) {
//                if (!field->getTile(static_cast<size_t>(vec.first * (multiplier/10) + handler->getCoord(AbstractEntity::Coord::X)),
//                                  static_cast<size_t>(vec.second * (multiplier/10) + handler->getCoord(AbstractEntity::Coord::Y))).getPassability()) {
//                    if (vec.first + 1 < 0.0000001 && vec.second + 1 < 0.0000001) {
//                        last =
//                    }
//                }
//            }
            tilePos.x += 32;
        }
        tilePos = {320, tilePos.y + 32};
    }
    float x = 320;
    std::stringstream ss;
    ss << handler->getHealth() << "/" << handler->getMaxHealth();
    sf::Text text(ss.str(), storage.getFont(TextureStorageSFML::general), 46);
    text.setPosition({x, tilePos.y + 14});
    window.draw(text);
    x += text.getGlobalBounds().width + 8;
    sprite.setTexture(storage.getTexture(TextureStorageSFML::heart));
    sprite.setPosition({x, tilePos.y + 32});
    window.draw(sprite);
    x += sprite.getGlobalBounds().width + 32;
    ss.str("");
    ss << handler->getDamage();
    text.setString(ss.str());
    text.setPosition({x, tilePos.y + 14});
    window.draw(text);
    x += text.getGlobalBounds().width + 8;
    sprite.setTexture(storage.getTexture(TextureStorageSFML::damage_icon));
    sprite.setPosition({x, tilePos.y + 32});
    window.draw(sprite);
    x += sprite.getGlobalBounds().width + 32;
    ss.str("");
    ss << handler->getConsumeAmt(Player::consumeID::coins);
    text.setString(ss.str());
    text.setPosition({x, tilePos.y + 14});
    window.draw(text);
    x += text.getGlobalBounds().width + 8;
    sprite.setTexture(storage.getTexture(TextureStorageSFML::coin_icon));
    sprite.setPosition({x, tilePos.y + 32});
    window.draw(sprite);
    window.display();
}


void OutputSFML::refreshScreen() {
//    window->display();
}

bool OutputSFML::pollEvents() {

    if (window.isOpen()) {
//        std::cout << "open" << "\n";
        for (sf::Event event{}; window.pollEvent(event);) {
//        std::cout << "event" << "\n";
            // Close window: exit

            if (event.type == sf::Event::Closed) {
                window.close();
                return true;
            }
            if (event.type == sf::Event::KeyPressed) {
                keyboardEvents.push(event);
            }
        }
    }

    return false;
}

OutputSFML::OutputSFML(sf::RenderWindow& window, std::queue<sf::Event>& keyboardEvents) : keyboardEvents(keyboardEvents), window(window) {
    this->window.close();
    this->window.create(sf::VideoMode(1280, 720), "Lost Fortune", sf::Style::Titlebar | sf::Style::Close);
    storage.loadTextures();
//    window->setSize({1280, 1152});
}
