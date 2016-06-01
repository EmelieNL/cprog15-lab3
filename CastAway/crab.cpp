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

    //check map boundaries in x
    if(newX < 0 || newX >= Engine::Instance().getMap()->getWidth())
        return;

    Terrain* newTerrain = Engine::Instance().getMap()->getTile(newX, getY())->getTerrain();

    //Check that the new terrain really is sand
    if(newTerrain->getType() == Terrain::Type::SAND){
        Creature::moveX(x); //call parent
    }
}

void Crab::moveY(int y)
{
    const auto newY = getY() + y;

    //check map boundaries in y
    if(newY < 0 || newY >= Engine::Instance().getMap()->getHeight())
        return;

    Terrain* newTerrain = Engine::Instance().getMap()->getTile(getX(), newY)->getTerrain();

    //Check that the new terrain really is sand
    if(newTerrain->getType() == Terrain::Type::SAND){
        Creature::moveY(y); //call parent
    }
}
