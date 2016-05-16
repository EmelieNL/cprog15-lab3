#ifndef STATEPAUSEMENU_H
#define STATEPAUSEMENU_H

#include "gamestate.h"

class StatePauseMenu:public GameState
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
    static StatePauseMenu* instance(){
        return &pausemenuState;
    }

protected:
    //IntroState() {}

private:
    static StatePauseMenu pausemenuState;
    const std::vector<std::string> commands = {"Continue", "Quit"};
};

#endif // STATEPAUSEMENU_H
