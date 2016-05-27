#ifndef FISH_H
#define FISH_H

#include "creature.h"

//Represent a fish creature that can only move in water terrain
class Fish:public Creature
{
public:
    Fish();
    Fish(char symbol);
    void moveX(int x);
    void moveY(int y);
};

#endif // FISH_H
