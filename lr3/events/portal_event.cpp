//
// Created by Егор Федоров on 17.10.2023.
//

#include "portal_event.h"

#include <utility>

PortalEvent::PortalEvent(std::pair<size_t, size_t> newCoord, size_t textureID) : newCoord(std::move(newCoord)),
    textureID(textureID) {}

size_t PortalEvent::getTextureID() const {
    return textureID;
}

void PortalEvent::eventHandler(PlayerHandler *instance) {
    instance->setCoords(newCoord.first, newCoord.second);
}
