add_library(TinyGamesSDLUI
        tinyGamesSDL.cpp
        tinyGamesSDL.h
)

target_include_directories(TinyGamesSDLUI
        PUBLIC
)

include_directories(${CMAKE_SOURCE_DIR}/ui)

target_link_libraries(TinyGamesSDLUI
        PRIVATE
        TinyGamesDice
        TinyGamesShifumi
        SDL3::SDL3
        glog::glog
)