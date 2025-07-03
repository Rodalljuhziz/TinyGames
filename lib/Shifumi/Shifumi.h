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
    static ShifumiChoice intToShifumiChoice(int choice);
    int getRoundNumber() const;
    int setRoundNumber(int numberOfRounds);
    std::string isWinner(ShifumiChoice playerChoice, int &isWon);
    int createPlayer(std::string &playerName) const;
    int deletePlayer(std::string &playerName) const;
    int selectPlayer(std::string &playerName);
    int setFilepathPlayerJson(const std::string &filepath);
    std::string getFilepathPlayerJson();

private:
    ShifumiChoice generateComputerChoice();
    int m_numberOfRounds = 1;
    std::string m_filepathPlayerJson, m_playerSelected;
};

#endif //SHIFUMI_H
