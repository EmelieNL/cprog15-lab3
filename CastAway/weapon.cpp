#include "weapon.h"

Weapon::Weapon(std::string id, int weight, char symbol, int attackValue):
    Item(id, weight, symbol)
{
    this->attackValue = attackValue;
}

int Weapon::getAttackValue() const
{
    return attackValue;
}

void Weapon::setAttackValue(int value)
{
    attackValue = value;
}
