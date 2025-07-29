//
// Created by walcz on 26/07/2025.
//

#ifndef TINYGAMESSDL_H
#define TINYGAMESSDL_H

#include "../IGameUi.h"

enum class Backend;
class TinyGamesLauncher;

class tinyGamesSDL : public IGameUi {
    public:
        explicit tinyGamesSDL(TinyGamesLauncher* launcher);
        ~tinyGamesSDL() override = default;

        void menu() override;
        void runDice() override;
        void runShifumi() override;
        void switchBackend() override;
        void exit() override;
        // Add other methods as needed for the SDL UI

        void playDiceButton();
        void playShifumiButton();
        void switchUiBackendButton();
        void quitButton();
        void switchConsole();
private:
    TinyGamesLauncher* m_launcher;
};



#endif //TINYGAMESSDL_H
