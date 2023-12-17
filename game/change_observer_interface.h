//
// Created by Егор Федоров on 07.12.2023.
//

#ifndef OOP_GAME_CHANGE_OBSERVER_INTERFACE_H
#define OOP_GAME_CHANGE_OBSERVER_INTERFACE_H

#include <memory>
#include "updates/menu_update_interface.h"
#include "updates/level_update_interface.h"

class ChangeObserverInterface {
public:
    virtual void logMenuUpdate(std::shared_ptr<MenuUpdateInterface> update) = 0;
    virtual void logLevelUpdate(std::shared_ptr<LevelUpdateInterface> update) = 0;
};


#endif //OOP_GAME_CHANGE_OBSERVER_INTERFACE_H
