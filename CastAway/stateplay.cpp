#include <iostream>
#include "engine.h"
#include "gamestate.h"
#include "stateplay.h"
#include "statepausemenu.h"

void StatePlay::init(){

    if(isInitDone())
        return;

    std::cout << "Play init!" << "\n";
    Engine::Instance().loadMap("level_1");

    Player* player = new Player;
    Engine::Instance().setPlayer(player);

    //start pos for the player
    int playerX = 5;
    int playerY = 5;

    player->setX(playerX);
    player->setY(playerY);

    player->addLog("You wake up and regain your conscience!");

    //Update player terrain info even as the player have not yet moved...
    Terrain* currentTerrain = Engine::Instance().getMap()->getTile(player->getX(), player->getY())->getTerrain();
    player->addLog(currentTerrain->getDesc());


    Engine::Instance().getMap()->addAbstractEntity(player->getX(), player->getY(), player);


    //Player starting items
    //Item* knife = new Item("Knife", 400, '|');
    //player->getInventory()->addItem(knife);

    setInitDone();
}

void StatePlay::clear(){

}

void StatePlay::pause(){

}

void StatePlay::resume(){
}

void StatePlay::handleInput(){
    char userCommand = 0;
    std::string input = "";
    getline(std::cin, input);

    if (input.length() == 1) {
     userCommand = input[0];
    }

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
     Engine::Instance().getMap()->update();
}

void StatePlay::render(){
    Engine::Instance().getMap()->render();

    //Output health
    std::cout << "HEALTH " << Engine::Instance().getPlayer()->getHealth() << std::endl;

    printCommands();

    //Print player log
     std::cout << std::endl;
    std::cout << "-- Log --" << std::endl;
    std::vector<std::string> log = Engine::Instance().getPlayer()->getLog();
    std::vector<std::string>::iterator it, end;
    for(it = log.begin(), end = log.end() ; it != end; ++it) {
        std::cout << (*it) << std::endl;
    }
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

