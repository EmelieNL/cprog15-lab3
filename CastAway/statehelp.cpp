#include <stdio.h>
#include <iostream>

#include "stateintro.h"
#include "statehelp.h"

using namespace std;

void StateHelp::init(){
    if(!isInitDone()){
        this->render();
        setInitDone();
    }
}

void StateHelp::clear(){
    cout << "StateHelp clear!" << "\n";
}

void StateHelp::pause(){
    cout << "StateHelp pause!" << "\n";
}

void StateHelp::resume(){

}

void StateHelp::handleInput(){
    string input = "";
    getline(cin, input);

    Engine::Instance().changeState(StateIntro::instance());
}

void StateHelp::update(){

}

void StateHelp::render(){
    Engine::Instance().clear();

    cout <<
    R"(
    ___       __
|__| |__  |    |__)
|  | |___ |___ |


    )" << endl;

    cout << "You goal is to escape the island and stay alive." << endl;
    cout << "Use menus with w, s and enter. The possible keyboard inputs in-game are always visible on the screen." << endl;
    cout << "Try to find and use resources as it will help you! View your inventory with the i-key and use items with w, s and enter." << endl;
    cout << "Move into entities to interact with them, such as picking up, attacking or just talking." << endl;
    cout << "Good luck!" << endl << endl;

    cout << "Press enter to continue..." << endl;
}
