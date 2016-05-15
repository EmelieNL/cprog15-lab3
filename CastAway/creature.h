#ifndef CREATURE_H
#define CREATURE_H
#include "abstractentity.h"
#include "tile.h"

class Creature:AbstractEntity
{
public:
    Creature();
    Creature(char symbol);
    Creature(char symbol, int x, int y);
    void setHealth(int health);
    int getHealth() const;
    void changeHealth(int healthChange);
    bool isAlive() const;
    void moveX(int x);
    void moveY(int y);
    virtual void update() override;

private:
    int health;
};

#endif // CREATURE_H
