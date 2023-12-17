//
// Created by Егор Федоров on 24.11.2023.
//

#ifndef OOP_GAME_CHANGE_OBSERVER_H
#define OOP_GAME_CHANGE_OBSERVER_H

class ChangeObserver;

#include "../entity/player/player_handler.h"
#include "menu/menu.h"
#include "updates/level_update_interface.h"
#include <queue>
#include "../input_output/output_interface.h"
#include "../input_output/input_interface.h"
#include "updates/menu_update_interface.h"
#include "change_observer_interface.h"
#include "../logging/logger.h"
#include "../entity/entity_handler.h"

class ChangeObserver {
private:
    enum class ObserveState {
        none, menu, level
    };
    std::shared_ptr<EntityHandler> oldHandler;
    std::shared_ptr<Menu> oldMenu;
    std::queue<std::shared_ptr<LevelUpdateInterface>> updates;
    std::queue<std::shared_ptr<MenuUpdateInterface>> menuUpdates;
    std::shared_ptr<OutputInterface> output = nullptr;
    std::shared_ptr<Logger> logger = nullptr;
    StatContainer container;
    ObserveState state;
public:
    ChangeObserver() = delete;
    explicit ChangeObserver(std::shared_ptr<OutputInterface> output, std::shared_ptr<Logger> logger);

    void startMenu(Menu& menu);
    void logMenuUpdate(const std::shared_ptr<MenuUpdateInterface>& update);
    bool executeMenuUpdates();

    void startLevel(std::shared_ptr<EntityHandler> handler);
    void logLevelUpdate(const std::shared_ptr<LevelUpdateInterface>& update);
    bool executeLevelUpdates();
};


#endif //OOP_GAME_CHANGE_OBSERVER_H
