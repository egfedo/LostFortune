//
// Created by Егор Федоров on 17.10.2023.
//

#include "portal_event.h"

#include <utility>

PortalEvent::PortalEvent(std::pair<size_t, size_t> newCoord) : newCoord(std::move(newCoord)) {}


uint32_t PortalEvent::eventHandler(AbstractEntity *instance, std::shared_ptr<Field> field, std::vector<std::vector<size_t>>& entityPos) {
    instance->setCoords(newCoord.first, newCoord.second, field, entityPos);
    return 1;
}
