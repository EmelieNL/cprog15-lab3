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
    Inventory* inventory = Engine::Instance().getPlayer()->getInventory();

    //Print nr of items
    std::cout << "You have " << inventory->getInventorySize()<< " items in your inventory. Weight: " << inventory->getWeight() << " gram" << std::endl;

    //Commands?
    for (std::vector<std::string>::const_iterator it = commands.begin() ; it != commands.end(); ++it){
        std::cout << it - commands.begin() << ": " << *it << "\n";
    }

    std::cout << std::endl;

    //Show everything in the inventory
    std::vector<Item*> items = inventory->getItems();
    std::vector<Item*>::iterator it, end;
    for(it = items.begin(), end = items.end() ; it != end; ++it) {
        std::cout << (*it)->getId() << ", " << (*it)->getWeight() << " gram" << std::endl;
    }
}

void StateInventory::pause()
{

}

void StateInventory::resume()
{

}
