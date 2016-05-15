#include "creature.h"

Creature::Creature()
{
    setHealth(100);
    setSymbol('C');
    setCanMove(true);
}

Creature::Creature(char symbol)
{
    setHealth(100);
    setSymbol(symbol);
    setCanMove(true);
}

Creature::Creature(char symbol, int x, int y)
{
    setHealth(100);
    setSymbol(symbol);
    setX(x);
    setY(y);
    setCanMove(true);
}

void Creature::setHealth(int health)
{
    this->health = health;
}

int Creature::getHealth() const
{
    return health;
}

void Creature::changeHealth(int healthChange)
{
    health += healthChange;
}

bool Creature::isAlive() const
{
    if(health > 0)
        return true;
    else
        return false;
}

void Creature::moveX(int x)
{
    //Can this creature move at all?
    if(isCanMove()){

        //is there anyting blocking?
        //Tile* tile =

    }
}

void Creature::update()
{

}
