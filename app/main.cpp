//
// Created by walcz on 17/06/2025.
//

#include <iostream>
#include "../lib/Dice/Dice.h"
#include "../lib/Shifumi/Shifumi.h"
#include <thread>
#include <chrono>
#include <limits>

void tinyGameMenu()
{
    std::cout << "Welcome to the Tiny Game Menu!" << std::endl;
    std::cout << "1. Play Dice" << std::endl;
    std::cout << "2. Play Shifumi" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Please enter your choice (1-3): ";
}

int main(int argc, char *argv[])
{
    Shifumi shifumi;
    Dice dice;
    int choice;
    bool running = true;

    while (running)
    {
        tinyGameMenu();
        std::cin >> choice;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 3." << std::endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            dice.diceMenu();
            break;
        case 2:
            shifumi.shifumiMenu();
            break;
        case 3:
            std::cout << "Exiting the game. Goodbye!" << std::endl;
            running = false;
            break;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 3." << std::endl;
            break; // ici on ne fait pas "return 1", on continue la boucle
        }
    }

    std::cout << "Thank you for playing!" << std::endl;
    std::cout << "Exiting the application";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "." << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "." << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "." << std::endl;
    return 0;
}
