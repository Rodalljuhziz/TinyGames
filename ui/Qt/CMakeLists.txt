find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


add_library(TinyGamesQtUI
        tinyGamesQt.ui
        tinyGamesQt.cpp
        tinyGamesQt.h
)

target_link_libraries(TinyGamesQtUI
        PRIVATE
        Qt6::Core
        Qt6::Widgets
        Qt6::Gui
)

include_directories(${CMAKE_SOURCE_DIR}/ui)

target_include_directories(TinyGamesQtUI
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)