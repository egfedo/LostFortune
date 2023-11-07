//
// Created by Егор Федоров on 05.11.2023.
//

#include "test_output.h"

void TestOutput::displayMenu(std::vector<std::string> buttons, size_t selected) {
    clear();
    size_t buttonsLen = 2 * buttons.size() - 1;
    size_t startPos = (23 / 2) - (buttonsLen / 2);
    for(size_t i = 0; i < startPos; i++) {
        printw("\n");
    }
    for(size_t i = 0; i < buttons.size(); i++) {
        if (i == selected) {
            printw("%s> ", std::string(34, ' ').c_str());
            attron(A_BOLD);
            printw("[%s]\n\n", buttons[i].c_str());
            attroff(A_BOLD);
        }
//            std::cout << std::string(34, ' ') << "> \x1b[1m[" << buttons[i] << "]\x1b[0m \n\n";
        else
            printw("%s[%s]\n\n", std::string(35, ' ').c_str(), buttons[i].c_str());
//            std::cout << std::string(35, ' ') << "[" << buttons[i] << "]\n\n";
    }
    for(size_t i = startPos + buttonsLen; i < 23; i++) {
        printw("\n");
    }
    refresh();
}

void TestOutput::displayLevel(Field& field, std::pair<size_t, size_t> playerLoc, Player& instance) {
    clear();
    printw("\n");
    size_t offset = field.getWidth() + (field.getWidth() - 1) * 2;
    offset = 40 - (offset / 2);
    char out;
    for(size_t i = 0; i < field.getHeight(); i++) {
        printw("%s", std::string(offset, ' ').c_str());
        for(size_t j = 0; j < field.getWidth(); j++) {
            if (i == playerLoc.second and j == playerLoc.first) {
                out = 'B';
                init_pair(4, COLOR_GREEN, COLOR_BLACK);
                attron(COLOR_PAIR(4));
            }
            else if (field.getTile(j, i).getEvent() != nullptr) {
                if (typeid(*field.getTile(j, i).getEvent()) == typeid(HealEvent)) {
                    out = '%';
                    init_pair(1, COLOR_RED, COLOR_BLACK);
                    attron(COLOR_PAIR(1));
                }
                if (typeid(*field.getTile(j, i).getEvent()) == typeid(SpikeEvent)) {
                    init_pair(2, COLOR_CYAN, COLOR_BLACK);
                    attron(COLOR_PAIR(2));
                    out = '^';
                }
                if (typeid(*field.getTile(j, i).getEvent()) == typeid(PortalEvent)) {
                    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
                    attron(COLOR_PAIR(3));
                    out = '@';
                }
            }
            else {
                switch (field.getTile(j, i).getTexture()) {
                    case 2:
                        out = '#';
                        break;
                    default:
                        out = '.';
                }
            }
            addch(out);
            printw("  ");
            attroff(COLOR_PAIR(1));
            attroff(COLOR_PAIR(2));
            attroff(COLOR_PAIR(3));
            attroff(COLOR_PAIR(4));
        }
        printw("\n");
    }
    std::stringstream ss;
    ss << "[Health: " << instance.getHealth() << "/" << instance.getMaxHealth() << "] [Damage: "
    << instance.getDamage() << "]\n";
    offset = 40 - (ss.str().size() / 2);
    printw("%s%s", std::string(offset, ' ').c_str(), ss.str().c_str());
    refresh();
}