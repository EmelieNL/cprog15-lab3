#ifndef STATEHELP_H
#define STATEHELP_H

#include "gamestate.h"

class StateHelp:public IGameState
{
public:
    // Assignment and copy constructors are deleted due to singelton
    StateHelp (const StateHelp&) = delete;
    void operator= (const StateHelp&) = delete;

    void init();
    void update();
    void render();
    void handleInput();
    void clear();

    //Be able to pause states when we enter a new one
    void pause();
    void resume();


    // Get static instance
    static StateHelp& instance(){
        static StateHelp helpState;
        return helpState;
    }

protected:
    StateHelp() {}
};

#endif // STATEHELP_H
