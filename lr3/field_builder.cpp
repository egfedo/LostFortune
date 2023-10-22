//
// Created by Егор Федоров on 22.10.2023.
//

#include "field_builder.h"

//
//void FieldBuilder::buildField(Field &instance, FieldBuilder::Level level) {
//    Tile wall(false, 1);
//    Tile grass(true, 2);
//    switch (level) {
//        case FieldBuilder::Level::first:
//
//            return;
//        case FieldBuilder::Level::second:
//            return;
//    }
//
//}

std::unique_ptr<Field> FieldBuilder::buildField(FieldBuilder::Level level) {
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
        SpikeEvent spike(5, 3);
        HealEvent heal(10, 4);

        for (size_t i = 0; i < field.getWidth(); i++) {
            if (not std::getline(in, line))
                return nullptr;

            for (size_t j = 0; j < field.getHeight(); j++) {
                if (j >= line.length())
                    return nullptr;
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
        PortalEvent portal({0, 0}, 0);
        for (size_t i = 0; i < portals.size() - 1; i++) {
            portal = PortalEvent(portals[i+1], 5);
            eventSample.setEvent(std::make_shared<PortalEvent>(portal));
            field.setTile(portals[i].first, portals[i].second, eventSample);
        }
        portal = PortalEvent(portals[0], 5);
        eventSample.setEvent(std::make_shared<PortalEvent>(portal));
        field.setTile(portals[portals.size()-1].first, portals[portals.size()-1].second, eventSample);
        return std::make_unique<Field>(field);
    }

    return nullptr;
}
