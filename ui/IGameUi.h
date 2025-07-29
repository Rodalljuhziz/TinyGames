//
// Created by walcz on 29/07/2025.
//

#ifndef IGAMEUI_H
#define IGAMEUI_H

class IGameUi {
public:
    virtual ~IGameUi() = default;
    virtual void menu() = 0;
    virtual void runDice() = 0;
    virtual void runShifumi() = 0;
    virtual void switchBackend() = 0;
    virtual void exit() = 0;
};

#endif //IGAMEUI_H
