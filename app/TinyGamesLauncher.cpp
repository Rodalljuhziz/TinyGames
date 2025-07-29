//
// Created by walcz on 01/07/2025.
//

#include "TinyGamesLauncher.h"
#include <QApplication>

#include "../ui/Console/tinyGamesConsole.h"
#include "../ui/Qt/tinyGamesQt.h"
#include "../ui/SDL/tinyGamesSDL.h"

TinyGamesLauncher::TinyGamesLauncher()
{
    m_currentBackend = Backend::Console; // Default backend is Console
}

void TinyGamesLauncher::run()
{
    bool running = true;

    while (running)
    {
        switch (m_currentBackend)
        {
            case Backend::Console: {
                tinyGamesConsole consoleUi(this);
                consoleUi.menu();
                break;
            }
            case Backend::Qt: {
                if (!m_qtUi)
                    m_qtUi = new tinyGamesQt(nullptr, this);

                m_qtUi->menu();
                running = false;
                break;
            }
            case Backend::SDL: {
                tinyGamesSDL sdlUi(this);
                sdlUi.menu();
                break;
            }
            case Backend::Error:
                running = false;
                break;
        }
    }
}

void TinyGamesLauncher::requestBackendSwitch(Backend newBackend)
{
    if (newBackend != m_currentBackend) {
        m_currentBackend = newBackend;
    }
}

Backend TinyGamesLauncher::getCurrentBackend() const
{
    return m_currentBackend;
}

std::string TinyGamesLauncher::switchBackend(const Backend newBackend) const
{
    std::string message;
    if(newBackend == m_currentBackend)
    {
        message = "Backend Already in use";
    }
    else if(newBackend == Backend::Console)
    {
        message = "Switch to console ui";
    }
    else if(newBackend == Backend::Qt)
    {
        message = "Switch to Qt ui";
    }
    else if(newBackend == Backend::SDL)
    {
        message = "Switch to SDL ui";
    }

    return message;
}

/*
Backend TinyGamesLauncher::choiceBackend()
{

    int choice;

    if(m_currentBackend == Backend::Console)
    {
        std::cout << "Choose a backend:\n";
        std::cout << "1. Console\n";
        std::cout << "2. SDL\n";
        std::cout << "3. Qt\n";
        std::cin >> choice;
    }
    else if(m_currentBackend == Backend::SDL)
    {

    }
    else if(m_currentBackend == Backend::Qt)
    {

        ShifumiQtUi shifumiQtUi;
        shifumiQtUi.switchUiBackend();

    }
    switch(choice)
    {
        case 1:
            m_currentBackend = Backend::Console;
            break;
        case 2:
            m_currentBackend = Backend::SDL;
            break;
        case 3:
            m_currentBackend = Backend::Qt;
            break;
    default:
        std::cout << "Invalid choice, defaulting to Console backend.\n";
    }

    return m_currentBackend;
}
*/