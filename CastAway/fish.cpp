#include "fish.h"

Fish::Fish()
{
    init('C');
}

Fish::Fish(char symbol)
{
    init(symbol);
}

void Fish::moveX(int x)
{
    const auto newX = getX() + x;
    Terrain* newTerrain = Engine::Instance().getMap()->getTile(newX, getY())->getTerrain();

    //Check that the new terrain really is water
    if(newTerrain->getType() == Terrain::Type::WATER){
        Creature::moveX(x); //call parent
    }
}

void Fish::moveY(int y)
{
    const auto newY = getY() + y;
    Terrain* newTerrain = Engine::Instance().getMap()->getTile(getX(), newY)->getTerrain();

    //Check that the new terrain really is water
    if(newTerrain->getType() == Terrain::Type::WATER){
        Creature::moveY(y); //call parent
    }
}
