#include <stdio.h>
#include <iostream>
#include "engine.h"
#include "gamestate.h"
#include "stateplay.h"

#include "statepausemenu.h"

StatePauseMenu StatePauseMenu::pausemenuState;

void StatePauseMenu::init(Engine* engine){
    this->render(engine);
}

void StatePauseMenu::clear(){
  std::cout << "IntroState clear!" << "\n";
}

 void StatePauseMenu::printCommands()
{
    std::cout << "What would you like to do?" << "\n";

    for (std::vector<std::string>::const_iterator it = commands.begin() ; it != commands.end(); ++it){
        std::cout << it - commands.begin() << ": " << *it << "\n";
    }
}

void StatePauseMenu::pause(){
    std::cout << "IntroState pause!" << "\n";
}

void StatePauseMenu::resume(){
    std::cout << "IntroState resume!" << "\n";
}

void StatePauseMenu::handleInput(Engine* engine){
    char userCommand;
    std::cin >> userCommand;

    switch (userCommand)
    {
    case '0': engine->changeState(StatePlay::instance());
              break;
    case '1': engine->quit();
               break;
     default:
            break;
    }
}

void StatePauseMenu::update(Engine* engine){

}

void StatePauseMenu::render(const Engine* engine){
    engine->clear();


    std::cout << "   _____          _                              " << "\n";
    std::cout << "  / ____|        | |     /\\                      " << "\n";
    std::cout << " | |     __ _ ___| |_   /  \\__      ____ _ _   _ " << "\n";
    std::cout << " | |    / _` / __| __| / /\\ \\ \\ /\\ / / _` | | | |" << "\n";
    std::cout << " | |___| (_| \\__ \\ |_ / ____ \\ V  V / (_| | |_| |" << "\n";
    std::cout << "  \\_____\\__,_|___/\\__/_/    \\_\\_/\\_/ \\__,_|\\__, |" << "\n";
    std::cout << "                                            __/ |" << "\n";
    std::cout << "                                           |___/ " << "\n";

    std::cout << "Game paused" << "\n";

    printCommands();
}



