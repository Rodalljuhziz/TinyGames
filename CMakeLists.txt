cmake_minimum_required(VERSION 3.10)
project(dice_roller
        VERSION 1.0.0
        DESCRIPTION "Some tiny games to play"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

include(cmake/googletest.cmake)

include_directories(${CMAKE_SOURCE_DIR}/3rdParty)

set(WITH_GFLAGS OFF CACHE BOOL "Disable gflags usage in glog" FORCE)
add_subdirectory(3rdParty/glog)

add_subdirectory(lib)
add_subdirectory(ui/Console)
# add_subdirectory(ui/SDL)
# add_subdirectory(ui/Qt)
add_subdirectory(app)
