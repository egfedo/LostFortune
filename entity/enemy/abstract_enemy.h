//
// Created by Егор Федоров on 08.12.2023.
//

#ifndef OOP_GAME_ABSTRACT_ENEMY_H
#define OOP_GAME_ABSTRACT_ENEMY_H


#include "../entity.h"

class AbstractEnemy : public AbstractEntity {
protected:
    size_t health;
    size_t maxHealth;
    size_t damage;
public:
    AbstractEnemy(size_t x, size_t y, size_t health, size_t maxHealth, size_t damage, const std::shared_ptr<ChangeObserver>& observer, uint32_t textureID);

    bool isAlive() override;
    size_t getHealth() override;
    void dealDamage(size_t amount) override;
    void heal(size_t amount) override;

    size_t getMaxHealth() override;
    void upgradeMaxHealth(size_t amount) override;

    size_t getDamage() override;
    void increaseDamage(size_t value) override;
    void decreaseDamage(size_t value) override;


    virtual void activate(std::shared_ptr<Field> field,
                  std::vector<std::shared_ptr<AbstractEntity>> entities,
                  std::vector<std::vector<size_t>>& entityPos) = 0;
};


#endif //OOP_GAME_ABSTRACT_ENEMY_H
