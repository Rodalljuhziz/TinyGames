//
// Created by walcz on 26/07/2025.
//

#include "tinyGamesQt.h"
#include "ui_tinyGamesQt.h"
#include "../../app/TinyGamesLauncher.h"
#include "../../lib/Shifumi/Shifumi.h"
#include "../../lib/Dice/Dice.h"
#include <QMessageBox>
#include <QCloseEvent>

tinyGamesQt::tinyGamesQt(QWidget* parent, TinyGamesLauncher* launcher)
    : QMainWindow(parent), m_ui(new Ui::tinyGamesVisualQtUi), m_launcher(launcher)
{
    m_ui->setupUi(this);
    m_ui->stackedWidgetMenu->setCurrentWidget(m_ui->menuPage);
}

tinyGamesQt::~tinyGamesQt()
{
    delete m_ui;
}

void tinyGamesQt::menu()
{
    isActive = true;
    std::cout << "azerty";
    this->show();
    //QApplication::exec();
}

void tinyGamesQt::runDice()
{

}

void tinyGamesQt::runShifumi()
{

}

void tinyGamesQt::switchBackend()
{
    bool running = true;
    while (running)
    {
        std::cout << "=== Choose a backend ===\n";
        std::cout << "1. Console\n";
        std::cout << "2. SDL\n";
        std::cout << "3. Return to main menu\n";
        std::cout << "4. Quit\n";
        std::cout << "Choice: ";

        int choice;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            m_launcher->requestBackendSwitch(Backend::Console);
            break;
        case 2:
            m_launcher->requestBackendSwitch(Backend::SDL);
            break;
        case 3:
            running = false;
            break;
        case 4:
            exit();
            break;
        default:
            std::cout << "Invalid choice.\n";
            return;
        }
    }
}

/*
void tinyGamesQt::switchUiBackend()
{
    m_ui->stackedWidgetMenu->setCurrentWidget(m_ui->switchUiPage);
}
*/

void tinyGamesQt::exit()
{
    this->close();
}

void tinyGamesQt::on_playDiceButton_clicked()
{
    //TODO: Implement the logic to play Dice game
    QMessageBox::information(this, "Dice Game", "runDice() a été appelé avec succès !");
}

void tinyGamesQt::on_playShifumiButton_clicked()
{
    //TODO: Implement the logic to play Shifumi game
}

void tinyGamesQt::on_switchUiBackendButton_clicked()
{
    m_ui->stackedWidgetMenu->setCurrentWidget(m_ui->switchUiPage);
}

void tinyGamesQt::on_quitButton_clicked()
{
    QApplication::quit();
}

void tinyGamesQt::on_switchConsole_clicked()
{
    // TODO: Implement the logic to switch to console mode
}

void tinyGamesQt::on_returnMenu_clicked()
{
    m_ui->stackedWidgetMenu->setCurrentWidget(m_ui->menuPage);
}

void tinyGamesQt::closeEvent(QCloseEvent* event)
{
    if (askQuitConfirmation()) {
        event->accept();
    } else {
        event->ignore();
    }
}

bool tinyGamesQt::askQuitConfirmation()
{
    const QMessageBox::StandardButton reply = QMessageBox::question(this,
                                                              "Confirm Quit",
                                                              "Are you sure you want to quit?",
                                                              QMessageBox::Yes | QMessageBox::No);
    return reply == QMessageBox::Yes;
}