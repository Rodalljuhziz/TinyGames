add_library(TinyGamesSDLUI
        DiceSDLUi.cpp
        DiceSDLUi.h
        ShifumiSDLUi.cpp
        ShifumiSDLUi.h
)

target_include_directories(TinyGamesSDLUI
        PUBLIC
)


target_link_libraries(TinyGamesSDLUI
        PRIVATE
        TinyGamesDice
        TinyGamesShifumi
        SDL3::SDL3
)