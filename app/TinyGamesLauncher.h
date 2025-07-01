//
// Created by walcz on 01/07/2025.
//

#ifndef TINYGAMESLAUNCHER_H
#define TINYGAMESLAUNCHER_H

enum class Backend {
    Console,
    SDL,
    Qt
};

class TinyGamesLauncher {
    public:
        void run();

    private:
        Backend m_currentBackend = Backend::Console;
        void runConsole();
        void runSDL();
        void runQt();
        void switchBackend();
};

#endif //TINYGAMESLAUNCHER_H
