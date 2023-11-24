//
// Created by Егор Федоров on 12.11.2023.
//

#include "level_builder.h"

Level LevelBuilder::buildLevel(LineStream *levelStream, LineStream *fieldStream) {
    std::string line;
    std::stringstream input;
    uint32_t health, maxHealth, damage = 0;
    std::string equipName;
    bool equipped;
    size_t fileLen = 0;
    line = levelStream->getLine();
    input = std::stringstream(line);
    input >> fileLen;
    if (fileLen == 0)
        throw std::runtime_error("Wrong formatting for level file");
    line = levelStream->getLine();
    input = std::stringstream(line);
    input >> health >> maxHealth >> damage;
    if (health == 0 or maxHealth == 0 or damage == 0)
        throw std::runtime_error("Wrong formatting for level file");
    Player playerOut(health, maxHealth, damage);
    for (size_t i = 0; i < fileLen; i++) {
        line = levelStream->getLine();
        input = std::stringstream(line);
        input >> equipName >> equipped;
        if (string2equip.contains(equipName))
            playerOut.setEquip(string2equip[equipName], equipped);
    }
    Field fieldOut;
    FieldBuilder::buildField(fieldOut, fieldStream);

    return {playerOut, std::make_shared<Field>(fieldOut)};
}
