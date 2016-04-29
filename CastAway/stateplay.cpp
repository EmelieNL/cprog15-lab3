#include <iostream>
#include "engine.h"
#include "gamestate.h"
#include "stateplay.h"
#include "statepausemenu.h"

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
    case 'q': engine->changeState(StatePauseMenu::instance());
              break;
    case 'w':
                break;
    case 'a':
                break;
    case 's':
                break;
    case 'd':
                break;
     default:
            break;

    }
}

void StatePlay::update(Engine* engine){

}

void StatePlay::render(const Engine* engine){
    engine->getMap()->render();
    printCommands();
}

//Print available commands that the player can enter
void StatePlay::printCommands()
{
    std::cout << "w: Move up" << '\n';
    std::cout << "a: Move left" << '\n';
    std::cout << "s: Move down" << '\n';
    std::cout << "d: Move right" << '\n';

    std::cout << '\n';

    std::cout << "q: Menu" << '\n';

}

