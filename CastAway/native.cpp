#include "native.h"

Native::Native()
{
    /* initialize random seed: */
    srand (time(NULL));

    setIsLookingForItem(false);
    init('H');
}

void Native::moveX(int x)
{
    const auto newX = getX() + x;

    //check map boundaries in x
    if(newX < 0 || newX >= Engine::Instance().getMap()->getWidth())
        return;

    Terrain* newTerrain = Engine::Instance().getMap()->getTile(newX, getY())->getTerrain();

    //Check that the new terrain really is solid
    if(newTerrain->isSolid()){
        Creature::moveX(x); //call parent
    }
}

void Native::moveY(int y)
{
    const auto newY = getY() + y;

    //check map boundaries in y
    if(newY < 0 || newY >= Engine::Instance().getMap()->getHeight())
        return;

    Terrain* newTerrain = Engine::Instance().getMap()->getTile(getX(), newY)->getTerrain();

    //Check that the new terrain really is solid
    if(newTerrain->isSolid()){
        Creature::moveY(y); //call parent
    }
}

void Native::addDialog(std::string message)
{
    dialog.insert(dialog.begin(), message); //Add message to first position
}

std::string Native::popDialog()
{
   std::string message = dialog.back();
   dialog.pop_back(); //Pop last
   return message;
}

std::string Native::getRandomDialog() const
{
    int random = rand() % dialog.size(); //Get random dialog from 0 - size
    return dialog.at(random);
}

bool Native::haveDialog() const
{
    if(dialog.size() > 0)
        return true;

    return false;
}

bool Native::isLookingForItem() const
{
    return lookingForItem;
}

void Native::setIsLookingForItem(bool value)
{
    lookingForItem = value;
}

std::string Native::getLookingForId() const
{
    return lookingForId;
}

void Native::setLookingForId(std::string id)
{
    lookingForId = id;
}

int Native::getNeedAmount() const
{
    return needAmount;
}

void Native::setNeedAmount(int value)
{
    needAmount = value;

    //If the native have all items needed, dont look for anything more
    if(needAmount == 0){
        setIsLookingForItem(false);
    }
}
