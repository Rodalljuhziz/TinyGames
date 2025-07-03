//
// Created by walcz on 17/06/2025.
//

#include "TinyGamesLauncher.h"
#include <glog/logging.h>

int main(int argc, char *argv[]) {
    google::InitGoogleLogging(argv[0]);
    FLAGS_logtostderr = true;
    TinyGamesLauncher launcher;
    launcher.run();
    return 0;
}