//
// Created by Егор Федоров on 01.10.2023.
//

#include "tile.h"

bool Tile::getPassability() {
    return passable;
}

void Tile::setPassability(bool state) {
    passable = state;
}

size_t Tile::getTexture() {
    return textureID;
}

void Tile::setTexture(size_t id) {
    textureID = id;
}

Tile::Tile(bool passable, size_t textureID) : passable(passable), textureID(textureID), event(nullptr) {}

Tile::Tile() : passable(true), textureID(0), event(nullptr) {}

std::shared_ptr<EventInterface> Tile::getEvent() {
    return event;
}

void Tile::setEvent(std::shared_ptr<EventInterface> event) {
    this->event = event;
}
