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
    /*
    //Can this creature move at all?
    if(isCanMove()){

        //is there anyting blocking?
        if(Engine::getMap()->isBlocked(getX() + x, getY())){
            return false;
        } else {

            //Remove creature from map tile
            Engine::getMap()->getTile(getX(), getY())->setAbsEntity(nullptr);

            //Update the creatures position
            setX(getX()+x);

            //Add creatre to map tile
            Engine::getMap()->getTile(getX(), getY())->setAbsEntity(this);



        }

    }*/
}

void Creature::update()
{

}
