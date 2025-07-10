cmake_minimum_required(VERSION 3.10)
project(dice_roller
        VERSION 1.0.0
        DESCRIPTION "Some tiny games to play"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Qt6_DIR "C:/Qt/6.9.1/mingw_64/lib/cmake/Qt6")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

enable_testing()

include(cmake/googletest.cmake)

include_directories(${CMAKE_SOURCE_DIR}/3rdParty)

set(WITH_GFLAGS OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

set(SDL_TEST OFF CACHE BOOL "" FORCE)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)

add_subdirectory(3rdParty/SDL)
add_subdirectory(3rdParty/glog)
add_subdirectory(lib)
add_subdirectory(ui/Console)
add_subdirectory(ui/SDL)
add_subdirectory(ui/Qt)
add_subdirectory(app)
