#include "crab.h"

Crab::Crab()
{
    init('C');
}

Crab::Crab(char symbol)
{
    init(symbol);
}

void Crab::moveX(int x)
{
    const auto newX = getX() + x;
    Terrain* newTerrain = Engine::Instance().getMap()->getTile(newX, getY())->getTerrain();

    //Check that the new terrain really is sand
    if(newTerrain->getType() == Terrain::Type::SAND){
        Creature::moveX(x); //call parent
    }
}

void Crab::moveY(int y)
{
    const auto newY = getY() + y;
    Terrain* newTerrain = Engine::Instance().getMap()->getTile(getX(), newY)->getTerrain();

    //Check that the new terrain really is sand
    if(newTerrain->getType() == Terrain::Type::SAND){
        Creature::moveY(y); //call parent
    }
}
