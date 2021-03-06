#include <stdio.h>
#include <iostream>
#include "engine.h"
#include "gamestate.h"
#include "stateplay.h"

#include "statepausemenu.h"

void StatePauseMenu::init(){
    setInitDone();
}

void StatePauseMenu::clear(){
  std::cout << "StatePauseState clear!" << "\n";
}

 void StatePauseMenu::printCommands()
{
    std::cout << "What would you like to do?" << "\n";

    for (std::vector<std::string>::const_iterator it = commands.begin() ; it != commands.end(); ++it){
        //If current item is selected show this to the user
        if(it - commands.begin() == getCurrentMenuOption()){
            std::cout << "-> ";
        }

        std::cout << "\t";
        std::cout << *it << "\n";
    }
}

void StatePauseMenu::pause(){
}

void StatePauseMenu::resume(){
    setCurrentMenuOption(0);
    setMaxMenuOption(commands.size()-1);
}

void StatePauseMenu::menuOptionAction()
{
    switch(getCurrentMenuOption()){
        case 0: Engine::Instance().changeState(StatePlay::instance());
                break;
        case 1: Engine::Instance().quit();
                break;
        default:
                break;
    }
}

void StatePauseMenu::handleInput(){
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

void StatePauseMenu::update(){

}

void StatePauseMenu::render(){
    Engine::Instance().clear();

    std::cout <<
    R"(
    _____          _
   / ____|        | |     /\
  | |     __ _ ___| |_   /  \__      ____ _ _   _
  | |    / _` / __| __| / /\ \ \ /\ / / _` | | | |
  | |___| (_| \__ \ |_ / ____ \ V  V / (_| | |_| |
   \_____\__,_|___/\__/_/    \_\_/\_/ \__,_|\__, |
                                             __/ |
                                            |___/ )" << std::endl;

    std::cout << "Game paused" << "\n";

    printCommands();
}



