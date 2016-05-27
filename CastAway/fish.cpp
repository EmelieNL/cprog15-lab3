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
    Terrain* newTerrain = Engine::Instance().getMap()->getTile(x, getY())->getTerrain();

    //Check that the new terrain really is water
    if(newTerrain->getType() == Terrain::Type::WATER){
        Creature::moveX(x); //call parent
    }
}

void Fish::moveY(int y)
{
    Terrain* newTerrain = Engine::Instance().getMap()->getTile(getX(), y)->getTerrain();

    //Check that the new terrain really is water
    if(newTerrain->getType() == Terrain::Type::WATER){
        Creature::moveY(y); //call parent
    }
}
