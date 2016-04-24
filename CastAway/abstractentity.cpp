#include <iostream>
#include "abstractentity.h"
#include "conmanip.h"
#include "render.h"

using namespace std;
using namespace conmanip;

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
   Render::printSymbol(symbol, console_text_colors::cyan, console_bg_colors::blue);
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

