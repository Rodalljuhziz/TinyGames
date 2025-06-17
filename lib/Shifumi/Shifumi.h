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
    int setRoundNumber(int numberOfRounds);
    static int isWinner(ShifumiChoice playerChoice, int &isWon);

private:
    static ShifumiChoice generateComputerChoice();

    int m_numberOfRounds = 1;
};



#endif //SHIFUMI_H
