//
// Created by Егор Федоров on 09.12.2023.
//

#ifndef OOP_GAME_TEXTURESTORAGESFML_H
#define OOP_GAME_TEXTURESTORAGESFML_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class TextureStorageSFML {
private:
    std::vector<std::string> texturePaths = {
            "./boris.png",
            "./wall.png",
            "./chest.png",
            "./coin_icon.png",
            "./damage_icon.png",
            "./heal.png",
            "./heart.png",
            "./portal.png",
            "./spike.png",
            "./ribbit.png",
            "./coin_item.png",
            "./godfather.png",
            "./ki.png",
            "./fog.png",
            "./weak_fog.png",
            "./strong_fog.png",
    };
    std::vector<sf::Texture> textures;

    std::vector<std::string> fontPaths = {
            "./font.ttf"
    };
    std::vector<sf::Font> fonts;

public:
    enum Texture {
        boris,
        wall,
        chest,
        coin_icon,
        damage_icon,
        heal,
        heart,
        portal,
        spike,
        ribbit,
        coin_item,
        godfather,
        ki,
        fog,
        weak_fog,
        strong_fog
    };

    enum Font {
        general
    };

    void loadTextures();
    const sf::Texture& getTexture(Texture textureID);
    const sf::Font& getFont(Font fontID);
};


#endif //OOP_GAME_TEXTURESTORAGESFML_H
