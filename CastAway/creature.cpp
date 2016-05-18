#include "creature.h"
#include "player.h"

Creature::Creature()
{
    init('C');
}

Creature::Creature(char symbol)
{
    init(symbol);
}

Creature::~Creature()
{

}

void Creature::setHealth(int health)
{
    this->health = health;

    //Dont go over maxHealth
    if(this->health > this->maxHealth){
        this->health = this->maxHealth;
    }
}

void Creature::setMaxHealth(int maxHealth)
{
    this->maxHealth = maxHealth;
}

int Creature::getHealth() const
{
    return health;
}

void Creature::changeHealth(int healthChange)
{
    setHealth(getHealth() + healthChange);
}

bool Creature::isAlive() const
{
    if(health > 0)
        return true;
    else
        return false;
}

void Creature::moveX(int x)
{
    //Can this creature move at all?
    if(isCanMove()){

        //check map boundaries in x
        if((getX() + x) < 0 || (getX() + x ) >= Engine::Instance().getMap()->getWidth()){
            return;

        //is there anyting blocking?
        } else if(Engine::Instance().getMap()->isBlocked(getX() + x, getY())){
            return;
        } else {
            //Remove creature from map tile
            Engine::Instance().getMap()->getTile(getX(), getY())->setAbsEntity(nullptr);

            //Update the creatures position
            setX(getX()+x);

            //Add creatre to map tile
            Engine::Instance().getMap()->getTile(getX(), getY())->setAbsEntity(this);
        }
    }
}

void Creature::moveY(int y)
{
    //Can this creature move at all?
    if(isCanMove()){
        //check map boundaries in y
        if((getY() + y) < 0 || (getY() + y ) >= Engine::Instance().getMap()->getHeight()){
            return;

        //is there anything blocking?
       } else if(Engine::Instance().getMap()->isBlocked(getX(), getY() + y)){
            return;

        } else {

            //Remove creature from map tile
            Engine::Instance().getMap()->getTile(getX(), getY())->setAbsEntity(nullptr);

            //Update the creatures position
            setY(getY()+y);

            //Add creatre to map tile
            Engine::Instance().getMap()->getTile(getX(), getY())->setAbsEntity(this);
        }
    }
}

void Creature::update()
{
    //Standard movment for a creature is random direction by one
    int direction = rand() % 4; //0, 1, 2, 3
    switch(direction){
        case 0: moveY(-1);
                break;
        case 1: moveY(1);
                break;
        case 2: moveX(-1);
                break;
        case 3: moveX(1);
                break;
    }

}

Inventory *Creature::getInventory() const
{
    return inventory;
}

void Creature::setInventory(Inventory *inventory)
{
    this->inventory = inventory;
}

void Creature::action(int x, int y)
{

}

Weapon *Creature::getWeapon() const
{
    return weapon;
}

void Creature::setWeapon(Weapon *value)
{
    weapon = value;
}

int Creature::getBasicAttack() const
{
    return basicAttack;
}

void Creature::setBasicAttack(int value)
{
    basicAttack = value;
}

void Creature::init(char symbol)
{
    /* initialize random seed: */
    srand (time(NULL));

    setHealth(100);
    setMaxHealth(100);
    setSymbol(symbol);
    setBasicAttack(10);
    setSolid(true);
    setFgColor(conmanip::console_text_colors::yellow);
    setBgColor(conmanip::console_bg_colors::black);
    setX(0);
    setY(0);
    setCanMove(true);
    setId("Creature");
    setInventory(new Inventory());
}
