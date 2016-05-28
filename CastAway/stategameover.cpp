#include <stdio.h>
#include <iostream>
#include "engine.h"
#include "gamestate.h"
#include "stategameover.h"
#include "stateintro.h"

using namespace std;

void StateGameOver::init() {
    setInitDone();
}

void StateGameOver::render() {
    Engine::Instance().clear();
    cout <<
    R"(
      _____          __  __ ______    ______      ________ _____
     / ____|   /\   |  \/  |  ____|  / __ \ \    / /  ____|  __ \
    | |  __   /  \  | \  / | |__    | |  | \ \  / /| |__  | |__) |
    | | |_ | / /\ \ | |\/| |  __|   | |  | |\ \/ / |  __| |  _  /
    | |__| |/ ____ \| |  | | |____  | |__| | \  /  | |____| | \ \
     \_____/_/    \_\_|  |_|______|  \____/   \/   |______|_|  \_\ )" << endl;

    printCommands();
}

void StateGameOver::handleInput() {
    char userCommand;
    string input = "";
    getline(cin, input);

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

void StateGameOver::printCommands() {
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

void StateGameOver::menuOptionAction() {

    switch(getCurrentMenuOption()){
    case 0: Engine::Instance().changeState(StateIntro::instance());
        break;
    case 1: Engine::Instance().quit();
        break;
    default:
        break;
    }
}

void StateGameOver::pause() {}
void StateGameOver::resume() {}
void StateGameOver::clear() {}
void StateGameOver::update() {}
