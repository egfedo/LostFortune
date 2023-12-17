//
// Created by Егор Федоров on 26.11.2023.
//

#include "LevelFieldUpdate.h"

LevelFieldUpdate::LevelFieldUpdate(std::pair<uint32_t, uint32_t> coords, Tile newTile) : coords(std::move(coords)), newTile(newTile){

}

void LevelFieldUpdate::applyUpdate(std::shared_ptr<EntityHandler> prevState, std::shared_ptr<OutputInterface> output,
                                   StatContainer format, std::shared_ptr<Logger> logger) {
    prevState->getField()->setTile(coords.first, coords.second, newTile);
}
