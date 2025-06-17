set(TARGET_NAME tinyGames_Dice)

add_library(${TARGET_NAME} STATIC)

target_sources(${TARGET_NAME} PRIVATE
        Dice.cpp
        Dice.h
)

add_subdirectory(test)