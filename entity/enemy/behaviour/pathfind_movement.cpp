//
// Created by Егор Федоров on 10.12.2023.
//

#include "pathfind_movement.h"

AbstractEntity::Direction PathfindMovement::moveDirection(std::pair<int64_t, int64_t> currentPos,
                                                          std::vector<std::shared_ptr<AbstractEntity>> &entities,
                                                          const std::shared_ptr<Field>& field,
                                                          std::vector<std::vector<size_t>>& entityPos) {
    std::pair<int64_t, int64_t> targetPos = {entities[0]->getCoord(AbstractEntity::Coord::X), entities[0]->getCoord(AbstractEntity::Coord::Y)};

    std::vector<std::vector<std::pair<int, int>>> directions(field->getWidth(), std::vector<std::pair<int, int>>(field->getHeight(), {0, 0}));

    std::queue<std::pair<int64_t, int64_t>> tiles;
    tiles.push(currentPos);
    std::pair<int64_t, int64_t> current;

    std::vector<std::pair<int, int>> possibleDirections = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1},
            {1, 1},
            {-1, -1},
            {1, -1},
            {-1, 1},
    };
    while (!tiles.empty()) {
        current = tiles.front();
        tiles.pop();

        for (auto direction : possibleDirections) {
            std::pair<int64_t, int64_t> neighbor = {current.first + direction.first, current.second + direction.second};

            if (neighbor.first < 0 || neighbor.first >= field->getWidth()
            || neighbor.second < 0 || neighbor.second >= field->getHeight())
                continue;

            if (!field->getTile(neighbor.first, neighbor.second).getPassability())
                continue;

            if (directions[neighbor.first][neighbor.second] != std::pair<int, int>(0, 0))
                continue;

            if(entityPos[neighbor.first][neighbor.second] > 1)
                continue;

            if (direction.first != 0 && direction.second != 0 &&
                (!field->getTile(current.first, current.second + direction.second).getPassability() ||
                        entityPos[current.first][current.second + direction.second] > 1) &&
                (!field->getTile(current.first + direction.first, current.second).getPassability() ||
                        entityPos[current.first + direction.first][current.second] > 1))
                continue;

            directions[neighbor.first][neighbor.second] = direction;

            if (neighbor == targetPos) {
                while(!tiles.empty())
                    tiles.pop();
                break;
            }
            tiles.push(neighbor);
        }
    }
    double distance = 0;
    current = targetPos;
    std::pair<int, int> prev;
    if (directions[current.first][current.second] == std::pair(0, 0))
        return AbstractEntity::Direction::none;

    while (current != currentPos) {
        prev = {directions[current.first][current.second].first, directions[current.first][current.second].second};
        distance += std::sqrt(std::pow(directions[current.first][current.second].first, 2) +
                std::pow(directions[current.first][current.second].second, 2));
//        std::cout << "\t" << std::sqrt(std::pow(directions[current.first][current.second].first, 2) +
//                                       std::pow(directions[current.first][current.second].second, 2)) << "\n";
        current = {current.first - directions[current.first][current.second].first,
                   current.second - directions[current.first][current.second].second};
    }
    std::cout << distance << "\n";
    if (distance > watchRange && !pursuing)
        return AbstractEntity::Direction::none;

    pursuing = true;

    if (distance > pursuitRange) {
        pursuing = false;
        return AbstractEntity::Direction::none;
    }

    if (prev == std::pair(1, 0))
        return AbstractEntity::Direction::right;
    if (prev == std::pair(-1, 0))
        return AbstractEntity::Direction::left;
    if (prev == std::pair(0, 1))
        return AbstractEntity::Direction::down;
    if (prev == std::pair(0, -1))
        return AbstractEntity::Direction::up;
    if (prev == std::pair(1, 1)) {
        if (field->getTile(currentPos.first+1, currentPos.second).getPassability())
            return AbstractEntity::Direction::right;
        else
            return AbstractEntity::Direction::down;
    }
    if (prev == std::pair(-1, -1)) {
        if (field->getTile(currentPos.first-1, currentPos.second).getPassability())
            return AbstractEntity::Direction::left;
        else
            return AbstractEntity::Direction::up;
    }
    if (prev == std::pair(1, -1)) {
        if (field->getTile(currentPos.first, currentPos.second-1).getPassability())
            return AbstractEntity::Direction::up;
        else
            return AbstractEntity::Direction::right;
    }
    if (prev == std::pair(-1, 1)) {
        if (field->getTile(currentPos.first, currentPos.second+1).getPassability())
            return AbstractEntity::Direction::down;
        else
            return AbstractEntity::Direction::left;
    }
}

PathfindMovement::PathfindMovement(size_t watchRange, size_t pursuitRange) :
watchRange(watchRange), pursuitRange(pursuitRange) {
}
