cmake_minimum_required(VERSION 3.26)
project(OOP_game)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lcurses")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

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
        lr3/events/portal_event.cpp
        lr3/field_builder.h
        lr3/field_builder.cpp
        lr3/line_stream.h
        lr3/line_stream.cpp
        lr3/file_wrapper.h
        lr3/file_wrapper.cpp
        lr4/game.h
        lr4/game.cpp
        lr4/output_interface.h
        lr4/output_interface.cpp
        lr4/button.h
        lr4/button.cpp
        lr4/input_interface.h
        lr4/input_interface.cpp
        lr4/test/test_input.h
        lr4/test/test_input.cpp
        lr4/test/test_output.h
        lr4/test/test_output.cpp
        lr4/menu.h
        lr4/menu.cpp
        lr4/button_action.h
        lr4/button_action.cpp
        lr4/level.h
        lr4/level.cpp)

target_link_libraries(OOP_game sfml-graphics sfml-audio ncurses)