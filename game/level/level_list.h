//
// Created by Егор Федоров on 09.12.2023.
//

#ifndef OOP_GAME_LEVEL_LIST_H
#define OOP_GAME_LEVEL_LIST_H

#include <vector>
#include <utility>
#include "../../input_output/implementations/file_wrapper.h"
#include "level.h"

class LevelList {
private:
    std::vector<std::string> levelInfoPaths;
    std::vector<std::string> fieldInfoPaths;
    FileWrapper levelFile;
    FileWrapper fieldFile;

public:
    Level loadLevel(size_t id);
    
};


#endif //OOP_GAME_LEVEL_LIST_H
