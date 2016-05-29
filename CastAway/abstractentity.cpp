#include <iostream>
#include "abstractentity.h"
#include "conmanip.h"
#include "render.h"

using namespace std;
using namespace conmanip;

conmanip::console_bg_colors AbstractEntity::getBgColor() const
{
    return bgColor;
}

console_text_colors AbstractEntity::getFgColor() const
{
    return fgColor;
}

std::string AbstractEntity::getId() const
{
    return id;
}

int AbstractEntity::getX() const
{
    return x;
}

int AbstractEntity::getY() const
{
    return y;
}

bool AbstractEntity::isCanMove() const
{
    return canMove;
}

void AbstractEntity::render() const
{
   Render::printSymbol(symbol, getFgColor(), getBgColor());
   Render::printSymbol(char(32), getFgColor(), getBgColor());
}

void AbstractEntity::setCanMove(bool newCanMove)
{
   canMove = newCanMove;
}

void AbstractEntity::setBgColor(conmanip::console_bg_colors color)
{
    bgColor = color;
}

void AbstractEntity::setFgColor(console_text_colors color)
{
    fgColor = color;
}

void AbstractEntity::setId(std::string newId)
{
   id = newId;
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

