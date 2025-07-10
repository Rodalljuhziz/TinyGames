//
// Created by walcz on 17/06/2025.
//

#include <iostream>

#include "TinyGamesLauncher.h"
#include <glog/logging.h>
//include <SDL3/SDL.h>

int main(int argc, char *argv[]) {

    google::InitGoogleLogging(argv[0]);
    FLAGS_logtostderr = true;
    TinyGamesLauncher launcher;
    launcher.run();

    return 0;
}