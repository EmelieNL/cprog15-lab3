#ifndef STATEINTRO_H
#define STATEINTRO_H

#include "gamestate.h"

class StateIntro:public GameState
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
    static StateIntro* instance(){
        return &introState;
    }

protected:
    //IntroState() {}

private:
    static StateIntro introState;
    const std::vector<std::string> commands = {"Play", "Help", "Quit"};
};

#endif // STATEINTRO_H
