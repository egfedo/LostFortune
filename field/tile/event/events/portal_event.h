//
// Created by Егор Федоров on 17.10.2023.
//

#ifndef OOP_GAME_PORTAL_EVENT_H
#define OOP_GAME_PORTAL_EVENT_H

#include "../event_interface.h"

class PortalEvent : public EventInterface {
private:
    std::pair<size_t, size_t> newCoord;

public:
    PortalEvent(std::pair<size_t, size_t> newCoord);
    uint32_t eventHandler(AbstractEntity * instance, std::shared_ptr<Field> field, std::vector<std::vector<size_t>>& entityPos) final;
};


#endif //OOP_GAME_PORTAL_EVENT_H
