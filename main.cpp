#include <iostream>

#include "player_handler.h"
#include "lr3/events/spike_event.h"
#include "lr3/field_builder.h"

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
        std::cout << i << " ";
        if (i < 10)
            std::cout << " ";
        for (size_t j = 0; j < field.getWidth(); j++) {
            std::cout << "[" << field.getTile(j, i).getTexture() << "|" << field.getTile(j, i).getPassability() << "|" <<
            (field.getTile(j, i).getEvent() != nullptr) << "] ";

        }
        std::cout << "\n";

    }
    std::cout << "\tEntrance: " << field.getEntrance().first << " " << field.getEntrance().second << "\n";
    std::cout << "\tExit: " << field.getExit().first << " " << field.getExit().second << "\n";
    std::cout << std::endl;
}
int main() {
    Player player(10, 20, 4);
    printPlayer(player);
//    player.setEquip(Player::equipID::sword, true);
//    player.setHealth(23);
//    printPlayer(player);
//    player.setMaxHealth(25);
//    printPlayer(player);
//    player.setDamage(300);
//    printPlayer(player);
//    Tile t(true, 1);
//    Tile t2(true, 2);
//    SpikeEvent event(10, 1);
//    std::shared_ptr<SpikeEvent> pt1 = std::make_shared<SpikeEvent>(event);
//    t2.setEvent(std::make_shared<SpikeEvent>(event));
//    Field field(20, 15, {0, 0}, {14, 14}, t);
//    field.setTile(10, 10, t2);
    Field field;
    int code = FieldBuilder::buildField(FieldBuilder::Level::second, field);
    if (code != 0)
        return 0;
    printField(field);
    PlayerHandler handler(9, 8, player, field);
    printHandler(handler);
    printPlayer(player);
    handler.move(PlayerHandler::Direction::right);
    printHandler(handler);
    printPlayer(player);

//    std::cout << "moving down" << std::endl;
//    handler.move(PlayerHandler::Direction::down);
//    printPlayer(player);
//    printHandler(handler);
//    handler.move(PlayerHandler::Direction::up);
//    printHandler(handler);
//    handler.giveConsume(Player::consumeID::heal, 300);
//    printPlayer(player);
//    printHandler(handler);
//    handler.setCoords(10, 9);
//    printHandler(handler);
//    printField(field);
    return 0;
}
