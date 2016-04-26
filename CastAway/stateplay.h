#ifndef STATEPLAY_H
#define STATEPLAY_H
#include "gamestate.h"

class StatePlay:public GameState
{
public:
    void init(Engine* engine);
    void update(Engine* engine);
    void render(const Engine* engine);
    void handleInput(Engine* engine);
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
    const std::vector<std::string> commands = {"Play", "Help", "Quit"};
};

#endif // STATEPLAY_H
