#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"

class Weapon:public Item
{
public:
     Weapon(std::string id, int weight, char symbol, int attackValue);
     int getAttackValue() const;
     void setAttackValue(int value);

private:
     int attackValue;
};

#endif // WEAPON_H
