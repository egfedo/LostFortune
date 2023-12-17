//
// Created by Егор Федоров on 24.11.2023.
//

#include "change_observer.h"
#include "../logging/message/impl/new_level_message.h"

#include <utility>


void ChangeObserver::logLevelUpdate(const std::shared_ptr<LevelUpdateInterface>& update) {
    if (state == ObserveState::menu)
        throw std::runtime_error("Change observer got a level update while being in menu mode");
    updates.push(update);
}

bool ChangeObserver::executeLevelUpdates() {
    if (state == ObserveState::menu)
        throw std::runtime_error("Change observer got a level update while being in menu mode");
    StatContainer newStats(oldHandler->getPlayer());
    auto playerHandler = oldHandler->getPlayer();
    size_t updAmt = updates.size();

    if (!updates.empty()) {
        while (!updates.empty()) {
            updates.front()->applyUpdate(oldHandler, output, newStats, logger);
            updates.pop();
        }
    }
    if (newStats != container) {
        container = newStats;
    }
    if (updAmt != 0)
        output->displayLevel(oldHandler->getField(),
                             oldHandler->getDrawable(),
                             playerHandler,
                             oldHandler->getEntityPos());
    return output->pollEvents();
}

void ChangeObserver::startLevel(std::shared_ptr<EntityHandler> handler) {
    oldHandler = std::shared_ptr<EntityHandler>(std::move(handler));
    oldHandler->setObserver(nullptr);
    auto playerHandler = oldHandler->getPlayer();
    container = StatContainer(playerHandler);
    output->displayLevel(oldHandler->getField(),
                         oldHandler->getDrawable(),
                         playerHandler,
                         oldHandler->getEntityPos());
    state = ObserveState::level;
    NewLevelMessage msg(oldHandler->getField()->getWidth(),
                        oldHandler->getField()->getHeight(),
                        playerHandler->getCoord(PlayerHandler::Coord::X),
                        playerHandler->getCoord(PlayerHandler::Coord::Y));
    logger->logMessage(&msg);
}

void ChangeObserver::startMenu(Menu &menu) {
    this->oldMenu = std::make_shared<Menu>(menu);
    output->displayMenu(oldMenu->getTitle(), oldMenu->getButtons(), oldMenu->getCurrent());
    state = ObserveState::menu;
}

void ChangeObserver::logMenuUpdate(const std::shared_ptr<MenuUpdateInterface>& update) {
    if (state == ObserveState::level)
        throw std::runtime_error("Change observer got a menu update while being in level mode");
    menuUpdates.push(update);
}

bool ChangeObserver::executeMenuUpdates() {
    if (state == ObserveState::level)
        throw std::runtime_error("Change observer got a menu update while being in level mode");
    size_t updAmt = menuUpdates.size();
    if (!menuUpdates.empty()) {
        while (!menuUpdates.empty()) {
            menuUpdates.front()->applyUpdate(oldMenu, output);
            menuUpdates.pop();
        }
    }
    if (updAmt != 0)
        output->displayMenu(oldMenu->getTitle(), oldMenu->getButtons(), oldMenu->getCurrent());
    return output->pollEvents();
}

ChangeObserver::ChangeObserver(std::shared_ptr<OutputInterface> output,
                               std::shared_ptr<Logger> logger) :
                               output(std::move(output)), logger(std::move(logger)),
                               state(ObserveState::none) {}
