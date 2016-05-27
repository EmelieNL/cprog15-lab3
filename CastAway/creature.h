#ifndef CREATURE_H
#define CREATURE_H
#include <stdlib.h> //random for movement
#include <time.h> //for random seed
#include "abstractentity.h"
#include "tile.h"
#include "map.h"
#include "engine.h"
#include "inventory.h"
#include "weapon.h"

class Creature:public AbstractEntity
{
public:
    Creature();
    Creature(char symbol);
    ~Creature();
    void setHealth(int health);
    void setMaxHealth(int maxHealth);
    int getHealth() const;
    void changeHealth(int healthChange);
    bool isAlive() const;
    virtual void moveX(int x);
    virtual void moveY(int y);
    virtual void update() override;
    Inventory* getInventory() const;
    void setInventory(Inventory* inventory);
    virtual void action(int x, int y);


    Weapon *getWeapon() const;
    void setWeapon(Weapon *value);

    int getBasicAttack() const;
    void setBasicAttack(int value);

    int getAttackDamage() const;
    int attack(Creature* enemy);

    bool isHostile() const;
    void setHostile(bool value);
    void init(char symbol);

private:
    int health;
    int maxHealth;
    int basicAttack;
    bool hostile;
    Weapon* weapon;
    Inventory* inventory;

};

#endif // CREATURE_H
