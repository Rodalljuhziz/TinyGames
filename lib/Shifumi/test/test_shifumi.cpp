//
// Created by walcz on 17/06/2025.
//

#include <gtest/gtest.h>
#include "../Shifumi.h"

TEST(ShifumiTest , setNumberOfRounds)
{
    Shifumi shifumi;
    const int error = shifumi.setRoundNumber(3);
    EXPECT_EQ(error, 0);
}

TEST(ShifumiTest, whoWins)
{
    int isWon;
    const int error = Shifumi::isWinner(ShifumiChoice::Rock, isWon);
    EXPECT_EQ(error, 0);
    EXPECT_GE(isWon, 1);
    EXPECT_LE(isWon, 3);

}