#include <iostream>

#include "player_handler.h"
void printPlayer(Player& player) {
    std::cout << "Player:\n";
    std::cout << "\tHealth " << player.getHealth() << "\n";
    std::cout << "\tMax Health " << player.getMaxHealth() << "\n";
    std::cout << "\tDamage " << player.getDamage() << "\n";
    std::cout << "Equipment:\n";
    std::cout << "\tSword " << player.checkEquip(Player::equipID::sword) << "\n";
    std::cout << "\tShield " << player.checkEquip(Player::equipID::shield) << "\n";
    std::cout << "Consumables:\n";
    std::cout << "\tBomb " << player.getConsAmt(Player::consumeID::bomb) << "\n";
    std::cout << "\tHeal " <<player.getConsAmt(Player::consumeID::heal) << "\n";
    std::cout << std::endl;
}

void printHandler(PlayerHandler& handler) {
    std::cout << "Handler:\n";
    std::cout << "\tX " << handler.getCoord(PlayerHandler::Coord::X) << "\n";
    std::cout << "\tY " << handler.getCoord(PlayerHandler::Coord::Y) << "\n";
    std::cout << std::endl;
}

void printField(Field& field) {
    std::cout << "Field:\n";
    for (size_t i = 0; i < field.getHeight(); i++) {
        for (size_t j = 0; j < field.getWidth(); j++) {
            std::cout << "[" << field.getTile(j, i).getTexture() << "|" << field.getTile(j, i).getPassability() << "] ";

        }
        std::cout << "\n";
    }
}
int main() {
    Player player(10, 20, 4);
    printPlayer(player);
    player.setEquip(Player::equipID::sword, true);
    player.setHealth(23);
    printPlayer(player);
    player.setMaxHealth(25);
    printPlayer(player);
    player.setDamage(300);
    printPlayer(player);
    Tile t(true, 1);
    Tile t2(false, 2);
    Field field(20, 15, {0, 0}, {14, 14}, t);
    field.setTile(10, 10, t2);
    PlayerHandler handler(1, 1, player, field);
    printHandler(handler);
    handler.move(PlayerHandler::Direction::up);
    printHandler(handler);
    handler.giveConsume(Player::consumeID::heal, 300);
    printPlayer(player);
    handler.move(PlayerHandler::Direction::down);
    printHandler(handler);
    handler.setCoords(10, 9);
    printHandler(handler);
    printField(field);
    return 0;
}
