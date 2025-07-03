add_executable( testDice
        test_dice.cpp
)

target_link_libraries( testDice PUBLIC
        GTest::gtest_main
        GTest::gtest
        TinyGamesDice
)

add_test( NAME testDice
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND testDice
)