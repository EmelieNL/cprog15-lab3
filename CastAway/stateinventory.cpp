#include <stdio.h>
#include <iostream>
#include "stateplay.h"
#include "stateinventory.h"
#include "statewin.h"
#include "consumable.h"
#include "weapon.h"
#include "item.h"
#include "boat.h"

void StateInventory::init(){
    setInitDone();
}

void StateInventory::update()
{

}

void StateInventory::render()
{
    Engine::Instance().clear();

    std::cout <<
    R"(
                 ___      ___  __   __
    | |\ | \  / |__  |\ |  |  /  \ |__) \ /
    | | \|  \/  |___ | \|  |  \__/ |  \  |
    )" << std::endl;

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
    int pos = 0;
    const auto& items = inventory->getItems();
    for(const auto& item : items) {

        //If current item is selected show this to the user
        if(pos == getCurrentMenuOption()){
            std::cout << "-> ";
        }
        std::cout << item->getId() << ", " << item->getWeight() << " gram";

        if(item->getCanStack()){
            std::cout << " (" << item->getStackAmount() << " pcs)";
        }

        std::cout << std::endl;
        ++pos;
    }
}

void StateInventory::menuOptionAction()
{
    //Get the entity at x and y
    Player* player = Engine::Instance().getPlayer();

    if(getCurrentMenuOption() >= player->getInventory()->getInventorySize())
        return;

    Item* item = player->getInventory()->getItem(getCurrentMenuOption());

    if(item == nullptr)
        return;

    //If we try to use a consumable
    if(Consumable* consumable = dynamic_cast<Consumable*>(item)) {
        player->changeHealth(consumable->getHealthValue());
        player->addLog("You consume the " + item->getId()+ " and feel better");
        player->getInventory()->removeItem(item);

    //Use a weapon
    } else if(Weapon* wep = dynamic_cast<Weapon*>(item)) {
           player->setWeapon(wep);
           player->addLog("You arm yourself with the " + item->getId() + " (" + std::to_string(wep->getAttackValue()) + " damage)");

    //Use a boat
    } else if(dynamic_cast<Boat*>(item)) {

        //If player is in water
        if(Engine::Instance().getMap()->getTile(player->getX(), player->getY())->getTerrain()->getType() == Terrain::Type::WATER){
            player->addLog("You jump into the boat and start rowing to your freedom!");
            Engine::Instance().changeState(StateWin::instance());
            return;
        } else {
            player->addLog("You must be in the water to use the boat...");
        }

    } else {
        player->addLog("You could not use that...");
    }

    //Go back to play state
    Engine::Instance().changeState(StatePlay::instance());

}

void StateInventory::pause()
{

}

void StateInventory::resume()
{
    setCurrentMenuOption(0); //reset menuoption
    setMaxMenuOption(Engine::Instance().getPlayer()->getInventory()->getInventorySize()-1);
}
