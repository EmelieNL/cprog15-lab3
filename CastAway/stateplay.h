#ifndef STATEPLAY_H
#define STATEPLAY_H
#include <map>
#include "gamestate.h"
#include "player.h"
#include "stateinventory.h"

class StatePlay:public IGameState
{
public:
    // Assignment and copy constructors are deleted due to singelton
    StatePlay (const StatePlay&) = delete;
    void operator= (const StatePlay&) = delete;

    void init();
    void update();
    void render();
    void handleInput();
    void clear();
    void printCommands();

    //Be able to pause states when we enter a new one
    void pause();
    void resume();

    //Get static
    static StatePlay& instance(){
        static StatePlay playState;
        return playState;
    }

protected:
    StatePlay() {}
};

#endif // STATEPLAY_H
