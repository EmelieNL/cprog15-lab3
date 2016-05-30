#include "fish.h"

Fish::Fish()
{
    init('F');
}

Fish::Fish(char symbol)
{
    init(symbol);
}

void Fish::moveX(int x)
{
    const auto newX = getX() + x;

    //check map boundaries in x
    if(newX < 0 || newX >= Engine::Instance().getMap()->getWidth())
        return;

    Terrain* newTerrain = Engine::Instance().getMap()->getTile(newX, getY())->getTerrain();

    //Check that the new terrain really is water
    if(newTerrain->getType() == Terrain::Type::WATER){
        Creature::moveX(x); //call parent
    }
}

void Fish::moveY(int y)
{
    const auto newY = getY() + y;

    //check map boundaries in y
    if(newY < 0 || newY >= Engine::Instance().getMap()->getHeight())
        return;

    Terrain* newTerrain = Engine::Instance().getMap()->getTile(getX(), newY)->getTerrain();

    //Check that the new terrain really is water
    if(newTerrain->getType() == Terrain::Type::WATER){
        Creature::moveY(y); //call parent
    }
}
