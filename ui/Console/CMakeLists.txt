add_library(TinyGamesConsoleUI
        DiceConsoleUi.h
        DiceConsoleUi.cpp
        ShifumiConsoleUi.h
        ShifumiConsoleUi.cpp
)

target_include_directories(TinyGamesConsoleUI
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(TinyGamesConsoleUI
    PRIVATE
        TinyGamesDice
        TinyGamesShifumi
)