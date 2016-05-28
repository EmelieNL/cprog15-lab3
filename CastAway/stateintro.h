#ifndef STATEINTRO_H
#define STATEINTRO_H

#include "gamestate.h"
#include "menuoption.h"

class StateIntro:public IGameState, public MenuOption
{

public:
    // Assignment and copy constructors are deleted due to singelton
    StateIntro (const StateIntro&) = delete;
    void operator= (const StateIntro&) = delete;

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
    static StateIntro& instance(){
        static StateIntro introState;
        return introState;
    }

protected:
    StateIntro() {}

private:
    const std::vector<std::string> commands = {"Play", "Help", "Quit"};
};

#endif // STATEINTRO_H
