//
// Created by Егор Федоров on 12.11.2023.
//

#include "level_builder.h"
#include "../../entity/enemy/behaviour_enemy.h"
#include "../../entity/enemy/behaviour/patrol_movement.h"
#include "../../entity/enemy/behaviour/knockback_attack.h"
#include "../../entity/enemy/behaviour/pathfind_movement.h"
#include "../../entity/enemy/behaviour/deal_damage_interaction.h"

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
    std::shared_ptr<Field> fieldPtr = std::make_shared<Field>(fieldOut);
    PlayerHandler handler = PlayerHandler(fieldOut.getEntrance().first, fieldOut.getEntrance().second, std::make_shared<Player>(playerOut), nullptr, 1);
    EntityHandler eHandler(std::make_shared<PlayerHandler>(handler), fieldPtr);
    BehaviourEnemy<PatrolMovement, KnockbackAttack> ribbit(
            5, 5, 10, 10, 3, 2, 30,
            PatrolMovement({5, 5}, {5, 10}),
            KnockbackAttack(3)
            );
    BehaviourEnemy<PatrolMovement, KnockbackAttack> ribbit2(
            9, 5, 10, 10, 3, 2, 30,
            PatrolMovement({9, 5}, {13, 5}),
            KnockbackAttack(3)
    );
    BehaviourEnemy<PathfindMovement, DealDamageInteraction> ribbit3(
            9, 10, 10, 10, 5, 3, 15,
            PathfindMovement(6, 10),
            DealDamageInteraction(5)
    );
    eHandler.addEntity(std::make_shared<BehaviourEnemy<PatrolMovement, KnockbackAttack>>(ribbit));
    eHandler.addEntity(std::make_shared<BehaviourEnemy<PatrolMovement, KnockbackAttack>>(ribbit2));
    eHandler.addEntity(std::make_shared<BehaviourEnemy<PathfindMovement, DealDamageInteraction>>(ribbit3));
    return Level(std::make_shared<EntityHandler>(eHandler));
}
