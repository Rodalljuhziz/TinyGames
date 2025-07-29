//
// Created by walcz on 27/07/2025.
//

#ifndef TINYGAMESCONSOLE_H
#define TINYGAMESCONSOLE_H

#include "../IGameUi.h"

enum class Backend;
class TinyGamesLauncher;

class tinyGamesConsole : public IGameUi {
    public:
        explicit tinyGamesConsole(TinyGamesLauncher* launcher);

        void menu() override;
        void runDice() override;
        void runShifumi() override;
        void switchBackend() override;
        void exit() override;

private:
    TinyGamesLauncher* m_launcher;
};

#endif //TINYGAMESCONSOLE_H
