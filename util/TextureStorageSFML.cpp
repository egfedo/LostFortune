//
// Created by Егор Федоров on 09.12.2023.
//

#include "TextureStorageSFML.h"

void TextureStorageSFML::loadTextures() {
    for (std::string& path : texturePaths) {
        sf::Texture texture;
        texture.loadFromFile(path);
        textures.push_back(texture);
    }
    for (std::string& path : fontPaths) {
        sf::Font font;
        font.loadFromFile(path);
        font.setSmooth(false);
        fonts.push_back(font);
    }
}

const sf::Texture &TextureStorageSFML::getTexture(TextureStorageSFML::Texture textureID) {
    return textures[textureID];
}

const sf::Font &TextureStorageSFML::getFont(TextureStorageSFML::Font fontID) {
    return fonts[fontID];
}

