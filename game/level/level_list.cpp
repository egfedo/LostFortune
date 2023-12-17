//
// Created by Егор Федоров on 09.12.2023.
//

#include "level_list.h"
#include "level_builder.h"

Level LevelList::loadLevel(size_t id) {
    if (id > levelInfoPaths.size()) {
        throw std::logic_error("Attempt to get level by id that doesn't exist");
    }
    levelFile.reopen(levelInfoPaths.at(id));
    fieldFile.reopen(fieldInfoPaths.at(id));
    LevelBuilder builder;
    return builder.buildLevel(&levelFile, &fieldFile);
}
