//
// Created by walcz on 27/07/2025.
//

#include "tinyGamesConsole.h"
#include "../../lib/Dice/Dice.h"
#include "../lib/Shifumi/Shifumi.h"
#include <iostream>
#include <limits>
#include <thread>

#include "../../app/TinyGamesLauncher.h"

tinyGamesConsole::tinyGamesConsole(TinyGamesLauncher* launcher)
    : m_launcher(launcher)
{
}

void tinyGamesConsole::menu()
{
    //TODO: Implement the logic to display the main menu
    bool running = true;
    while (running)
    {
        std::cout << "=== TinyGames Menu ===\n";
        std::cout << "1. Play Dice\n";
        std::cout << "2. Play Shifumi\n";
        std::cout << "3. Switch UI Backend\n";
        std::cout << "4. Quit\n";
        std::cout << "Choice: ";

        int choice;
        std::cin >> choice;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input.\n";
            continue;
        }

        switch (choice) {
        case 1:
            runDice();
            break;
        case 2:
            runShifumi();
            break;
        case 3:
            switchBackend();
            running = false;
            break;
        case 4:
            running = false;
            break;
        default:
            std::cout << "Invalid choice.\n";
        }
    }

    std::cout << "Thank you for playing!";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    std::cout << "\n";
}

void tinyGamesConsole::runDice()
{
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
                exit();
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4." << std::endl;
                break;
        }
    }
}

void tinyGamesConsole::runShifumi()
{
    Shifumi shifumi;
    bool running = true;

    std::cout << "==== Welcome to the Shifumi game! ====" << std::endl;

    while (running) {
        int menuChoice;
        const int rounds = shifumi.getRoundNumber();

        std::cout << "1. Set number of rounds (current: " << rounds << ")\n";
        std::cout << "2. Play Shifumi\n";
        std::cout << "3. Return to main menu\n";
        std::cout << "4. Quit the application\n";
        std::cout << "Please enter your choice (1-4): ";

        std::cin >> menuChoice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        switch (menuChoice) {
            case 1: {
                int number;
                std::cout << "Enter number of rounds: ";
                std::cin >> number;
                if (std::cin.fail() || shifumi.setRoundNumber(number) != 0) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cerr << "Invalid number. Defaulting to 1.\n";
                }
                break;
            }
            case 2: {
                for (int i = 1; i <= shifumi.getRoundNumber(); ++i) {
                    int input;
                    std::cout << "Round " << i << ": Choose (1) Rock, (2) Paper, (3) Scissors: ";
                    std::cin >> input;

                    if (std::cin.fail() || input < 1 || input > 3) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid choice.\n";
                        --i;
                        continue;
                    }

                    const ShifumiChoice player = Shifumi::intToShifumiChoice(input);
                    int result;
                    std::string outcome = shifumi.isWinner(player, result);
                    std::cout << outcome << "\n";

                    std::cout << "Press Enter to continue...";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.get();
                }
                break;
            }
            case 3:
                running = false;
                break;
            case 4:
            {
                std::string confirmation;
                std::cout << "Are you sure you want to quit? (y/n)\n";
                std::cin >> confirmation;
                if (confirmation == "y" || confirmation == "Y" || confirmation == "yes" || confirmation == "YES") {
                    exit(); // Quitte l’appli
                } else {
                    std::cout << "Returning to the Shifumi menu.\n";
                    // Ne pas rappeler `menu()` ici — on est déjà dans une boucle
                    continue; // ou rien du tout
                }
            }
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }
}

void tinyGamesConsole::switchBackend()
{
    bool running = true;
    while (running)
    {
        std::cout << "=== Choose a backend ===\n";
        std::cout << "1. Qt\n";
        std::cout << "2. SDL\n";
        std::cout << "3. Return to main menu\n";
        std::cout << "4. Quit\n";
        std::cout << "Choice: ";

        int choice;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input.\n";
            continue;
        }

        switch (choice)
        {
            case 1:
                m_launcher->requestBackendSwitch(Backend::Qt);
                return;
            case 2:
                m_launcher->requestBackendSwitch(Backend::SDL);
                return;
            case 3:
                running = false;
                break;
            case 4:
                exit();
                break;
            default:
                std::cout << "Invalid choice.\n";
                return;
        }
    }
}

void tinyGamesConsole::exit()
{
    //TODO: Implement the logic to exit the console UI
    // This method can be used to exit the console UI
    std::cout << "Exiting TinyGames Console. Goodbye!\n";
    std::exit(0);
}

/*
    ::DICE MENU TO CHANGE:
    Noting was made for now
 */

/*
    ::DICE RUN TO CHANGE::
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
 */

/*
    ::SHIFUMI MENU TO CHANGE::
     Shifumi shifumi;
    bool running = true;

    std::cout << "==== Welcome to the Shifumi game! ====" << std::endl;

    while (running) {
        int menuChoice;
        int rounds = shifumi.getRoundNumber();

        std::cout << "1. Set number of rounds (current: " << rounds << ")\n";
        std::cout << "2. Play Shifumi\n";
        std::cout << "3. Return to main menu\n";
        std::cout << "4. Quit the application\n";
        std::cout << "Please enter your choice (1-4): ";

        std::cin >> menuChoice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        switch (menuChoice) {
            case 1: {
                int number;
                std::cout << "Enter number of rounds: ";
                std::cin >> number;
                if (std::cin.fail() || shifumi.setRoundNumber(number) != 0) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cerr << "Invalid number. Defaulting to 1.\n";
                }
                break;
            }
            case 2: {
                for (int i = 1; i <= shifumi.getRoundNumber(); ++i) {
                    int input;
                    std::cout << "Round " << i << ": Choose (1) Rock, (2) Paper, (3) Scissors: ";
                    std::cin >> input;

                    if (std::cin.fail() || input < 1 || input > 3) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid choice.\n";
                        --i;
                        continue;
                    }

                    const ShifumiChoice player = shifumi.intToShifumiChoice(input);
                    int result;
                    std::string outcome = shifumi.isWinner(player, result);
                    std::cout << outcome << "\n";

                    std::cout << "Press Enter to continue...";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.get();
                }
                break;
            }
            case 3:
                running = false;
                break;
            case 4:
                std::cout << "Exiting the application. Goodbye!\n";
                exit(0);
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

 */

/*
    ::SHIFUMI RUN TO CHANGE::
    Shifumi shifumi;
    bool running = true;

    std::cout << "==== Welcome to the Shifumi game! ====" << std::endl;

    while (running) {
        int menuChoice;
        int rounds = shifumi.getRoundNumber();

        std::cout << "1. Set number of rounds (current: " << rounds << ")\n";
        std::cout << "2. Play Shifumi\n";
        std::cout << "3. Return to main menu\n";
        std::cout << "4. Quit the application\n";
        std::cout << "Please enter your choice (1-4): ";

        std::cin >> menuChoice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        switch (menuChoice) {
            case 1: {
                int number;
                std::cout << "Enter number of rounds: ";
                std::cin >> number;
                if (std::cin.fail() || shifumi.setRoundNumber(number) != 0) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cerr << "Invalid number. Defaulting to 1.\n";
                }
                break;
            }
            case 2: {
                for (int i = 1; i <= shifumi.getRoundNumber(); ++i) {
                    int input;
                    std::cout << "Round " << i << ": Choose (1) Rock, (2) Paper, (3) Scissors: ";
                    std::cin >> input;

                    if (std::cin.fail() || input < 1 || input > 3) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid choice.\n";
                        --i;
                        continue;
                    }

                    const ShifumiChoice player = shifumi.intToShifumiChoice(input);
                    int result;
                    std::string outcome = shifumi.isWinner(player, result);
                    std::cout << outcome << "\n";

                    std::cout << "Press Enter to continue...";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.get();
                }
                break;
            }
            case 3:
                running = false;
                break;
            case 4:
                std::cout << "Exiting the application. Goodbye!\n";
                exit(0);
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

 */