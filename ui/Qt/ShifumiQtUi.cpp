//
// Created by walcz on 10/07/2025.
//

#include "ShifumiQtUi.h"
#include "ui_tinyGamesQt.h"

ShifumiQtUi::ShifumiQtUi(QWidget* parent)
    : QMainWindow(parent), m_ui(new Ui::ShifumiQtUi)
{
    m_ui->setupUi(this);
}

ShifumiQtUi::~ShifumiQtUi()
{
    delete m_ui;
}

void ShifumiQtUi::run()
{
    this->show();
}

void ShifumiQtUi::on_action_playDiceButton_triggered()
{
}

void ShifumiQtUi::on_action_playShifumiButton_triggered()
{
}

void ShifumiQtUi::on_action_switchUiBackendButton_triggered()
{
}

void ShifumiQtUi::on_action_quitButton_triggered()
{
}

//void ShifumiQtUi::run() {

    /*
    Shifumi shifumi;
    bool running = true;

    std::cout << "==== Welcome to the Shifumi game! ====" << std::endl;

    while (running) {
        int menuChoice;
        int rounds = shifumi.getRoundNumber();

        std::cout << "1. Set number of rounds (current: " << rounds << ")\n";
        std::cout << "2. Play Shifumi\n";
        std::cout << "3. Return to main menu\n";
        std::cout << "4. Quit the application\n";
        std::cout << "Please enter your choice (1-4): ";

        std::cin >> menuChoice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        switch (menuChoice) {
            case 1: {
                int number;
                std::cout << "Enter number of rounds: ";
                std::cin >> number;
                if (std::cin.fail() || shifumi.setRoundNumber(number) != 0) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cerr << "Invalid number. Defaulting to 1.\n";
                }
                break;
            }
            case 2: {
                for (int i = 1; i <= shifumi.getRoundNumber(); ++i) {
                    int input;
                    std::cout << "Round " << i << ": Choose (1) Rock, (2) Paper, (3) Scissors: ";
                    std::cin >> input;

                    if (std::cin.fail() || input < 1 || input > 3) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid choice.\n";
                        --i;
                        continue;
                    }

                    const ShifumiChoice player = shifumi.intToShifumiChoice(input);
                    int result;
                    std::string outcome = shifumi.isWinner(player, result);
                    std::cout << outcome << "\n";

                    std::cout << "Press Enter to continue...";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.get();
                }
                break;
            }
            case 3:
                running = false;
                break;
            case 4:
                std::cout << "Exiting the application. Goodbye!\n";
                exit(0);
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }
    */
//}
