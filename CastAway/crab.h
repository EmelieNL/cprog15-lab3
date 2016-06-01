#ifndef CRAB_H
#define CRAB_H
#include "creature.h"

//Represent a crab creature that can only move on sand terrain
class Crab:public Creature
{
public:
    Crab();
    Crab(char symbol);
    void moveX(int x);
    void moveY(int y);
};

#endif // CRAB_H
