#include <stdio.h>
#include <iostream>
#include "engine.h"
#include "gamestate.h"
#include "stateintro.h"
#include "stateplay.h"

StateIntro StateIntro::introState;

void StateIntro::init(Engine* engine){
    this->render(engine);
}

void StateIntro::clear(){
  std::cout << "IntroState clear!" << "\n";
}

 void StateIntro::printCommands()
{
    std::cout << "What would you like to do?" << "\n";

    for (std::vector<std::string>::const_iterator it = commands.begin() ; it != commands.end(); ++it){
        std::cout << it - commands.begin() << ": " << *it << "\n";
    }
}

void StateIntro::pause(){
    std::cout << "IntroState pause!" << "\n";
}

void StateIntro::resume(){
    std::cout << "IntroState resume!" << "\n";
}

void StateIntro::handleInput(Engine* engine){
    char userCommand;
    std::cin >> userCommand;

    switch (userCommand)
    {
    case '0': engine->changeState(StatePlay::instance());
              break;
    case '1':
                break;
    case '2': engine->quit();
               break;
     default:
            break;

    }
}

void StateIntro::update(Engine* engine){

}

void StateIntro::render(const Engine* engine){
    engine->clear();

    std::cout << "Welcome to" << "\n";
    std::cout << "   _____          _                              " << "\n";
    std::cout << "  / ____|        | |     /\\                      " << "\n";
    std::cout << " | |     __ _ ___| |_   /  \\__      ____ _ _   _ " << "\n";
    std::cout << " | |    / _` / __| __| / /\\ \\ \\ /\\ / / _` | | | |" << "\n";
    std::cout << " | |___| (_| \\__ \\ |_ / ____ \\ V  V / (_| | |_| |" << "\n";
    std::cout << "  \\_____\\__,_|___/\\__/_/    \\_\\_/\\_/ \\__,_|\\__, |" << "\n";
    std::cout << "                                            __/ |" << "\n";
    std::cout << "                                           |___/ " << "\n";

    printCommands();
}
