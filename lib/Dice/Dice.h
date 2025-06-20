//
// Created by walcz on 17/06/2025.
//

#ifndef DICE_H
#define DICE_H

enum class DiceError {
    Success = 0,
    InvalidNumberOfFaces = 0x0FF10000,
    RollFailed = 0x0FF10001,
    UnknownError = 0x0FF1FFFF
};

class Dice {

public:
    Dice();
    void diceMenu();
    void playerChoice(int choice);
    int setDieFaces(int numberOfFaces);
    int roll(int &result) const;

private:
    int m_numberOfFaces = 6;
};



#endif //DICE_H
