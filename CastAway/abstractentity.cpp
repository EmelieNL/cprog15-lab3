#include <iostream>
#include "abstractentity.h"
#include "engine.h"

//Basic class to represent entities thay can exist in the game world,
//should be extended by all other map objects etc

int AbstractEntity::getColor() const
{
    return this->color;
}

int AbstractEntity::getDirection() const
{
    return this->direction;
}

std::string AbstractEntity::getId() const
{
    return this->id;
}

int AbstractEntity::getX() const
{
    return this->x;
}

int AbstractEntity::getY() const
{
    return this->y;
}

bool AbstractEntity::isCanMove() const
{
    return this->canMove;
}

bool AbstractEntity::isMoving() const
{
    return this->moving;
}

bool AbstractEntity::isSolid() const
{
    return this->solid;
}

void AbstractEntity::render() const
{
   //TODO also user color
    std::cout << this->symbol;
}

void AbstractEntity::setCanMove(bool canMove)
{
   this->canMove = canMove;
}

void AbstractEntity::setColor(int color)
{
   this->color = color;
}

void AbstractEntity::setDirection(int direction)
{
   this->direction = direction;
}

void AbstractEntity::setId(std::string newId)
{
   this->id = newId;
}

void AbstractEntity::setMoving(bool moving)
{
   this->moving = moving;
}

void AbstractEntity::setSolid(bool solid)
{
   this->solid = solid;
}

void AbstractEntity::setX(int x)
{
   this->x = x;
}

void AbstractEntity::setY(int y)
{
   this->y = y;
}

void AbstractEntity::setSymbol(char symbol){
    this->symbol = symbol;
}

void update()
{
    //TODO
}
