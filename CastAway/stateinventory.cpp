#include <stdio.h>
#include <iostream>
#include "stateplay.h"
#include "stateinventory.h"

StateInventory StateInventory::inventoryState;

void StateInventory::init(){
    setInitDone();
}

void StateInventory::update()
{

}

void StateInventory::render()
{
    Engine::Instance().clear();


    std::cout << "             ___      ___  __   __      " << std::endl;
    std::cout << "| |\\ | \\  / |__  |\\ |  |  /  \\ |__) \\ / " << std::endl;
    std::cout << "| | \\|  \\/  |___ | \\|  |  \\__/ |  \\  |  " << std::endl;


    printCommands();
}

void StateInventory::handleInput()
{
    char userCommand;
    std::cin >> userCommand;

    switch (userCommand)
    {
    case '0': Engine::Instance().changeState(StatePlay::instance());
              break;
     default:
            break;
    }
}

void StateInventory::clear()
{

}

void StateInventory::printCommands()
{
    for (std::vector<std::string>::const_iterator it = commands.begin() ; it != commands.end(); ++it){
        std::cout << it - commands.begin() << ": " << *it << "\n";
    }

      //TODO
    //Show everything in the inventory
    /*Inventory* inventory = Engine::Instance().getPlayer()->getInventory();
    for (std::vector<Item*>::const_iterator it = inventory->getItems().begin() ; it != inventory->getItems().end(); ++it){
        std::cout << *it << "\n";
    }*/
}

void StateInventory::pause()
{

}

void StateInventory::resume()
{

}


