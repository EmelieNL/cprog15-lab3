#include "menuoption.h"

void MenuOption::initMenuOption(int max)
{
    currentMenuOption=0;
    this->maxMenuOption = max;
}

void MenuOption::increaseMenuOption()
{
    if(currentMenuOption+1<=maxMenuOption)
        currentMenuOption++;
}

void MenuOption::decreaseMenuOption()
{
    if(currentMenuOption-1>=0)
        currentMenuOption--;
}

void MenuOption::setMaxMenuOption(int max)
{
    this->maxMenuOption = max;
}

void MenuOption::setCurrentMenuOption(int curr)
{
    this->currentMenuOption = curr;
}

int MenuOption::getCurrentMenuOption() const
{
    return currentMenuOption;
}
