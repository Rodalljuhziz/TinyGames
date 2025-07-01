//
// Created by walcz on 01/07/2025.
//

#include "TinyGamesLauncher.h"

#include "../ui/Console/DiceConsoleUi.h"
#include "../ui/Console/ShifumiConsoleUi.h"

#include <iostream>
#include <limits>
#include <thread>

void TinyGamesLauncher::run()
{
    bool running = true;
    while (running) {
        std::cout << "=== TinyGames Menu (" << (m_currentBackend == Backend::Console ? "Console" : m_currentBackend == Backend::SDL ? "SDL" : "Qt") << ") ===\n";
        std::cout << "1. Play Dice\n";
        std::cout << "2. Play Shifumi\n";
        std::cout << "3. Switch UI Backend\n";
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

        switch (choice) {
        case 1:
            if (m_currentBackend == Backend::Console) {
                DiceConsoleUi().run();
            } else {
                std::cout << "[TODO] Dice in this backend not implemented yet.\n";
            }
            break;
        case 2:
            if (m_currentBackend == Backend::Console) {
                ShifumiConsoleUi().run();
            } else {
                std::cout << "[TODO] Shifumi in this backend not implemented yet.\n";
            }
            break;
        case 3:
            switchBackend();
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

void TinyGamesLauncher::switchBackend() {
    if (m_currentBackend == Backend::Console)
        m_currentBackend = Backend::SDL;
    else if (m_currentBackend == Backend::SDL)
        m_currentBackend = Backend::Qt;
    else
        m_currentBackend = Backend::Console;

    std::cout << "Switched to ";
    if (m_currentBackend == Backend::Console)
        std::cout << "Console";
    else if (m_currentBackend == Backend::SDL)
        std::cout << "SDL";
    else
        std::cout << "Qt";
    std::cout << " backend.\n";
}