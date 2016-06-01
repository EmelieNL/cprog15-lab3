#ifndef AXE_H
#define AXE_H

#include "weapon.h"

class Axe:public Weapon
{
public:
    Axe(std::string id, int weight, char symbol, int attackValue);
};

#endif // AXE_H
