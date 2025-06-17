//
// Created by walcz on 17/06/2025.
//

#include "Shifumi.h"
#include "ShifumiUtils.h"
#include <random>
#include <iostream>

Shifumi::Shifumi()
{
}

int Shifumi::setRoundNumber(const int numberOfRounds)
{
    m_numberOfRounds = numberOfRounds;
    if(m_numberOfRounds < 1)
    {
        m_numberOfRounds = 1;
        return 0x0FF10001;
    }
    return 0;
}

int Shifumi::isWinner(ShifumiChoice playerChoice, int &isWon)
{
    ShifumiChoice computerChoice = generateComputerChoice();
    std::string winner;
    isWon = 0;

    std::cout << "Player chose: " << toString(playerChoice) << "\n";
    std::cout << "Computer chose: " << toString(computerChoice) << "\n";

    if (playerChoice == computerChoice)
    {
        isWon = 3;
        winner = "It's a tie, player and computer choose";
    }
    else if (
        (playerChoice == ShifumiChoice::Rock     && computerChoice == ShifumiChoice::Scissors) ||
        (playerChoice == ShifumiChoice::Paper    && computerChoice == ShifumiChoice::Rock)     ||
        (playerChoice == ShifumiChoice::Scissors && computerChoice == ShifumiChoice::Paper))
    {
       isWon = 1;
        winner = "Player wins";
    }

    else
    {
        isWon = 0;
        winner = "Computer wins";
    }


    std::cout << winner << " with " << toString(playerChoice) << " against " << toString(computerChoice) << " (computer)" << "\n";
    return 0;
}

ShifumiChoice Shifumi::generateComputerChoice()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, 2);
    return static_cast<ShifumiChoice>(dist(gen));
}