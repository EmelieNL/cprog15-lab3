#include <iostream>
#include "engine.h"
#include "gamestate.h"
#include "stateplay.h"

StatePlay StatePlay::playState;

void StatePlay::init(Engine *engine){
     std::cout << "Play init!" << "\n";
    engine->loadMap("level_1");
}

void StatePlay::clear(){

}

void StatePlay::pause(){

}

void StatePlay::resume(){
}

void StatePlay::handleInput(Engine* engine){
    char userCommand;
    std::cin >> userCommand;

    switch (userCommand)
    {
    case '0': //engine->changeState();
              break;
    case '1':
                break;
    case '2': engine->quit();
               break;
     default:
            break;

    }
}

void StatePlay::update(Engine* engine){

}

void StatePlay::render(const Engine* engine){
   // engine->clear();
     std::cout << "Play render!" << "\n";
    engine->getMap()->render();
}

