#include <stdio.h>
#include <iostream>

#include "stateplay.h"
#include "statequest.h"

using namespace std;

void StateQuest::init(){
    if(!isInitDone()){
        this->render();
        setInitDone();
    }
}

void StateQuest::clear(){
    cout << "StateQuest clear!" << "\n";
}

void StateQuest::pause(){
    cout << "StateQuest pause!" << "\n";
}

void StateQuest::resume(){

}

void StateQuest::handleInput(){
    string input = "";
    getline(cin, input);

    Engine::Instance().changeState(StatePlay::instance());
}

void StateQuest::update(){

}

void StateQuest::render(){
    Engine::Instance().clear();

    cout <<
    R"(
                         |
                     \       /
                       .-"-.
                  --  /     \  --
`~~^~^~^~^~^~^~^~^~^-=======-~^~^~^~~^~^~^~^~^~^~^~`
`~^_~^~^~-~^_~^~^_~-=========- -~^~^~^-~^~^_~^~^~^~`
`~^~-~~^~^~-^~^_~^~~ -=====- ~^~^~-~^~_~^~^~~^~-~^~`
`~^~^~-~^~~^~-~^~~-~^~^~-~^~~^-~^~^~^-~^~^~^~^~~^~-`
    )" << endl;

    cout << "You regain your conscious in the cold water, you are shipwrecked and lost" << endl;
    cout << "How will you escape this place? Will you survive as a CastAway?" << endl << endl;
    cout << "Press enter to continue..." << endl;
}
