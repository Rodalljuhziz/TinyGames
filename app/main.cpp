//
// Created by walcz on 17/06/2025.
//

#include <iostream>
#include <QApplication>

#include "TinyGamesLauncher.h"
#include <glog/logging.h>
//include <SDL3/SDL.h>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    std::cout << "Welcome to TinyGames Launcher!\n";
    std::cout << "Current backend: Console\n";
    google::InitGoogleLogging(argv[0]);
    FLAGS_logtostderr = true;
    TinyGamesLauncher launcher;
    launcher.run();

    return app.exec();
}