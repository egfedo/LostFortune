//
// Created by Егор Федоров on 26.11.2023.
//

#include "stat_formatter.h"

#include <utility>

void StatContainer::add(StatContainer::MainStat stat, uint32_t value) {
    generalStats[static_cast<uint32_t>(stat)] = value;
}

void StatContainer::add(Player::equipID equipment, bool state) {
    this->equipment[static_cast<uint32_t>(equipment)] = state;
}

void StatContainer::add(Player::consumeID consumable, uint32_t amount) {
    consumables[static_cast<uint32_t>(consumable)] = amount;
}

bool StatContainer::operator==(const StatContainer &other) {
    for(size_t i = 0; i < generalStats.size(); i++)
        if (generalStats[i] != other.generalStats[i])
            return false;

    for(size_t i = 0; i < equipment.size(); i++)
        if (equipment[i] != other.equipment[i])
            return false;

    for(size_t i = 0; i < consumables.size(); i++)
        if (consumables[i] != other.consumables[i])
            return false;

    return true;
}

bool StatContainer::operator!=(const StatContainer &other) {
    return !(operator==(other));
}

StatContainer::StatContainer(std::vector<uint32_t> generalStats, std::vector<bool> equipment,
                             std::vector<uint32_t> consumables) : generalStats(std::move(generalStats)),
                             equipment(std::move(equipment)), consumables(std::move(consumables)){

}

StatContainer::StatContainer(const std::shared_ptr<PlayerHandler>& handler) {
    generalStats.push_back(handler->getHealth());
    generalStats.push_back(handler->getMaxHealth());
    generalStats.push_back(handler->getDamage());

    for (auto equip : Player::possibleEquips)
        equipment.push_back(handler->checkEquip(equip));
    for (auto consume : Player::possibleConsumes)
        consumables.push_back(handler->getConsumeAmt(consume));
}

uint32_t StatContainer::getStat(int vector, uint32_t id) {
    switch(vector) {
        case 0:
            return generalStats[id];
        case 1:
            return equipment[id];
        case 2:
            return consumables[id];
        default:
            return 0;
    }
}

StatContainer::StatContainer() = default;

