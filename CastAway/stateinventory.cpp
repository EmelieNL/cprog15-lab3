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
    case 'i': Engine::Instance().changeState(StatePlay::instance());
              break;
    case 'w':   decreaseMenuOption();
                break;
    case 's':   increaseMenuOption();
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

    //Commands
    std::cout << "i: Continue" << std::endl;

    //Print nr of items
    std::cout << "You have " << inventory->getInventorySize()<< " items in your inventory. Weight: " << inventory->getWeight() << " gram" << std::endl;

    std::cout << std::endl;

    //Show everything in the inventory
    std::vector<Item*> items = inventory->getItems();
    std::vector<Item*>::iterator it, end;
    for(it = items.begin(), end = items.end() ; it != end; ++it) {

        //If current item is selected show this to the user
        if(it - items.begin() == getCurrentMenuOption()){
            std::cout << "-> ";
        }
        std::cout << (*it)->getId() << ", " << (*it)->getWeight() << " gram" << std::endl;
    }

    std::cout << "Current menu opt: " << getCurrentMenuOption() << std::endl;
}

void StateInventory::menuOptionAction()
{
    //TODO
}

void StateInventory::pause()
{

}

void StateInventory::resume()
{
    setCurrentMenuOption(0); //reset menuoption
    setMaxMenuOption(Engine::Instance().getPlayer()->getInventory()->getInventorySize()-1);
}
