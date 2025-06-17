//
// Created by walcz on 17/06/2025.
//

#include <gtest/gtest.h>
#include "../Dice.h"

TEST(DiceTest , setDiceFaces)
{
    Dice dice;
    const int error = dice.setDieFaces(6);
    EXPECT_EQ(error, 0);
}

TEST(DiceTest, RollsBetweenOneAndSix) {
    Dice dice;
    int error = dice.setDieFaces(6);
    EXPECT_EQ(error, 0);
    if(error == 0)
    {
        int result = 0;
        error = dice.roll(result);
        EXPECT_EQ(error, 0);
        if(error == 0)
        {
            EXPECT_GE(result, 1);
            EXPECT_LE(result, 6);
        }
    }
}