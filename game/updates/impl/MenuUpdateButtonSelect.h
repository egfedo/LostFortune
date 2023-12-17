//
// Created by Егор Федоров on 27.11.2023.
//

#ifndef OOP_GAME_MENUUPDATEBUTTONSELECT_H
#define OOP_GAME_MENUUPDATEBUTTONSELECT_H


#include "../menu_update_interface.h"

class MenuUpdateButtonSelect : public MenuUpdateInterface {
private:
    InputInterface::Command direction;
public:
    explicit MenuUpdateButtonSelect(InputInterface::Command direction);
    void applyUpdate(std::shared_ptr<Menu> prevState, std::shared_ptr<OutputInterface> output) final;
};


#endif //OOP_GAME_MENUUPDATEBUTTONSELECT_H
