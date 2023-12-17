//
// Created by Егор Федоров on 05.11.2023.
//

#ifndef OOP_GAME_OUTPUT_INTERFACE_H
#define OOP_GAME_OUTPUT_INTERFACE_H

class OutputInterface;

#include <string>
#include "../field/field.h"
#include "../entity/player/player_handler.h"
#include "../game/menu/button.h"

class OutputInterface {
public:
    virtual void displayMenu(std::string title, std::vector<Button> buttons, size_t selected) = 0;
//    virtual void redrawButton(std::vector<Button> buttons, size_t oldPos, size_t newPos) = 0;
    virtual void displayLevel(const std::shared_ptr<Field>& field,
                              std::vector<std::shared_ptr<AbstractEntity>> entities,
                              const std::shared_ptr<PlayerHandler>& handler,
                              std::vector<std::vector<size_t>> entityPos) = 0;
    virtual void refreshScreen() = 0;
    virtual bool pollEvents() = 0;
};


#endif //OOP_GAME_OUTPUT_INTERFACE_H
