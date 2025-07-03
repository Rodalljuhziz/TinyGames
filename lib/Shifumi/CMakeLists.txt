add_library(TinyGamesShifumi
        Shifumi.cpp
        Shifumi.h
)

target_include_directories(TinyGamesShifumi
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/3rdParty
)

target_link_libraries(TinyGamesShifumi
        PUBLIC glog::glog
)

add_subdirectory(test)