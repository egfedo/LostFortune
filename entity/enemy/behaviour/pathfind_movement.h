//
// Created by Егор Федоров on 10.12.2023.
//

#ifndef OOP_GAME_PATHFIND_MOVEMENT_H
#define OOP_GAME_PATHFIND_MOVEMENT_H

#include "../../entity.h"

#define DEFAULT_WATCH_RANGE 7
#define DEFAULT_PURSUIT_RANGE 10

class PathfindMovement {
private:
    bool pursuing = false;
    double watchRange = DEFAULT_WATCH_RANGE;
    double pursuitRange = DEFAULT_PURSUIT_RANGE;
public:
    AbstractEntity::Direction moveDirection(std::pair<int64_t, int64_t> currentPos,
                                            std::vector<std::shared_ptr<AbstractEntity>>& entities,
                                            const std::shared_ptr<Field>& field,
                                            std::vector<std::vector<size_t>>& entityPos);
    PathfindMovement() = default;
    PathfindMovement(size_t watchRange, size_t pursuitRange);
};


#endif //OOP_GAME_PATHFIND_MOVEMENT_H
