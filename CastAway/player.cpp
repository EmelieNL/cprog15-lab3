#include "player.h"
#include "item.h"
#include "inventory.h"
#include "native.h"
#include "stategameover.h"
#include "statewin.h"
#include "engine.h"
#include "tree.h"
#include "axe.h"

#include <iostream>

Player::Player()
{
    setSymbol('@');
    setCanMove(true);
    setFgColor(conmanip::console_text_colors::light_yellow);
    setBgColor(conmanip::console_bg_colors::black);
}

Player::~Player()
{
    std::cout << "Destructor for Player" << std::endl;
}
void Player::addLog(std::string message)
{
    log.insert(log.begin(), message); //Add message to first position

    //Only store 10 messages
    if(log.size() > 10)
        log.pop_back(); //remove last message
}

std::vector<std::string> Player::getLog() const
{
    return log;
}

void Player::moveX(int x)
{
    int newX = getX() + x;
    int newY = getY();

    //Can this creature move at all?
    if(isCanMove()){

         //check map boundaries in x
        if(newX < 0 || newX >= Engine::Instance().getMap()->getWidth()){
              return;

        //is there anyting blocking?
        }else if(Engine::Instance().getMap()->isBlocked(newX, newY)){
            action(newX, newY);
            return;

        //move
        } else {

            //Update terrain info
            updateTerrainData(newX, newY);

            //Remove creature from map tile
            Engine::Instance().getMap()->getTile(getX(), getY())->setAbsEntity(nullptr);

            //Update the creatures position
            setX(newX);

            //Add creatre to map tile
            Engine::Instance().getMap()->getTile(getX(), getY())->setAbsEntity(this);
        }
    }
}

void Player::moveY(int y)
{
    int newX = getX();
    int newY = getY() + y;

    //Can this creature move at all?
    if(isCanMove()){

        //check map boundaries in y
        if(newY < 0 || newY >= Engine::Instance().getMap()->getHeight()){
            return;

        //is there anything blocking?
        } else if(Engine::Instance().getMap()->isBlocked(newX, newY)){
            action(newX, newY);
            return;

        //move
        } else {

            //Update terrain info
            updateTerrainData(newX, newY);

            //Remove creature from map tile
            Engine::Instance().getMap()->getTile(getX(), getY())->setAbsEntity(nullptr);

            //Update the creatures position
            setY(newY);

            //Add creatre to map tile
            Engine::Instance().getMap()->getTile(getX(), getY())->setAbsEntity(this);
        }
    }
}

void Player::action(int x, int y)
{
    //Get the entity at x and y
    Tile* tile = Engine::Instance().getMap()->getTile(x, y);
    AbstractEntity* blocking = tile->getAbsEntity();

    //If we hit a item, try to pick it up
    if(Item* item = dynamic_cast<Item*>(blocking)) {
        if(getInventory()->addItem(item)){
            addLog("You picked up a " + item->getId());
            Engine::Instance().getMap()->removeAbstractEntity(blocking);

         //could not pick up item
        } else {
             addLog("You see a " + item->getId() + " but can't pick it up!");
        }

    //If we hit a creature
    } else if(Creature* enemy = dynamic_cast<Creature*>(blocking)){

        //If hostile attack
        if(enemy->isHostile()) {
            int damageDelt = attack(enemy);
            if(enemy->isAlive()){
                addLog("You hit " + enemy->getId() + " with " + std::to_string(damageDelt) + " damage! Health: " + std::to_string(enemy->getHealth()));
            } else {
                addLog("You killed the " + enemy->getId() + "!");
            }

        //not hostile
        } else {

            //Is it a native?
            if(Native* native = dynamic_cast<Native*>(blocking)){

                //Is this native looking for something?
                if(native->isLookingForItem()){
                   addLog(native->getId() + " says: I need " +  std::to_string(native->getNeedAmount()) + " " + native->getLookingForId() + " to build a decent boat for you.");

                   //If the player have this item in inventory
                   Item* giveItem = getInventory()->getItem(native->getLookingForId());
                   if(giveItem != nullptr){
                       int need = native->getNeedAmount();

                       //If the player have more then needed
                       if(giveItem->getStackAmount() > need){
                           native->setNeedAmount(0); //The native now has all he needs
                           giveItem->setStackAmount(giveItem->getStackAmount()-need); //lower stack amount
                           addLog("You give "+ std::to_string(need) + " " + giveItem->getId() + " to " + native->getId() + " which is what was needed, and you still have some left.");

                       //Player have just enough or less
                       } else if(giveItem->getStackAmount() == need){
                          native->setNeedAmount(0);
                          addLog("You give all "+ std::to_string(need) + " " + giveItem->getId() + " to " + native->getId() + " which was exactly what was needed.");
                          getInventory()->removeItem(giveItem); //remove from inventory

                       //Player does not have enough
                       } else {
                           //Give as much as possible
                           native->setNeedAmount(need-giveItem->getStackAmount());
                           addLog("You give all " + std::to_string(giveItem->getStackAmount()) + " " + giveItem->getId() + " to " + native->getId() + " but more is needed.");
                           getInventory()->removeItem(giveItem); //remove from inventory
                       }

                       //Does the native have all he needs? Then drop first item from his inventory
                       if( native->getNeedAmount() == 0){
                            addLog(native->getId() + " says: Thank you! Here is your reward... A " + native->getInventory()->getItem(0)->getId() + "! I will now go to rest");
                            native->setHealth(0);
                       }
                   } else {
                       addLog("You dont have any " + native->getLookingForId() + " to give...");

                   }
                } else if(native->haveDialog()){
                    addLog(native->getId() + " says: " + native->getRandomDialog());
                } else {
                   addLog("You bumped in to a friendly " + blocking->getId());
                }

            } else {
                addLog("You bumped in to a friendly " + blocking->getId());
            }
        }

    //If we hit a tree
    } else if(Tree* tree = dynamic_cast<Tree*>(blocking)){

            //Do we have a axe?
            if(dynamic_cast<Axe*>(getWeapon())){
                if(tree->chopDown()){
                    addLog("You choped down the " + tree->getId());
                }
            } else {
                addLog("You need to equip a axe to chop down the " + tree->getId());
            }
    } else {
        addLog("You bumped in to a " + blocking->getId());
    }
}

// If player is dead, it's GO
void Player::update() {
    if (!isAlive()) Engine::Instance().changeState(StateGameOver::instance());
}

void Player::updateTerrainData(int newX, int newY)
{

    Terrain* currentTerrain = Engine::Instance().getMap()->getTile(getX(), getY())->getTerrain();
    Terrain* newTerrain = Engine::Instance().getMap()->getTile(newX, newY)->getTerrain();

    //Add info to the player if the terrain changes
    if(currentTerrain->getType() != newTerrain->getType()){
         Engine::Instance().getPlayer()->addLog(newTerrain->getDesc());
    }

    //Effect the player if the terrain have any effect
    newTerrain->effect(this);
}
