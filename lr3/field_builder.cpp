//
// Created by Егор Федоров on 22.10.2023.
//

#include "field_builder.h"


int FieldBuilder::buildField(size_t level, Field &templt) {
    std::string filename;
    std::stringstream nameFormat;
    nameFormat << "./level" << static_cast<size_t>(level) << ".txt";
    filename = nameFormat.str();
    std::string line;
    std::ifstream in(filename);
    std::vector<size_t> params;
    size_t input;

    if (in.is_open()) {
        for(size_t i = 0; i < 2; i++) {
            std::getline(in, line);
            std::stringstream stream(line);
            stream >> input;
            if (input == 0) {
                in.close();
                return 2;
            }
            params.push_back(input);
        }
        for(size_t i = 0; i < 2; i++) {
            std::getline(in, line);
            std::stringstream stream(line);
            for(size_t j = 0; j < 2; j++) {
                stream >> input;
                params.push_back(input);
            }
        }
        Tile air(true, 0);
        Field field(params[0], params[1], {params[2], params[3]}, {params[4], params[5]}, air);
        Tile wall(false, 2);
        Tile floor(true, 1);
        Tile eventSample(true, 1);
        std::vector<std::pair<size_t, size_t>> portals;
        SpikeEvent spike(5);
        HealEvent heal(10);

        for (size_t i = 0; i < field.getWidth(); i++) {
            if (not std::getline(in, line)) {
                in.close();
                return 3;
            }

            for (size_t j = 0; j < field.getHeight(); j++) {
                if (j >= line.length()) {
                    in.close();
                    return 4;
                }
                switch (line[j]) {
                    case '#':
                        field.setTile(i, j, wall);
                        break;
                    case 'S':
                        eventSample.setEvent(std::make_shared<SpikeEvent>(spike));
                        field.setTile(i, j, eventSample);
                        break;
                    case 'H':
                        eventSample.setEvent(std::make_shared<HealEvent>(heal));
                        field.setTile(i, j, eventSample);
                        break;
                    case 'P':
                        portals.emplace_back(i, j);
                    default:
                        field.setTile(i, j, floor);
                        break;
                }
            }
        }
        PortalEvent portal({0, 0});
        for (size_t i = 0; i < portals.size() - 1; i++) {
            portal = PortalEvent(portals[i+1]);
            eventSample.setEvent(std::make_shared<PortalEvent>(portal));
            field.setTile(portals[i].first, portals[i].second, eventSample);
        }
        portal = PortalEvent(portals[0]);
        eventSample.setEvent(std::make_shared<PortalEvent>(portal));
        field.setTile(portals[portals.size()-1].first, portals[portals.size()-1].second, eventSample);
        bool entrancePassable = field.getTile(field.getEntrance().first, field.getEntrance().second).getPassability();
        bool exitPassable = field.getTile(field.getExit().first, field.getExit().second).getPassability();
        if (!entrancePassable or !exitPassable) {
            in.close();
            return 5;
        }
        if (not checkPassability(field)) {
            in.close();
            return 6;
        }
        templt = std::move(field);
        return 0;
    }
    in.close();
    return 1;
}

bool FieldBuilder::checkPassability(Field &instance) {
    Field temp = instance;
    floodFill(temp, instance.getEntrance());
    return not temp.getTile(instance.getExit().first, instance.getExit().second).getPassability();
}

void FieldBuilder::floodFill(Field &temp, std::pair<size_t, size_t> coords) {
    if (!temp.getTile(coords.first, coords.second).getPassability())
        return;
    Tile tile = temp.getTile(coords.first, coords.second);
    tile.setPassability(false);
    temp.setTile(coords.first, coords.second, tile);
    if (coords.first != 0)
        floodFill(temp, {coords.first - 1, coords.second});
    if (coords.first != temp.getWidth() - 1)
        floodFill(temp, {coords.first + 1, coords.second});
    if (coords.second != 0)
        floodFill(temp, {coords.first, coords.second - 1});
    if (coords.second != temp.getHeight() - 1)
        floodFill(temp, {coords.first, coords.second + 1});
}

