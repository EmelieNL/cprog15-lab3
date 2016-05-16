#ifndef CREATURE_H
#define CREATURE_H
#include "abstractentity.h"
#include "tile.h"
#include "map.h"
#include "engine.h"
#include "inventory.h"

class Creature:public AbstractEntity
{
public:
    Creature();
    Creature(char symbol);
    Creature(char symbol, int x, int y);
    ~Creature();
    void setHealth(int health);
    int getHealth() const;
    void changeHealth(int healthChange);
    bool isAlive() const;
    void moveX(int x);
    void moveY(int y);
    virtual void update() override;
    Inventory* getInventory() const;
    void setInventory(Inventory* inventory);

private:
    int health;
    Inventory* inventory;
};

#endif // CREATURE_H
