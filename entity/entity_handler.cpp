//
// Created by Егор Федоров on 08.12.2023.
//

#include "entity_handler.h"
#include "enemy/abstract_enemy.h"

EntityHandler::EntityHandler(const std::shared_ptr<PlayerHandler>& handler,
                             const std::shared_ptr<Field>& field) {
    entities.clear();
    entities.push_back(handler);
    entities[0]->setID(1);
    this->field = field;
    entityPos = std::vector<std::vector<size_t>>(field->getWidth(), std::vector<size_t>());
    for (size_t i = 0; i < field->getWidth(); i++) {
        entityPos[i] = std::vector<size_t>(field->getHeight(), 0);
    }
    entityPos[entities[0]->getCoord(AbstractEntity::Coord::X)]
            [entities[0]->getCoord(AbstractEntity::Coord::Y)] = 1;

}

bool EntityHandler::movePlayer(AbstractEntity::Direction direction) {
    auto& player = entities[0];
    if (player != nullptr) {
        player->move(direction, field, entityPos);
        return player->getCoord(AbstractEntity::Coord::X) == field->getExit().first &&
                player->getCoord(AbstractEntity::Coord::Y) == field->getExit().second;
    }
    return false;
}

void EntityHandler::moveEnemies() {
    for (size_t i = 0; i < entities.size();) {
        auto entity = entities[i];
        if (auto enemy = std::dynamic_pointer_cast<AbstractEnemy>(entity)) {
            enemy->activate(field, entities, entityPos);
        }
        i++;
    }
}

void EntityHandler::setObserver(const std::shared_ptr<ChangeObserver> &observer) {
    for (auto& entity : entities)
        entity->setObserver(observer);
    field->setObserver(observer);
}

std::shared_ptr<PlayerHandler> EntityHandler::getPlayer() {
    return std::dynamic_pointer_cast<PlayerHandler>(entities[0]);
}

EntityHandler::EntityHandler(const EntityHandler &handler) {
    Field tmpField = *handler.field;
    field = std::make_shared<Field>(tmpField);
    for(auto& entity : handler.entities) {
        entities.push_back(entity->getCopy());
    }
    entityPos = std::vector<std::vector<size_t>>(field->getWidth(), std::vector<size_t>());
    for (size_t i = 0; i < field->getWidth(); i++) {
        entityPos[i] = std::vector<size_t>(handler.entityPos[i]);
    }
}

EntityHandler &EntityHandler::operator=(const EntityHandler &handler) {
    EntityHandler tmp(handler);
    field = std::move(tmp.field);
    entities = std::move(tmp.entities);
    entityPos = std::move(tmp.entityPos);
    return *this;
}

std::shared_ptr<Field> EntityHandler::getField() {
    return field;
}

std::vector<std::shared_ptr<AbstractEntity>> EntityHandler::getDrawable() {
    std::vector<std::shared_ptr<AbstractEntity>> ret;
    for(auto& entity : entities) {
        if (entity->getTextureID() != 0) {
            ret.push_back(entity->getCopy());
        }
    }
    return ret;
}

std::vector<std::vector<size_t>> &EntityHandler::getEntityPos() {
    return entityPos;
}

std::shared_ptr<AbstractEntity> EntityHandler::getEntity(size_t id) {
    return entities[id-1];
}

void EntityHandler::addEntity(const std::shared_ptr<AbstractEntity> &entity) {
    entities.push_back(entity);
    entities.at(entities.size()-1)->setID(entities.size());
    entityPos[entities[entities.size()-1]->getCoord(AbstractEntity::Coord::X)]
    [entities[entities.size()-1]->getCoord(AbstractEntity::Coord::Y)] = entities.size();

}
