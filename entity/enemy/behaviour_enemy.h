//
// Created by Егор Федоров on 10.12.2023.
//

#ifndef OOP_GAME_BEHAVIOUR_ENEMY_H
#define OOP_GAME_BEHAVIOUR_ENEMY_H

#include "abstract_enemy.h"

template <typename MoveBehaviour, typename InteractBehaviour>
class BehaviourEnemy : public AbstractEnemy {
private:
    MoveBehaviour moveBehaviour;
    InteractBehaviour interactBehaviour;
    size_t timer = 0;
    size_t activationPeriod;
public:
    void activate(std::shared_ptr<Field> field,
                  std::vector<std::shared_ptr<AbstractEntity>> entities,
                  std::vector<std::vector<size_t>>& entityPos) final;

    std::shared_ptr<AbstractEntity> getCopy() override;

    BehaviourEnemy(size_t x, size_t y, size_t health, size_t maxHealth, size_t damage, uint32_t textureID, size_t activationPeriod, MoveBehaviour moveBehaviour, InteractBehaviour interactBehaviour);

    BehaviourEnemy(const BehaviourEnemy& bEnemy);
};

template<typename MoveBehaviour, typename InteractBehaviour>
BehaviourEnemy<MoveBehaviour, InteractBehaviour>::BehaviourEnemy(const BehaviourEnemy &bEnemy) : AbstractEnemy(bEnemy) {
    x = bEnemy.x;
    y = bEnemy.y;
    health = bEnemy.health;
    maxHealth = bEnemy.maxHealth;
    damage = bEnemy.damage;
    id = bEnemy.id;
    textureID = bEnemy.textureID;
    observer = bEnemy.observer;
    interactBehaviour = bEnemy.interactBehaviour;
    moveBehaviour = bEnemy.moveBehaviour;
    activationPeriod = bEnemy.activationPeriod;
}

template<typename MoveBehaviour, typename InteractBehaviour>
BehaviourEnemy<MoveBehaviour, InteractBehaviour>::BehaviourEnemy(size_t x, size_t y,  size_t health, size_t maxHealth, size_t damage,
                                                                 uint32_t textureID, size_t activationPeriod,
                                                                 MoveBehaviour moveBehaviour,
                                                                 InteractBehaviour interactBehaviour) : AbstractEnemy(x, y, health, maxHealth, damage,
                                                                                                                      nullptr, textureID) {
                                                                    this->moveBehaviour = moveBehaviour;
                                                                    this->interactBehaviour = interactBehaviour;
                                                                    this->activationPeriod = activationPeriod;
                                                                 }

template<typename MoveBehaviour, typename InteractBehaviour>
std::shared_ptr<AbstractEntity> BehaviourEnemy<MoveBehaviour, InteractBehaviour>::getCopy() {
    BehaviourEnemy<MoveBehaviour, InteractBehaviour> copy(*this);
    return std::make_shared<BehaviourEnemy<MoveBehaviour, InteractBehaviour>>(copy);
}

template<typename MoveBehaviour, typename InteractBehaviour>
void BehaviourEnemy<MoveBehaviour, InteractBehaviour>::activate(std::shared_ptr<Field> field,
                                                                std::vector<std::shared_ptr<AbstractEntity>> entities,
                                                                std::vector<std::vector<size_t>>& entityPos) {
    timer++;
    if (timer < activationPeriod)
        return;
    timer = 0;
    AbstractEntity::Direction dir = moveBehaviour.moveDirection({x, y}, entities, field, entityPos);
    AbstractEntity::MoveResult res = move(dir, field, entityPos);
    if (res == AbstractEntity::MoveResult::entity) {
        auto coords = getDirectionCoords(dir, field);
        interactBehaviour.interact(entities[entityPos[coords.first][coords.second]-1],
                                   field, dir, entityPos, damage);
    }

}


#endif //OOP_GAME_BEHAVIOUR_ENEMY_H
