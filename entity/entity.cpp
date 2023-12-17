//
// Created by Егор Федоров on 08.12.2023.
//

#include "entity.h"

#include <utility>

size_t AbstractEntity::getCoord(AbstractEntity::Coord n) const {
    switch (n) {
        case AbstractEntity::Coord::X:
            return x;
        case AbstractEntity::Coord::Y:
            return y;
    }
}

AbstractEntity::MoveResult AbstractEntity::setCoord(Coord n, size_t value, const std::shared_ptr<Field>& field,
                              std::vector<std::vector<size_t>>& entityPos) {
    size_t nx, ny;
    nx = x;
    ny = y;
    switch (n) {
        case AbstractEntity::Coord::X:
            nx = value;
        case AbstractEntity::Coord::Y:
            ny = value;
    }
    nx = std::min(nx, field->getWidth() - 1);
    ny = std::min(ny, field->getHeight() - 1);
    return updateCoords(nx, ny, field, entityPos);
}

AbstractEntity::MoveResult AbstractEntity::setCoords(size_t x, size_t y, const std::shared_ptr<Field>& field,
                               std::vector<std::vector<size_t>>& entityPos) {
    size_t nx, ny;
    nx = std::min(x, field->getWidth() - 1);
    ny = std::min(y, field->getHeight() - 1);
    if (field->getTile(nx, ny).getPassability()) {
        if (entityPos[nx][ny] == 0) {
            entityPos[this->x][this->y] = 0;
            entityPos[nx][ny] = id;
            this->x = nx;
            this->y = ny;
            if (observer != nullptr) {
                LevelPositionUpdate upd({x, y}, id);
                observer->logLevelUpdate(std::make_shared<LevelPositionUpdate>(upd));
            }
            return MoveResult::success;
        }
        else
            return MoveResult::entity;
    }
    else
        return MoveResult::wall;
}

AbstractEntity::MoveResult AbstractEntity::updateCoords(size_t nx, size_t ny, const std::shared_ptr<Field>& field, std::vector<std::vector<size_t>>& entityPos) {
    if (field->getTile(nx, ny).getPassability()) {
        if (entityPos[nx][ny] == 0) {
            entityPos[x][y] = 0;
            entityPos[nx][ny] = id;
            x = nx;
            y = ny;
            if (observer != nullptr) {
                LevelPositionUpdate update({x, y}, id);
                observer->logLevelUpdate(std::make_shared<LevelPositionUpdate>(update));
            }
            std::shared_ptr<EventInterface> ptr = field->getTile(nx, ny).getEvent();
            if (ptr != nullptr) {
                uint32_t uses = ptr->eventHandler(this, field, entityPos);
                if (uses == 0) {
                    Tile eTile = field->getTile(nx, ny);
                    eTile.setEvent(nullptr);
                    field->setTile(nx, ny, eTile);
                }
            }
            return MoveResult::success;
        }
        else
            return MoveResult::entity;
    }
    else
        return MoveResult::wall;
}

AbstractEntity::MoveResult AbstractEntity::move(Direction dir, const std::shared_ptr<Field>& field,
                          std::vector<std::vector<size_t>>& entityPos) {
    auto newCoords = getDirectionCoords(dir, field);
    if (newCoords == std::pair(x, y))
        return MoveResult::success;
    return updateCoords(newCoords.first, newCoords.second, field, entityPos);
}

void AbstractEntity::setObserver(std::shared_ptr<ChangeObserver> observer) {
    this->observer = std::move(observer);
}

AbstractEntity::AbstractEntity(size_t x, size_t y, uint32_t textureID)
                               : x(x), y(y), textureID(textureID) {}

AbstractEntity::AbstractEntity(size_t x, size_t y,
                               std::shared_ptr<ChangeObserver> observer,
                               uint32_t textureID)
                               : AbstractEntity(x, y, textureID) {
    observer = std::move(observer);
}

AbstractEntity::AbstractEntity() : x(0), y(0), observer(nullptr), textureID(0) {}

AbstractEntity::AbstractEntity(const AbstractEntity &handler) {
    x = handler.x;
    y = handler.y;
    observer = handler.observer;
}

uint32_t AbstractEntity::getTextureID() {
    return textureID;
}

std::pair<size_t, size_t> AbstractEntity::getDirectionCoords(AbstractEntity::Direction dir, const std::shared_ptr<Field>& field) {
    size_t nx, ny;
    nx = x;
    ny = y;
    switch (dir) {
        case AbstractEntity::Direction::up:
            if (ny != 0)
                ny--;
            break;
        case AbstractEntity::Direction::down:
            if (ny != field->getHeight() - 1)
                ny++;
            break;
        case AbstractEntity::Direction::left:
            if (nx != 0)
                nx--;
            break;
        case AbstractEntity::Direction::right:
            if (nx != field->getWidth() - 1)
                nx++;
            break;
        case AbstractEntity::Direction::none:
            break;
    }
    return {nx, ny};
}

void AbstractEntity::setID(size_t id) {
    this->id = id;
}

