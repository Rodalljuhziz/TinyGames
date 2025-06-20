//
// Created by walcz on 17/06/2025.
//

#ifndef SHIFUMI_H
#define SHIFUMI_H


enum class ShifumiChoice {
    Rock,
    Paper,
    Scissors
};


class Shifumi {
public:
    Shifumi();
    void shifumiMenu();
    void playerChoice(int choice);
    ShifumiChoice intToShifumiChoice(int choice);
    int setRoundNumber(int numberOfRounds);
    int isWinner(ShifumiChoice playerChoice, int &isWon);

private:
    ShifumiChoice generateComputerChoice();

    int m_numberOfRounds = 1;
};



#endif //SHIFUMI_H
