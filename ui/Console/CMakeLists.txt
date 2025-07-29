add_library(TinyGamesConsoleUI
        tinyGamesConsole.cpp
        tinyGamesConsole.h
)

include_directories(${CMAKE_SOURCE_DIR}/ui)

target_include_directories(TinyGamesConsoleUI
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(TinyGamesConsoleUI
    PRIVATE
        TinyGamesDice
        TinyGamesShifumi
)