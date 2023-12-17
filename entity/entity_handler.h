//
// Created by Егор Федоров on 08.12.2023.
//

#ifndef OOP_GAME_ENTITY_HANDLER_H
#define OOP_GAME_ENTITY_HANDLER_H

#include <utility>
#include "entity.h"

class EntityHandler {
private:
    std::shared_ptr<Field> field;
    std::vector<std::shared_ptr<AbstractEntity>> entities;
    std::vector<std::vector<size_t>> entityPos;
public:
    explicit EntityHandler(const std::shared_ptr<PlayerHandler>& handler, const std::shared_ptr<Field>& field);
    bool movePlayer(AbstractEntity::Direction direction);
    void moveEnemies();
    void setObserver(const std::shared_ptr<ChangeObserver>& observer);
    std::shared_ptr<PlayerHandler> getPlayer();
    std::shared_ptr<Field> getField();
    EntityHandler(const EntityHandler& handler);
    EntityHandler& operator = (const EntityHandler& handler);
    std::vector<std::shared_ptr<AbstractEntity>> getDrawable();
    std::vector<std::vector<size_t>>& getEntityPos();
    std::shared_ptr<AbstractEntity> getEntity(size_t id);
    void addEntity(const std::shared_ptr<AbstractEntity>& entity);
};


#endif //OOP_GAME_ENTITY_HANDLER_H
