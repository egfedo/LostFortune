//
// Created by Егор Федоров on 26.11.2023.
//

#ifndef OOP_GAME_LEVELFIELDUPDATE_H
#define OOP_GAME_LEVELFIELDUPDATE_H

#include <utility>
#include "../../../field/tile/tile.h"


class LevelFieldUpdate : public LevelUpdateInterface {
private:
    std::pair<uint32_t, uint32_t> coords;
    Tile newTile;
public:
    LevelFieldUpdate(std::pair<uint32_t, uint32_t> coords, Tile newTile);
    void applyUpdate(std::shared_ptr<EntityHandler> prevState, std::shared_ptr<OutputInterface> output, StatContainer format, std::shared_ptr<Logger> logger);
};


#endif //OOP_GAME_LEVELFIELDUPDATE_H
