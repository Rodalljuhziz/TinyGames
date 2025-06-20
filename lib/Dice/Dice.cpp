//
// Created by walcz on 17/06/2025.
//

#include "Dice.h"
#include <random>
#include <iostream>
#include <limits>

Dice::Dice()
{
}


void Dice::diceMenu()
{
    bool running = true;
    std::string yesNoInput;

    std::cout << "==== Welcome to Dice roll! ===" << std::endl;

    while (running)
    {
        int menuChoice;;

        std::cout << "Dice initialized with " << m_numberOfFaces << " faces." << std::endl;

        std::cout << "1. Let's roll the dice!" << std::endl;
        std::cout << "2. Change numbers of faces" << std::endl;
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

void Dice::playerChoice(const int choice)
{
    int numberOfFaces;
    switch(choice)
    {
        case 1:
        {
            int result;
            std::string yesNoInput;
            if (roll(result) == 0)
            {
                std::cout << "You rolled a " << result << " on a dice with " << m_numberOfFaces << " faces." << std::endl;
                std::cout << "Do you want to roll again? (yes/no): ";
                std::cin >> yesNoInput;
                if(yesNoInput == "yes" || yesNoInput == "y" || yesNoInput =="Y" || yesNoInput == "Yes")
                {
                    playerChoice(1);
                }
                else if(yesNoInput == "no" || yesNoInput == "n" || yesNoInput =="N" || yesNoInput == "No")
                {
                    std::cout << "Exiting the dice roll." << std::endl;
                }
                else
                {
                    std::cerr << "Invalid input. Exiting the dice roll." << std::endl;
                }
            }
            else
            {
                std::cerr << "Failed to roll the dice." << std::endl;
            }
            break;
        }

        case 2:
        {
            std::cout << "Enter the number of faces for the dice: ";
            std::cin >> numberOfFaces;
            if(numberOfFaces < 1)
            {
                std::cerr << "Invalid number of faces. Setting to 6." << std::endl;
                numberOfFaces = 6;
            }
            m_numberOfFaces = numberOfFaces;
            break;
        }
        default:
            std::cout <<  "Invalid choice. Please enter a number between 1 and 4." << std::endl;
            break;
    }
}

int Dice::setDieFaces(const int numberOfFaces)
{
    m_numberOfFaces = numberOfFaces;
    if(m_numberOfFaces < 0)
    {
        m_numberOfFaces = 6;
        return 0x0FF10001;
    }
    return 0;
}

int Dice::roll(int &result) const
{
    if(m_numberOfFaces <= 0)
    {
        return 0x0FF10000;
    }
    static std::random_device random;
    static std::mt19937 generator(random());
    std::uniform_int_distribution<> dis(1, m_numberOfFaces);
    result = dis(generator); // Generate a random number between 1 and m_numberOfFaces
    return 0;
}