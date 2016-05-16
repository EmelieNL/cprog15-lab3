#include <stdio.h>
#include <iostream>

#include "gamestate.h"
#include "stateintro.h"
#include "stateplay.h"

StateIntro StateIntro::introState;

void StateIntro::init(){
    this->render();
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

void StateIntro::handleInput(){
    char userCommand;
    std::cin >> userCommand;

    switch (userCommand)
    {
    case '0': Engine::Instance().changeState(StatePlay::instance());
              break;
    case '1':
                break;
    case '2': Engine::Instance().quit();
               break;
     default:
            break;

    }
}

void StateIntro::update(){

}

void StateIntro::render(){
    Engine::Instance().clear();

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
