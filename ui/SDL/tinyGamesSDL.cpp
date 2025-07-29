//
// Created by walcz on 26/07/2025.
//

#include "tinyGamesSDL.h"
#include <glog/logging.h>

#include "../../app/TinyGamesLauncher.h"

tinyGamesSDL::tinyGamesSDL(TinyGamesLauncher* launcher) : m_launcher(launcher)
{
}

void tinyGamesSDL::menu()
{

}

void tinyGamesSDL::runDice()
{

}

void tinyGamesSDL::runShifumi()
{

}

void tinyGamesSDL::switchBackend()
{
    bool running = true;
    while (running)
    {
        std::cout << "=== Choose a backend ===\n";
        std::cout << "1. Console\n";
        std::cout << "2. Qt\n";
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
            m_launcher->requestBackendSwitch(Backend::Console);
            break;
        case 2:
            m_launcher->requestBackendSwitch(Backend::Qt);
            break;
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

void tinyGamesSDL::exit()
{

}

void tinyGamesSDL::playDiceButton()
{

}

void tinyGamesSDL::playShifumiButton()
{

}

void tinyGamesSDL::switchUiBackendButton()
{

}

void tinyGamesSDL::quitButton()
{

}

void tinyGamesSDL::switchConsole()
{

}
