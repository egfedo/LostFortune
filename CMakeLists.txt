cmake_minimum_required(VERSION 3.26)
project(OOP_game)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOP_game main.cpp
        player.cpp
        player.h
        player_handler.h
        player_handler.cpp
        lr2/tile.h
        lr2/tile.cpp
        lr2/field.h
        lr2/field.cpp
        lr3/event_interface.h
        lr3/event_interface.cpp
        lr3/events/heal_event.h
        lr3/events/heal_event.cpp
        lr3/events/spike_event.h
        lr3/events/spike_event.cpp
        lr3/events/portal_event.h
        lr3/events/portal_event.cpp)
