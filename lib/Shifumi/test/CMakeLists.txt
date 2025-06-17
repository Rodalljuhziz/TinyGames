add_executable( testShifumi
        test_shifumi.cpp
)

target_link_libraries( testShifumi PUBLIC
        GTest::gtest_main
        GTest::gtest
        tinyGames_Shifumi
)

add_test( NAME testShifumi
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND testShifumi
)