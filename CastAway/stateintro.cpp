#include <stdio.h>
#include <iostream>

#include "gamestate.h"
#include "stateintro.h"
#include "stateplay.h"

StateIntro StateIntro::introState;

void StateIntro::init(){
    setInitDone();
}

void StateIntro::clear(){
  std::cout << "IntroState clear!" << "\n";
}

 void StateIntro::printCommands()
{
    std::cout << "What would you like to do? (Navigate with w, s and enter)" << "\n";

    for (std::vector<std::string>::const_iterator it = commands.begin() ; it != commands.end(); ++it){

        //If current item is selected show this to the user
        if(it - commands.begin() == getCurrentMenuOption()){
            std::cout << "-> ";
        }

        std::cout << "\t";
        std::cout << *it << "\n";
    }
}

void StateIntro::pause(){
    std::cout << "IntroState pause!" << "\n";
}

void StateIntro::resume(){
    setCurrentMenuOption(0);
    setMaxMenuOption(commands.size()-1);
}

void StateIntro::menuOptionAction()
{
    switch(getCurrentMenuOption()){
        case 0: Engine::Instance().changeState(StatePlay::instance());
                break;
        case 1:
                break;
        case 2: Engine::Instance().quit();
                break;
        default:
                break;

    }
}

void StateIntro::handleInput(){
    char userCommand;
    std::string input = "";
    getline(std::cin, input);

    if (input.length() == 1) {
     userCommand = input[0];
   } else {
        menuOptionAction();
        return;
   }

    switch (userCommand)
    {
        case 'w':   decreaseMenuOption();
                    break;
        case 's':   increaseMenuOption();
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
