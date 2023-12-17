//
// Created by Егор Федоров on 08.12.2023.
//

#include "patrol_movement.h"

AbstractEntity::Direction
PatrolMovement::moveDirection(std::pair<int64_t, int64_t> currentPos, std::vector<std::shared_ptr<AbstractEntity>>& entities,
                              const std::shared_ptr<Field>& field, std::vector<std::vector<size_t>>& entityPos) {
    std::pair<int64_t, int64_t> destination;
    if (movingTo == Direction::A) {
        if (currentPos == pointA) {
            movingTo = Direction::B;
            destination = pointB;
        }
        else
            destination = pointA;

    }
    else {
        if (currentPos == pointB) {
            movingTo = Direction::A;
            destination = pointA;
        }
        else
            destination = pointB;
    }
    std::pair<int64_t, int64_t> vector = {destination.first - currentPos.first,
                                        destination.second - currentPos.second};

    if (abs(vector.first) > abs(vector.second)) {
        if (vector.first > 0)
            return AbstractEntity::Direction::right;
        else
            return AbstractEntity::Direction::left;
    }
    else if (abs(vector.second) > abs(vector.first)) {
        if (vector.second > 0)
            return AbstractEntity::Direction::down;
        else
            return AbstractEntity::Direction::up;
    }
    else {
        if (vector.first > 0)
            return AbstractEntity::Direction::right;
        else
            return AbstractEntity::Direction::down;
    }
}

PatrolMovement::PatrolMovement(std::pair<int64_t, int64_t> pointA,
                               std::pair<int64_t, int64_t> pointB) :
                               pointA(pointA), pointB(pointB) {}

PatrolMovement::PatrolMovement() : PatrolMovement({0, 0}, {0, 1}){

}
