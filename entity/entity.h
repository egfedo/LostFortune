//
// Created by Егор Федоров on 08.12.2023.
//

#ifndef OOP_GAME_ENTITY_H
#define OOP_GAME_ENTITY_H

#include <utility>
#include <algorithm>

class Field;
class ChangeObserver;


class AbstractEntity {
protected:
    size_t x;
    size_t y;
    uint32_t textureID = 0;
    size_t id = 0;
    std::shared_ptr<ChangeObserver> observer;
public:

    enum class Direction {
        up,
        down,
        left,
        right,
        none
    };

    enum class Coord {X, Y};
    enum class MoveResult {
        success,
        entity,
        wall
    };
    AbstractEntity();
    AbstractEntity(size_t x, size_t y, uint32_t textureID);
    AbstractEntity(size_t x, size_t y, std::shared_ptr<ChangeObserver> observer, uint32_t textureID);

    AbstractEntity(const AbstractEntity &handler);

    size_t getCoord(Coord n) const;
    MoveResult setCoord(Coord n, size_t value,
                        const std::shared_ptr<Field>& field,
                        std::vector<std::vector<size_t>>& entityPos);
    MoveResult setCoords(size_t x, size_t y, const std::shared_ptr<Field>& field, std::vector<std::vector<size_t>>& entityPos);

    virtual MoveResult move(Direction dir, const std::shared_ptr<Field>& field, std::vector<std::vector<size_t>>& entityPos);

    virtual bool isAlive() = 0;
    virtual size_t getHealth() = 0;
    virtual void dealDamage(size_t amount) = 0;
    virtual void heal(size_t amount) = 0;

    virtual size_t getMaxHealth() = 0;
    virtual void upgradeMaxHealth(size_t amount) = 0;

    virtual size_t getDamage() = 0;
    virtual void increaseDamage(size_t value) = 0;
    virtual void decreaseDamage(size_t value) = 0;

    void setObserver(std::shared_ptr<ChangeObserver> observer);

    virtual std::shared_ptr<AbstractEntity> getCopy() = 0;

    uint32_t getTextureID();

    void setID(size_t id);

protected:
    std::pair<size_t, size_t> getDirectionCoords(Direction dir, const std::shared_ptr<Field>& field);
    MoveResult updateCoords(size_t nx, size_t ny, const std::shared_ptr<Field>& field, std::vector<std::vector<size_t>>& entityPos);
};

#include "../field/field.h"
#include "../game/change_observer.h"

#endif //OOP_GAME_ENTITY_H
