//
// Created by walcz on 17/06/2025.
//

#include "Shifumi.h"
#include "ShifumiUtils.h"
#include <random>
#include <iostream>
#include <limits>

Shifumi::Shifumi()
{

}

void Shifumi::shifumiMenu()
{
    bool running = true;

    std::cout << "Welcome to the Shifumi game!" << std::endl;

    while (running)
    {
        int menuChoice;
        if(m_numberOfRounds == 1)
        {
            std::cout << "1. Set number of rounds (by default 1 round)" << std::endl;
        } else
        {
            std::cout << "1. Set number of rounds (current: " << m_numberOfRounds << ")" << std::endl;
        }
        std::cout << "2. Play Shifumi" << std::endl;
        std::cout << "3. Return to main menu" << std::endl;
        std::cout << "4. Quit the application" << std::endl;
        std::cout << "Please enter your choice (1-4): ";
        std::cin >> menuChoice;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 3." << std::endl;
            continue;
        }

        if (menuChoice == 3) {
            running = false;
        } else if (menuChoice == 4) {
            exit(0);
        } else {
            playerChoice(menuChoice);
        }
    }

}

void Shifumi::playerChoice(const int choice)
{
    int playerChoice, isWon;
    switch (choice)
    {
        case 1:
        {
            int numberOfRounds;
            std::cout << "Enter the number of rounds you want to play: ";
            std::cin >> numberOfRounds;
            if (setRoundNumber(numberOfRounds) != 0)
            {
                std::cerr << "Invalid number of rounds. Setting to 1." << std::endl;
            } else
            {
                std::cout << "Number of rounds set to " << m_numberOfRounds << " successfully." << std::endl;
            }
            break;
        }

    case 2:
    {
        for (int round = 1; round <= m_numberOfRounds; ++round)
        {
            std::cout << "Choose Rock, Paper, or Scissors:" << std::endl;
            std::cout << "1. Rock" << std::endl;
            std::cout << "2. Paper" << std::endl;
            std::cout << "3. Scissors" << std::endl;
            std::cin >> playerChoice;
            if (playerChoice < 1 || playerChoice > 3)
            {
                std::cout << "Invalid choice. Please enter a number between 1 and 3." << std::endl;
                --round;
                return;
            }
            const ShifumiChoice playerChoiceEnum = intToShifumiChoice(playerChoice);
            isWinner(playerChoiceEnum, isWon);
        }
        break;
    }

    default:
        std::cout <<  "Invalid choice. Please enter a number between 1 and 4." << std::endl;
        break;
    }
}

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