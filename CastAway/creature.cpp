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

        //is there anyting blocking?
        if(Engine::Instance().getMap()->isBlocked(getX() + x, getY())){

            AbstractEntity* blocking = Engine::Instance().getMap()->getTile(getX() + x, getY())->getAbsEntity();
            //If this is the player
            if(Player* p = dynamic_cast<Player*>(this)) {
               // old was safely casted to NewType
               p->addLog("You bumped in to a " + blocking->getId());
            }
            return;

        //check map boundaries in x
        } else if((getX() + x) < 0 || (getX() + x ) >= Engine::Instance().getMap()->getWidth()){
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

        //is there anything blocking?
        if(Engine::Instance().getMap()->isBlocked(getX(), getY() + y)){
            return;

        //check map boundaries in y
        } else if((getY() + y) < 0 || (getY() + y ) >= Engine::Instance().getMap()->getHeight()){
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

}

Inventory *Creature::getInventory() const
{
    return inventory;
}

void Creature::setInventory(Inventory *inventory)
{
    this->inventory = inventory;
}

void Creature::init(char symbol)
{
    setHealth(100);
    setSymbol(symbol);
    setSolid(true);
    setFgColor(conmanip::console_text_colors::yellow);
    setBgColor(conmanip::console_bg_colors::black);
    setX(0);
    setY(0);
    setCanMove(true);
    setId("Creature");
    setInventory(new Inventory());
}
