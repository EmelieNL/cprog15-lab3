#ifndef STATEQUEST_H
#define STATEQUEST_H

#include "gamestate.h"

class StateQuest:public IGameState
{
public:
    // Assignment and copy constructors are deleted due to singelton
    StateQuest (const StateQuest&) = delete;
    void operator= (const StateQuest&) = delete;

    void init();
    void update();
    void render();
    void handleInput();
    void clear();

    //Be able to pause states when we enter a new one
    void pause();
    void resume();


    // Get static instance
    static StateQuest& instance(){
        static StateQuest questState;
        return questState;
    }

protected:
    StateQuest() {}
};

#endif // STATEQUEST_H
