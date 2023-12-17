//
// Created by Егор Федоров on 27.09.2023.
//

#ifndef OOP_GAME_PLAYER_HANDLER_H
#define OOP_GAME_PLAYER_HANDLER_H

class PlayerHandler;
class Field;
#include <cstddef>
#include "player.h"

#include "../../game/change_observer.h"
#include "../entity.h"

class PlayerHandler : public AbstractEntity {
private:
    std::shared_ptr<Player> player;
public:

    PlayerHandler(size_t x, size_t y, Player& instance, uint32_t textureID);
    PlayerHandler(size_t x, size_t y, std::shared_ptr<Player> instance,
                  std::shared_ptr<ChangeObserver> observer,
                  uint32_t textureID, size_t id = 0);
    ~PlayerHandler() = default;

    bool isAlive() final;
    size_t getHealth() final;
    void dealDamage(size_t amount) final;
    void heal(size_t amount) final;

    size_t getMaxHealth() final;
    void upgradeMaxHealth(size_t amount) final;

    size_t getDamage() final;
    void increaseDamage(size_t value) final;
    void decreaseDamage(size_t value) final;

    bool checkEquip(Player::equipID name);
    void giveEquip(Player::equipID name);
    void removeEquip(Player::equipID name);

    size_t getConsumeAmt(Player::consumeID name);
    void giveConsume(Player::consumeID name, size_t amount);
    void removeConsume(Player::consumeID name, size_t amount);


    PlayerHandler(const PlayerHandler& handler);
    PlayerHandler& operator = (const PlayerHandler& handler);

    std::shared_ptr<AbstractEntity> getCopy() override;
};

#include "../../game/updates/impl/LevelPositionUpdate.h"
#include "../../game/updates/impl/LevelConsumableUpdate.h"
#include "../../game/updates/impl/LevelMainStatUpdate.h"
#include "../../game/updates/impl/LevelEquipmentUpdate.h"
#include "../../field/field.h"
#endif //OOP_GAME_PLAYER_HANDLER_H
