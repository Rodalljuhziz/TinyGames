//
// Created by walcz on 17/06/2025.
//

#ifndef SHIFUMIUTILS_H
#define SHIFUMIUTILS_H

#include "Shifumi.h"

inline const char* toString(ShifumiChoice choice) {
    switch (choice) {
    case ShifumiChoice::Rock:     return "Rock";
    case ShifumiChoice::Paper:    return "Paper";
    case ShifumiChoice::Scissors: return "Scissors";
    default:                      return "Unknown";
    }
}

#endif //SHIFUMIUTILS_H
