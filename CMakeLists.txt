cmake_minimum_required(VERSION 3.10)
project(dice_roller
        VERSION 1.0.0
        DESCRIPTION "Some tiny games to play"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

include(cmake/googletest.cmake)

add_subdirectory(lib)
add_subdirectory(app)