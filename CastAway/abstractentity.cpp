#include <iostream>
#include "abstractentity.h"
#include "conmanip.h"
#include "render.h"

using namespace std;
using namespace conmanip;

conmanip::console_bg_colors AbstractEntity::getBgColor() const
{
    return this->bgColor;
}

console_text_colors AbstractEntity::getFgColor() const
{
    return this->fgColor;
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

void AbstractEntity::render() const
{
   Render::printSymbol(symbol, getFgColor(), getBgColor());
   Render::printSymbol(char(32), getFgColor(), getBgColor());
}

void AbstractEntity::setCanMove(bool canMove)
{
   this->canMove = canMove;
}

void AbstractEntity::setBgColor(conmanip::console_bg_colors color)
{
    this->bgColor = color;
}

void AbstractEntity::setFgColor(console_text_colors color)
{
    this->fgColor = color;
}

void AbstractEntity::setId(std::string newId)
{
   this->id = newId;
}

void AbstractEntity::setX(int x)
{
   this->x = x;
}

void AbstractEntity::setY(int y)
{
   this->y = y;
}

void AbstractEntity::update()
{

}

void AbstractEntity::setSymbol(char symbol){
    this->symbol = symbol;
}

