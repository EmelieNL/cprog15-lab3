#ifndef STATEPLAY_H
#define STATEPLAY_H
#include <map>
#include "gamestate.h"
#include "player.h"

class StatePlay:public GameState
{
public:
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
    static StatePlay* instance(){
        return &playState;
    }
private:
    static StatePlay playState;
};

#endif // STATEPLAY_H
