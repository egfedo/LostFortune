//
// Created by Егор Федоров on 17.10.2023.
//

#ifndef OOP_GAME_PORTAL_EVENT_H
#define OOP_GAME_PORTAL_EVENT_H

#include "../event_interface.h"

class PortalEvent : public EventInterface {
private:
    std::pair<size_t, size_t> newCoord;
    size_t textureID;

public:
    PortalEvent(std::pair<size_t, size_t> newCoord, size_t textureID);
    size_t getTextureID() const override;
    void eventHandler(PlayerHandler * instance) override;
};


#endif //OOP_GAME_PORTAL_EVENT_H
