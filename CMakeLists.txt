cmake_minimum_required(VERSION 3.26)
project(OOP_game)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lcurses")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(OOP_game main.cpp
        player/player.cpp
        player/player.h
        player/player_handler.h
        player/player_handler.cpp
        field/tile/tile.h
        field/tile/tile.cpp
        field/field.h
        field/field.cpp
        field/tile/event/event_interface.h
        field/tile/event/event_interface.cpp
        field/tile/event/events/heal_event.h
        field/tile/event/events/heal_event.cpp
        field/tile/event/events/spike_event.h
        field/tile/event/events/spike_event.cpp
        field/tile/event/events/portal_event.h
        field/tile/event/events/portal_event.cpp
        field/field_builder.h
        field/field_builder.cpp
        input_output/line_stream.h
        input_output/line_stream.cpp
        input_output/implementations/file_wrapper.h
        input_output/implementations/file_wrapper.cpp
        game/game.h
        game/game.cpp
        input_output/output_interface.h
        input_output/output_interface.cpp
        game/menu/button.h
        game/menu/button.cpp
        input_output/input_interface.h
        input_output/input_interface.cpp
        input_output/implementations/test_input.h
        input_output/implementations/test_input.cpp
        input_output/implementations/test_output.h
        input_output/implementations/test_output.cpp
        game/menu/menu.h
        game/menu/menu.cpp
        game/level/level.h
        game/level/level.cpp
        input_output/implementations/file_input.h
        input_output/implementations/file_input.cpp
        field/tile/event/events/chest_event.h
        field/tile/event/events/chest_event.cpp
        game/menu/menu_builder.h
        game/menu/menu_builder.cpp
        game/level/level_builder.h
        game/level/level_builder.cpp
        game/change_listener.h
        game/change_listener.cpp)

target_link_libraries(OOP_game sfml-graphics sfml-audio ncurses)