//
// Created by walcz on 26/07/2025.
//

#ifndef TINYGAMESQT_H
#define TINYGAMESQT_H

#include "../IGameUi.h"
#include <QtWidgets/QMainWindow>

QT_BEGIN_NAMESPACE
    namespace Ui { class tinyGamesVisualQtUi; }
QT_END_NAMESPACE

enum class Backend;
class TinyGamesLauncher;

class tinyGamesQt : public QMainWindow , public IGameUi{

    Q_OBJECT

    public:
        explicit tinyGamesQt(QWidget* parent, TinyGamesLauncher* launcher);
        ~tinyGamesQt() override;
        void menu() override;
        void runDice() override;
        void runShifumi() override;
        void switchBackend() override;
        void exit() override;

    private slots:
        // Add other methods as needed for the Qt UI
        void on_playDiceButton_clicked();
        void on_playShifumiButton_clicked();
        void on_switchUiBackendButton_clicked();
        void on_quitButton_clicked();
        void on_switchConsole_clicked();
        void on_returnMenu_clicked();

    private:
        void closeEvent(QCloseEvent* event) override;
        bool askQuitConfirmation();

        Ui::tinyGamesVisualQtUi* m_ui;
        bool isActive = false;
        TinyGamesLauncher* m_launcher;
};

#endif //TINYGAMESQT_H