//
// Created by Егор Федоров on 01.10.2023.
//

#include "field.h"

#include <utility>
#include <iostream>
Field::Field(size_t width, size_t height) : width(width), height(height) {
    if (width < MIN_SIZE)
        width = MIN_SIZE;
    if (height < MIN_SIZE)
        height = MIN_SIZE;
    array = new Tile*[width];
    Tile* line;
    for(size_t i = 0; i < width; i++) {
        line = new Tile[height];
        array[i] = line;
    }
    entrance = std::pair<size_t, size_t>(0, 0);
    exit = std::pair<size_t, size_t>(width - 1, height - 1);
}

Field::Field() : Field(DEF_WIDTH, DEF_HEIGHT) {}

Tile Field::getTile(size_t x, size_t y) {
    x = std::min(x, width - 1);
    y = std::min(y, height - 1);
    return array[x][y];
}

void Field::setTile(size_t x, size_t y, Tile tile) {
    x = std::min(x, width - 1);
    y = std::min(y, height - 1);
    array[x][y] = tile;
}

Field::~Field() {
    for(size_t i = 0; i < width; i++) {
        delete [] array[i];
    }
    delete [] array;
}

std::pair<size_t, size_t> Field::getEntrance() {
    return entrance;
}

std::pair<size_t, size_t> Field::getExit() {
    return exit;
}

size_t Field::getWidth() {
    return width;
}

size_t Field::getHeight() {
    return height;
}

Field::Field(const Field & field) : width(field.width), height(field.height),
    entrance(field.entrance), exit(field.exit) {
    array = new Tile*[width];
    Tile* line;
    for(size_t i = 0; i < width; i++) {
        line = new Tile[height];
        array[i] = line;
        std::copy(field.array[i], field.array[i] + field.height, array[i]);
        // WIP copying event interface
    }
    for(size_t i = 0; i < width; i++) {
        for(size_t j = 0; j < height; j++) {
            if (array[i][j].getEvent() != nullptr) {
                EventInterface* ptr = array[i][j].getEvent().get();
                if (typeid(*ptr) == typeid(HealEvent)) {
                    std::shared_ptr<HealEvent> tmp = std::static_pointer_cast<HealEvent>(field.array[i][j].getEvent());
                    array[i][j].setEvent(std::make_shared<HealEvent>(*tmp));
                }
                if (typeid(*ptr) == typeid(SpikeEvent)) {
                    std::shared_ptr<SpikeEvent> tmp = std::static_pointer_cast<SpikeEvent>(field.array[i][j].getEvent());
                    array[i][j].setEvent(std::make_shared<SpikeEvent>(*tmp));
                }
                if (typeid(*ptr) == typeid(PortalEvent)) {
                    std::shared_ptr<PortalEvent> tmp = std::static_pointer_cast<PortalEvent>(field.array[i][j].getEvent());
                    array[i][j].setEvent(std::make_shared<PortalEvent>(*tmp));
                }
                if (typeid(*ptr) == typeid(ChestEvent)) {
                    std::shared_ptr<ChestEvent> tmp = std::static_pointer_cast<ChestEvent>(field.array[i][j].getEvent());
                    array[i][j].setEvent(std::make_shared<ChestEvent>(*tmp));
                }
            }
        }
    }
}

Field& Field::operator = (const Field& field) {
    Field temp(field);
    width = temp.width;
    height = temp.height;
    entrance = temp.entrance;
    exit = temp.exit;
    std::swap(array, temp.array);
    return *this;
}

Field::Field(Field&& field) : array(nullptr), width(0), height(0),
    entrance({0, 0}), exit({0, 0}) {
    std::swap(array, field.array);
    std::swap(width, field.width);
    std::swap(height, field.height);
    std::swap(entrance, field.entrance);
    std::swap(exit, field.exit);
}

Field &Field::operator = (Field &&field) {
    if (this != &field) {
        std::swap(array, field.array);
        std::swap(width, field.width);
        std::swap(height, field.height);
        std::swap(entrance, field.entrance);
        std::swap(exit, field.exit);
    }
    return *this;
}

Field::Field(size_t width, size_t height, std::pair<size_t, size_t> entrance,
             std::pair<size_t, size_t> exit, Tile tile) : Field(width, height) {
    entrance.first = std::min(width, entrance.first);
    entrance.second = std::min(height, entrance.second);
    exit.first = std::min(width, exit.first);
    exit.second = std::min(height, exit.second);
    this->entrance = entrance;
    this->exit = exit;
    for (size_t i = 0; i < width; i++) {
        for (size_t j = 0; j < height; j++) {
            array[i][j] = tile;
        }
    }
}
