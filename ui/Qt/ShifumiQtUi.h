//
// Created by walcz on 10/07/2025.
//

#ifndef SHIFUMIQTUI_H
#define SHIFUMIQTUI_H

#include "../../lib/Shifumi/Shifumi.h"
#include <QtWidgets/QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ShifumiQtUi; }
QT_END_NAMESPACE

class ShifumiQtUi  : public QMainWindow
{

    Q_OBJECT

    public:
        explicit ShifumiQtUi(QWidget* parent = nullptr);
        ~ShifumiQtUi() override;

        void run();

    public slots:
        void on_action_playDiceButton_triggered();
        void on_action_playShifumiButton_triggered();
        void on_action_switchUiBackendButton_triggered();
        void on_action_quitButton_triggered();

    private:
        Ui::ShifumiQtUi* m_ui;
};

#endif //SHIFUMIQTUI_H
