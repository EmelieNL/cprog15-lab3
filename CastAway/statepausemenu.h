#ifndef STATEPAUSEMENU_H
#define STATEPAUSEMENU_H

#include "menuoption.h"
#include "gamestate.h"

class StatePauseMenu:public IGameState, public MenuOption
{

public:
    // Assignment and copy constructors are deleted due to singelton
    StatePauseMenu (const StatePauseMenu&) = delete;
    void operator= (const StatePauseMenu&) = delete;

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

    //Get static
    static StatePauseMenu& instance(){
            static StatePauseMenu pausemenuState;
        return pausemenuState;
    }

protected:
    StatePauseMenu() {}

private:

    const std::vector<std::string> commands = {"Continue", "Quit"};
};

#endif // STATEPAUSEMENU_H
