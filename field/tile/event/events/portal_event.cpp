//
// Created by Егор Федоров on 17.10.2023.
//

#include "portal_event.h"

#include <utility>

PortalEvent::PortalEvent(std::pair<size_t, size_t> newCoord) : newCoord(std::move(newCoord)) {}


uint32_t PortalEvent::eventHandler(PlayerHandler *instance) {
    instance->setCoords(newCoord.first, newCoord.second);
    return 1;
}
