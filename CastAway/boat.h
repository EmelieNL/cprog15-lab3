#ifndef BOAT_H
#define BOAT_H

#include "item.h"

class Boat:public Item
{
public:
    Boat(std::string id, int weight, char symbol);
};

#endif // BOAT_H
