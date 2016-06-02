#include <stdio.h>
#include <iostream>
#include "engine.h"
#include "gamestate.h"
#include "statewin.h"
#include "stateintro.h"

using namespace std;

void StateWin::init() {
    setInitDone();
}

void StateWin::render() {
    Engine::Instance().clear();
    cout << "Hooray, you built a boat!" <<
            "You sail away in your new boat into the sunset..." << endl <<
    R"(
        ___ __
       (_  ( . ) )__                  '.    \   :   /    .'
         '(___(_____)      __           '.   \  :  /   .'
                         /. _\            '.  \ : /  .'
                    .--.|/_/__      -----____   _  _____-----
    _______________''.--o/___  \_______________(_)___________
           ~        /.'o|_o  '.|  ~                   ~   ~
      ~            |/    |_|  ~'         ~
                   '  ~  |_|        ~       ~     ~     ~
         ~    ~          |_|O  ~                       ~
                ~     ___|_||_____     ~       ~    ~
      ~    ~      .'':. .|_|A:. ..::''.
                /:.  .:::|_|.\ .:.  :.:\   ~
     ~         :..:. .:. .::..:  .:  ..:.       ~   ~    ~
                \.: .:  :. .: ..:: .lcf/
       ~      ~      ~    ~    ~         ~
                  ~           ~    ~   ~             ~
           ~         ~            ~   ~                 ~
      ~                  ~    ~ ~                 ~)" << endl << endl;


    printCommands();
}

void StateWin::handleInput() {
    char userCommand;
    string input = "";
    getline(cin, input);

    if (input.length() == 1) {
        userCommand = input[0];
    } else {
        menuOptionAction();
        return;
    }

    switch (userCommand) {
    case 'w':   decreaseMenuOption();
        break;
    case 's':   increaseMenuOption();
        break;
    default:
        break;
    }
}

void StateWin::printCommands() {
    std::cout << "What would you like to do?" << endl;
        cout << "-> " << commands[0] << endl;
}

void StateWin::menuOptionAction() {

    switch(getCurrentMenuOption()){
    case 0: Engine::Instance().quit();
    default:
        break;
    }
}

void StateWin::pause() {}
void StateWin::resume() {}
void StateWin::clear() {}
void StateWin::update() {}
