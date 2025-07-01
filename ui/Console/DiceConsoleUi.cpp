//
// Created by walcz on 01/07/2025.
//

#include "DiceConsoleUi.h"
#include "../../lib/Dice/Dice.h"
#include <iostream>
#include <limits>

void DiceConsoleUi::run() {
    Dice dice(6); // Default to a 6-faced dice
    bool running = true;

    std::cout << "==== Welcome to Dice roll! ===" << std::endl;

    while (running)
    {
        int menuChoice;

        std::cout << "Dice initialized with " << dice.getNumberOfFaces() << " faces." << std::endl;

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
        switch(menuChoice)
        {
            case 1: {
                int result;
                if (dice.roll(result) == 0) {
                    std::cout << "You rolled a " << result << "!" << "\n" << std::endl;
                    std::cout << "Press Enter to continue...";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.get();
                } else {
                    std::cerr << "Failed to roll the dice." << std::endl;
                }
                break;
            }
            case 2: {
                int numberOfFaces;
                std::cout << "Enter the number of faces for the dice: ";
                std::cin >> numberOfFaces;
                if (numberOfFaces < 1) {
                    std::cerr << "Invalid number of faces. Setting to 6." << std::endl;
                    numberOfFaces = 6;
                }
                dice.setDieFaces(numberOfFaces);
                std::cout << "Press Enter to continue...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
                break;
            }
            case 3:
                running = false;
                break;
            case 4:
                exit(0);
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4." << std::endl;
                break;
        }
    }
}