#include "consumable.h"



Consumable::Consumable(std::string id, int weight, char symbol, int health):
    Item(id, weight, symbol)
{
    this->healthValue = health;
}

Consumable::Consumable(std::string id, int weight, char symbol, int health, bool canStack, int maxStack, int stackAmount):
    Item(id, weight, symbol, canStack, maxStack, stackAmount)
{
    this->healthValue = health;
}

int Consumable::getHealthValue() const
{
    return healthValue;
}

void Consumable::setHealthValue(int health)
{
    this->healthValue = health;
}
