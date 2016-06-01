#ifndef STATEWIN_H
#define STATEWIN_H

#include "menuoption.h"
#include "gamestate.h"


class StateWin:public IGameState, public MenuOption {
public:
    // Assignment and copy constructors are deleted due to singelton
    StateWin (const StateWin&) = delete;
    void operator= (const StateWin&) = delete;

    void init();
    void update();
    void render();
    void handleInput();
    void clear();
    void printCommands();
    void pause();
    void resume();
    void menuOptionAction();

    // Get static instance
    static StateWin &instance(){
        static StateWin winState;
        return winState;
    }

protected:
    StateWin() {}
private:
    const std::vector<std::string> commands = {"Quit"};
};

#endif // STATEWIN_H
