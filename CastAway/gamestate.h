#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "engine.h"

class GameState {
public:
    virtual void init(Engine* engine) = 0;
    virtual void update(Engine* engine) = 0;
    virtual void render(const Engine* engine) = 0;
    virtual void handleInput(Engine* engine) = 0;
    virtual void clear() = 0;

    //Be able to pause states when we enter a new one
    virtual void pause() = 0;
    virtual void resume() = 0;

    //Change gamestate from this to another
    virtual void changeState(Engine* engine, GameState* state){
        engine->changeState(state);
    }


protected:
    GameState(){}
};

#endif // GAMESTATE_H
