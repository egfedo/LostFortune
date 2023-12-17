//
// Created by Егор Федоров on 08.12.2023.
//

#ifndef OOP_GAME_PATROL_MOVEMENT_H
#define OOP_GAME_PATROL_MOVEMENT_H

#include <utility>
#include "../../entity.h"

class PatrolMovement {
private:
    std::pair<int64_t, int64_t> pointA;
    std::pair<int64_t, int64_t> pointB;
    enum class Direction {
        A, B
    };
    Direction movingTo = Direction::B;
public:
    AbstractEntity::Direction moveDirection(std::pair<int64_t, int64_t> currentPos,
                                            std::vector<std::shared_ptr<AbstractEntity>>& entities,
                                            const std::shared_ptr<Field>& field,
                                            std::vector<std::vector<size_t>>& entityPos);
    PatrolMovement(std::pair<int64_t, int64_t> pointA, std::pair<int64_t, int64_t> pointB);
    PatrolMovement();
};


#endif //OOP_GAME_PATROL_MOVEMENT_H
