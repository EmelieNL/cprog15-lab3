#include <iostream>
#include "engine.h"
#include "gamestate.h"
#include "stateplay.h"
#include "statepausemenu.h"

StatePlay StatePlay::playState;

void StatePlay::init(){

    if(isInitDone())
        return;

    std::cout << "Play init!" << "\n";
    Engine::Instance().loadMap("level_1");

    Player* player = new Player;
    Engine::Instance().setPlayer(player);

    //start pos for the player
    int playerX = 1;
    int playerY = 1;

    player->setX(playerX);
    player->setY(playerY);

    Engine::Instance().getMap()->getTile(playerX, playerY)->setAbsEntity(player);

    setInitDone();
}

void StatePlay::clear(){

}

void StatePlay::pause(){

}

void StatePlay::resume(){
}

void StatePlay::handleInput(){
    char userCommand;
    std::cin >> userCommand;

    switch (userCommand)
    {
    case 'q': Engine::Instance().changeState(StatePauseMenu::instance());
              break;

    //Movement
    case 'w':
                Engine::Instance().getPlayer()->moveY(-1);
                break;
    case 'a':
                Engine::Instance().getPlayer()->moveX(-1);
                break;
    case 's':
                Engine::Instance().getPlayer()->moveY(1);
                break;
    case 'd':
                Engine::Instance().getPlayer()->moveX(1);
                break;

     //Actions
     case 'i':
                Engine::Instance().changeState(StateInventory::instance());
                break;
     default:
            break;

    }
}

void StatePlay::update(){

}

void StatePlay::render(){
    Engine::Instance().getMap()->render();
    printCommands();
}

//Print available commands that the player can enter
void StatePlay::printCommands()
{
    std::cout << "-- Actions --" << '\n';
    std::cout << "w: Move up" << '\n';
    std::cout << "a: Move left" << '\n';
    std::cout << "s: Move down" << '\n';
    std::cout << "d: Move right" << '\n';
    std::cout << "i: Inventory" << '\n';
    std::cout << '\n';

    std::cout << "q: Menu" << '\n';

    if(Engine::Instance().isDebug()){
        std::cout << "Player pos: (" << Engine::Instance().getPlayer()->getX() << ", " << Engine::Instance().getPlayer()->getY() << ")\n";
    }

}

