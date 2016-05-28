#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "engine.h"

/* Interface (all functions are pure virtual) to handle the game */

class IGameState {
public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void handleInput() = 0;
    virtual void clear() = 0;

    //Be able to pause states when we enter a new one
    virtual void pause() = 0;
    virtual void resume() = 0;

    //Change gamestate from this to another
    virtual void changeState(IGameState& state){
        Engine::Instance().changeState(state);
    }

    bool isInitDone() const {
        return initDone;
    }

    void setInitDone(){
        initDone = true;
    }

private:
    bool initDone = false;
protected:
    IGameState(){}
};

#endif // GAMESTATE_H
