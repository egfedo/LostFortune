//
// Created by Егор Федоров on 05.11.2023.
//

#include "test_output.h"

void TestOutput::displayMenu(std::string title, std::vector<Button> buttons, size_t selected) {
    clear();
    size_t buttonsLen = 2 * buttons.size() + 1;
    size_t startPos = (23 / 2) - (buttonsLen / 2);
    size_t titleOffset = 40 - (title.length() / 2);
    for(size_t i = 0; i < startPos; i++) {
        printw("\n");
    }
    printw("%s%s\n\n", std::string(titleOffset, ' ').c_str(), title.c_str());
    for(size_t i = 0; i < buttons.size(); i++) {
        if (i == selected) {
            printw("%s> ", std::string(34, ' ').c_str());
            attron(A_BOLD);
            printw("[%s]\n\n", buttons[i].text.c_str());
            attroff(A_BOLD);
        }
//            std::cout << std::string(34, ' ') << "> \x1b[1m[" << buttons[i] << "]\x1b[0m \n\n";
        else
            printw("%s[%s]\n\n", std::string(35, ' ').c_str(), buttons[i].text.c_str());
//            std::cout << std::string(35, ' ') << "[" << buttons[i] << "]\n\n";
    }
    for(size_t i = startPos + buttonsLen; i < 23; i++) {
        printw("\n");
    }
    displayWarning();
    refresh();
}

void TestOutput::displayLevel(const std::shared_ptr<Field>& field,
                              std::vector<std::shared_ptr<AbstractEntity>> entities,
                              const std::shared_ptr<PlayerHandler>& handler,
                              std::vector<std::vector<size_t>> entityPos) {
    clear();
    printw("\n");
    size_t offset = field->getWidth() + (field->getWidth() - 1);
    offset = 40 - (offset / 2);
    char out;
    for(size_t i = 0; i < field->getHeight(); i++) {
        printw("%s", std::string(offset, ' ').c_str());
        for(size_t j = 0; j < field->getWidth(); j++) {

            switch (field->getTile(j, i).getTexture()) {
                case 2:
                    out = '#';
                    break;
                default:
                    out = '.';
            }

            if (field->getTile(j, i).getEvent() != nullptr) {
                auto ptr = field->getTile(j, i).getEvent().get();
                if (typeid(*ptr) == typeid(HealEvent)) {
                    out = '%';
                    init_pair(1, COLOR_RED, COLOR_BLACK);
                    attron(COLOR_PAIR(1));
                }
                if (typeid(*ptr) == typeid(SpikeEvent)) {
                    init_pair(2, COLOR_CYAN, COLOR_BLACK);
                    attron(COLOR_PAIR(2));
                    out = '^';
                }
                if (typeid(*ptr) == typeid(PortalEvent)) {
                    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
                    attron(COLOR_PAIR(3));
                    out = '@';
                }
                if (typeid(*ptr) == typeid(ChestEvent)) {
                    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
                    attron(COLOR_PAIR(5));
                    out = '$';
                }
            }
            if (i == field->getExit().second and j == field->getExit().first) {
                out = 'E';
            }
            if (i == handler->getCoord(AbstractEntity::Coord::Y) and j == handler->getCoord(AbstractEntity::Coord::X)) {
                out = 'B';
                init_pair(4, COLOR_GREEN, COLOR_BLACK);
                attron(COLOR_PAIR(4));
            }

            addch(out);
            printw(" ");
            attroff(COLOR_PAIR(1));
            attroff(COLOR_PAIR(2));
            attroff(COLOR_PAIR(3));
            attroff(COLOR_PAIR(4));
            attroff(COLOR_PAIR(5));
        }
        printw("\n");
    }
    std::stringstream ss;
    ss << "[Health: " << handler->getHealth() << "/" << handler->getMaxHealth() << "] [Damage: "
    << handler->getDamage() << "]";
    if (handler->checkEquip(Player::equipID::sword))
        ss << " [SWORD]";
    if (handler->checkEquip(Player::equipID::shield))
        ss << " [SHIELD]";
    if (handler->getConsumeAmt(Player::consumeID::coins))
        ss << " [COINS: " << handler->getConsumeAmt(Player::consumeID::coins) << "]";
    if (handler->getConsumeAmt(Player::consumeID::bomb))
        ss << " [BOMBS: " << handler->getConsumeAmt(Player::consumeID::bomb) << "]";
    if (handler->getConsumeAmt(Player::consumeID::heal))
        ss << " [HEAL: " << handler->getConsumeAmt(Player::consumeID::heal) << "]";
    ss << "\n";
    offset = 40 - (ss.str().size() / 2);
    printw("%s%s", std::string(offset, ' ').c_str(), ss.str().c_str());
    displayWarning();
    refresh();
}

TestOutput::TestOutput() {
    initscr();
    start_color();
    curs_set(0);
}

TestOutput::~TestOutput() {
    endwin();
}

void TestOutput::displayWarning() {
    int x, y;
    getmaxyx(stdscr, x, y);
    if (not (x == 24 and y == 80)) {
        clear();
        printw("This terminal size (%d x %d) is unsupported. Please change it to 80x24", y, x);
    }
}


void TestOutput::refreshScreen() {
    refresh();
}


bool TestOutput::pollEvents() {
    return false;
}
