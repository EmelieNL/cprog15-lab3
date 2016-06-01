#ifndef STATEGAMEOVER_H
#define STATEGAMEOVER_H

#include "menuoption.h"
#include "gamestate.h"

class StateGameOver:public IGameState, public MenuOption
{
public:
    // Assignment and copy constructors are deleted due to singelton
    StateGameOver (const StateGameOver&) = delete;
    void operator= (const StateGameOver&) = delete;

    void init();
    void update();
    void render();
    void handleInput();
    void clear();
    void printCommands();

    //Be able to pause states when we enter a new one
    void pause();
    void resume();

    void menuOptionAction();

    // Get static instance
    static StateGameOver &instance(){
        static StateGameOver gameOverState;
        return gameOverState;
    }

protected:
    StateGameOver() {}
private:
    const std::vector<std::string> commands = {"Quit"};
};

#endif // STATEGAMEOVER_H
