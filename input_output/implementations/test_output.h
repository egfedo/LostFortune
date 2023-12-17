//
// Created by Егор Федоров on 05.11.2023.
//

#ifndef OOP_GAME_TEST_OUTPUT_H
#define OOP_GAME_TEST_OUTPUT_H

#include "../output_interface.h"
#include <iostream>
#include "../../field/tile/event/events/spike_event.h"
#include "../../field/tile/event/events/heal_event.h"
#include "../../field/tile/event/events/portal_event.h"
#include "../../field/tile/event/events/chest_event.h"
#include <ncurses.h>
#include <sstream>

class TestOutput : public OutputInterface {
private:
    void displayWarning();
public:
    TestOutput();
    void displayMenu(std::string title, std::vector<Button> buttons, size_t selected) final;
//    virtual void redrawButton(std::vector<Button> buttons, size_t oldPos, size_t newPos) = 0;
    void displayLevel(const std::shared_ptr<Field>& field,
                      std::vector<std::shared_ptr<AbstractEntity>> entities,
                      const std::shared_ptr<PlayerHandler>& handler,
                      std::vector<std::vector<size_t>> entityPos) final;
    void refreshScreen() final;
    bool pollEvents() final;
    ~TestOutput();
};


#endif //OOP_GAME_TEST_OUTPUT_H
