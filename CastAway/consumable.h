#ifndef CONSUMABLE_H
#define CONSUMABLE_H
#include "item.h"

class Consumable:public Item
{
public:
    Consumable(std::string id, int weight, char symbol, int health);
    Consumable(std::string id, int weight, char symbol, int health, bool canStack, int maxStack, int stackAmount);
    int getHealthValue() const;
    void setHealthValue(int health);

private:
    int healthValue;

};

#endif // CONSUMABLE_H
