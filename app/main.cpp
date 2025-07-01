//
// Created by walcz on 17/06/2025.
//

#include "TinyGamesLauncher.h"

int main() {
    TinyGamesLauncher launcher;
    launcher.run();
    return 0;
}
/*
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
    std::cout << "Constructing Shifumi..." << std::endl;
    Shifumi shifumi;
    std::cout << "Shifumi constructed." << std::endl;

    std::cout << "Constructing Dice..." << std::endl;
    Dice dice;
    std::cout << "Dice constructed." << std::endl;
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
        case 4:
           std::cout << "Switch to Sdl" << std::endl;
            break;
        case 5:
            std::cout << "Switch to Qt" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 3." << std::endl;
            break;
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
*/