//
// Created by walcz on 01/07/2025.
//

#ifndef TINYGAMESLAUNCHER_H
#define TINYGAMESLAUNCHER_H

class tinyGamesQt;
#include <iostream>

enum class Backend {
    Console,
    SDL,
    Qt,
    Error
};

class TinyGamesLauncher {
    public:
        TinyGamesLauncher();
        void run();

        void requestBackendSwitch(Backend newBackend);
        Backend getCurrentBackend() const;
    private:
        Backend m_currentBackend;
        std::string switchBackend(Backend newBackend) const;
        tinyGamesQt* m_qtUi = nullptr;
        //Backend choiceBackend();

};

#endif //TINYGAMESLAUNCHER_H
