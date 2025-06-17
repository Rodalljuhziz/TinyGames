set(TARGET_NAME tinyGames_Shifumi)

add_library(${TARGET_NAME} STATIC)

target_sources(${TARGET_NAME} PRIVATE
        Shifumi.cpp
        Shifumi.h
)

add_subdirectory(test)