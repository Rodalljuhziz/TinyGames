//
// Created by walcz on 17/06/2025.
//

#ifndef SHIFUMI_H
#define SHIFUMI_H

#include <iostream>

enum class ShifumiChoice {
    Rock,
    Paper,
    Scissors
};


class Shifumi {
public:
    Shifumi();
    ShifumiChoice intToShifumiChoice(int choice);
    int getRoundNumber() const;
    int setRoundNumber(int numberOfRounds);
    std::string isWinner(ShifumiChoice playerChoice, int &isWon);
    int createPlayer(std::string &playerName);
    int selectPlayer(std::string &playerName);

private:
    ShifumiChoice generateComputerChoice();
    int m_numberOfRounds = 1;
};



#endif //SHIFUMI_H
