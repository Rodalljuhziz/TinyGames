//
// Created by walcz on 17/06/2025.
//

#include "Shifumi.h"
#include "ShifumiUtils.h"
#include <random>
#include <fstream>
//#include <nlohmann/json.hpp>

//using json = nlohmann::json;

Shifumi::Shifumi()
= default;

ShifumiChoice Shifumi::intToShifumiChoice(const int choice)
{
    switch (choice)
    {
        case 1: return ShifumiChoice::Rock;
        case 2: return ShifumiChoice::Paper;
        case 3: return ShifumiChoice::Scissors;
        default: return ShifumiChoice::Rock; // Default to Rock if invalid choice
    }
}

int Shifumi::getRoundNumber() const
{
    return m_numberOfRounds;
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

std::string Shifumi::isWinner(ShifumiChoice playerChoice, int &isWon)
{
    ShifumiChoice computerChoice = generateComputerChoice();
    std::string winner;
    isWon = 0;

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

    return std::string("Player: ") + toString(playerChoice) + ", Computer: " + toString(computerChoice) + " → " + winner;
}
/*
int Shifumi::createPlayer(std::string& playerName)
{
    std::vector< std::string> playersList;
    json playerJSON;

    std::ifstream file("players.json");
    if(!file)
    {
        std::cerr << "can't open the file players.json";
        return 1;
    }

    if(file.contains("players") && file["players"].isArray)
    {

    }

    for(std::vector playerList : name)
    {
        if(playerName == name)
        {
           std::cout << "Player alreay exist!" << std::endl;
        }
    }
    else if(!playerName.empty())
    {

    }
}

int Shifumi::selectPlayer(std::string& playerName)
{
    std::vector< std::string> playersList;
    json playerJSON;

    std::ifstream file("players.json");
    if(!file)
    {
        std::cerr << "can't open the file players.json";
        return 1;
    }

    if(file.contains("players") && file["players"].isArray)
    {

        return 0;
    }else
    {
        return 1;
    }
}
*/
ShifumiChoice Shifumi::generateComputerChoice()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, 2);
    return static_cast<ShifumiChoice>(dist(gen));
}
