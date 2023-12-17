cmake_minimum_required(VERSION 3.26)
project(OOP_game)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)


add_executable(OOP_game main.cpp
        entity/player/player.cpp
        entity/player/player.h
        entity/player/player_handler.h
        entity/player/player_handler.cpp
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
        game/change_observer.h
        game/change_observer.cpp
        game/updates/level_update_interface.h
        game/updates/level_update_interface.cpp
        game/updates/impl/LevelMainStatUpdate.h
        game/updates/impl/LevelMainStatUpdate.cpp
        game/updates/impl/LevelEquipmentUpdate.h
        game/updates/impl/LevelEquipmentUpdate.cpp
        game/updates/impl/LevelConsumableUpdate.h
        game/updates/impl/LevelConsumableUpdate.cpp
        game/stat_formatter.h
        game/stat_formatter.cpp
        game/updates/impl/LevelPositionUpdate.h
        game/updates/impl/LevelPositionUpdate.cpp
        game/updates/impl/LevelFieldUpdate.h
        game/updates/impl/LevelFieldUpdate.cpp
        input_output/output_interface.h
        input_output/output_interface.cpp
        game/updates/menu_update_interface.h
        game/updates/menu_update_interface.cpp
        game/updates/impl/MenuUpdateButtonSelect.h
        game/updates/impl/MenuUpdateButtonSelect.cpp
        input_output/implementations/OutputSFML.h
        input_output/implementations/OutputSFML.cpp
        input_output/implementations/InputSFML.h
        input_output/implementations/InputSFML.cpp
        game/change_observer_interface.h
        game/change_observer_interface.cpp
        logging/message/abstract_log_message.h
        logging/message/abstract_log_message.cpp
        logging/message/impl/new_level_message.h
        logging/message/impl/new_level_message.cpp
        logging/message/impl/player_win_message.h
        logging/message/impl/player_win_message.cpp
        logging/message/impl/player_lost_message.h
        logging/message/impl/player_lost_message.cpp
        util/KeyboardMapperSMFL.h
        util/KeyboardMapperSMFL.cpp
        logging/message/impl/key_press_command_message.h
        logging/message/impl/key_press_command_message.cpp
        logging/message/impl/key_press_message.h
        logging/message/impl/key_press_message.cpp
        logging/log_writer_interface.h
        logging/log_writer_interface.cpp
        logging/impl/cout_writer.h
        logging/impl/cout_writer.cpp
        logging/impl/file_writer.h
        logging/impl/file_writer.cpp
        logging/logger.h
        logging/logger.cpp
        entity/entity.h
        entity/entity.cpp
        entity/enemy/abstract_enemy.h
        entity/enemy/abstract_enemy.cpp
        entity/enemy/behaviour/patrol_movement.h
        entity/enemy/behaviour/patrol_movement.cpp
        entity/entity_handler.h
        entity/entity_handler.cpp
        game/level/level_list.h
        game/level/level_list.cpp
        util/TextureStorageSFML.h
        util/TextureStorageSFML.cpp
        entity/enemy/behaviour/knockback_attack.h
        entity/enemy/behaviour/knockback_attack.cpp
        entity/enemy/behaviour_enemy.h
        entity/enemy/behaviour_enemy.cpp
        entity/enemy/behaviour/pathfind_movement.h
        entity/enemy/behaviour/pathfind_movement.cpp
        entity/enemy/behaviour/deal_damage_interaction.h
        entity/enemy/behaviour/deal_damage_interaction.cpp)

target_link_libraries(OOP_game sfml-graphics sfml-audio ncurses)
target_compile_features(OOP_game PRIVATE cxx_std_20)

if(WIN32)
    add_custom_command(
            TARGET OOP_game
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:OOP_game>
            VERBATIM)
endif()

install(TARGETS OOP_game)