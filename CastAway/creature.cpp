#include "creature.h"
#include "player.h"
#include "inventory.h"
#include "weapon.h"


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
    //delete inventory;
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
    if(getHealth() > 0)
        return true;
    else
        return false;
}

void Creature::moveX(int x)
{
    int newX = getX() + x;
    int newY = getY();

    //Can this creature move at all?
    if(isCanMove()){

        //check map boundaries in x
        if(newX < 0 || newX >= Engine::Instance().getMap()->getWidth()){
            return;

        //is there anyting blocking?
        } else if(Engine::Instance().getMap()->isBlocked(newX, newY)){
             action(newX, newY);
            return;
        } else {
            //Remove creature from map tile
            Engine::Instance().getMap()->getTile(getX(), getY())->setAbsEntity(nullptr);

            //Update the creatures position
            setX(newX);

            //Add creatre to map tile
            Engine::Instance().getMap()->getTile(newX, newY)->setAbsEntity(this);
        }
    }
}

void Creature::moveY(int y)
{
    int newX = getX();
    int newY = getY() + y;

    //Can this creature move at all?
    if(isCanMove()){
        //check map boundaries in y
        if(newY < 0 || newY >= Engine::Instance().getMap()->getHeight()){
            return;

        //is there anything blocking?
       } else if(Engine::Instance().getMap()->isBlocked(newX, newY)){
            action(newX, newY);
            return;

        } else {

            //Remove creature from map tile
            Engine::Instance().getMap()->getTile(getX(), getY())->setAbsEntity(nullptr);

            //Update the creatures position
            setY(newY);

            //Add creatre to map tile
            Engine::Instance().getMap()->getTile(newX, newY)->setAbsEntity(this);
        }
    }
}

void Creature::update()
{
    //Check if the creature is still alive
    if(!isAlive()){

        bool dropItem = false;
         Item* item;
        //Drop the first item in inventory on the map if possible
        //if the creature have something in the inventory
        //if(getInventory()->getInventorySize() > 0){
         if(false){
            //Get the item from inventory
            item = getInventory()->getAndRemoveItem(0);
            item->setX(getX());
            item->setY(getY());

            dropItem = true;
            //Wait to add item to the map until this creature is removed...
        }

        //Remove from the map...
        Engine::Instance().getMap()->removeAbstractEntity(dynamic_cast<AbstractEntity*>(this));

        if(dropItem){
             Engine::Instance().getMap()->addAbstractEntity(item->getX(), item->getY(), item);
        }

        //This might not exactly be the cleanest solution...
        delete this;

        return;
    }

    //Movement for hostile creatures if player is close
    float xDist =  Engine::Instance().getPlayer()->getX() - getX();
    float yDist =  Engine::Instance().getPlayer()->getY() - getY();
    float distance = std::sqrt((xDist*xDist) + (yDist*yDist)); //hypotenuse

    //If the player is close enough, move towards player
    if(isHostile() && distance < 6){

        //Random chance that the creature will not move
        int random = rand() % 100;
        if(random > 50)
            return;

        //Normalize
        xDist /= distance;
        yDist /= distance;

        //creature is directly below player
        if(xDist == 0 && yDist == -1){
            moveY(-1);
        //creature is directly above player
        } else if(xDist == 0 && yDist == 1){
            moveY(1);
        //creature is directly left of player
        } else if(xDist == 1 && yDist == 0){
            moveX(1);
        //creature is directly right of player
        } else if(xDist == -1 && yDist == 0){
            moveX(-1);
        //Diagonal, choose a direction
        //Player is not 4th quadrant compared to the creature
        } else if(xDist > 0 && yDist>0){
            if(xDist < yDist){
                moveY(1);
            } else {
                moveX(1);
            }
        //Player is in 1th quadrant compared to the creature
        } else if(xDist > 0 && yDist<0){
            if(xDist < std::abs(yDist)){
                moveY(-1);
            } else {
                moveX(1);
            }
        //Player is in 2th quadrant compared to the creature
        } else if(xDist < 0 && yDist<0){
            if(xDist < yDist){
                moveY(-1);
            } else {
                moveX(-1);
            }
        //Player is in 3th quadrant compared to the creature
        } else if(xDist < 0 && yDist>0){
            if(std::abs(xDist) < yDist){
                moveY(1);
            } else {
                moveX(-1);
            }
        }

        //Allow the creature the option to attack the player, as it will not be able to catch up anytime
        /*xDist =  Engine::Instance().getPlayer()->getX() - getX();
        yDist =  Engine::Instance().getPlayer()->getY() - getY();
        distance = std::sqrt((xDist*xDist) + (yDist*yDist)); //hypotenuse
        if(distance < 2)
            attack(Engine::Instance().getPlayer());
        */
        return;
    }

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

Inventory* Creature::getInventory()
{
    return &inventory;
}

//void Creature::setInventory(Inventory *inventory)
//{
//    this->inventory = inventory;
//}

void Creature::action(int x, int y)
{
    //Get the entity at x and y
    Tile* tile = Engine::Instance().getMap()->getTile(x, y);
    AbstractEntity* blocking = tile->getAbsEntity();

    //Is this creature hostile?
    if(isHostile()){
        //If we hit the player, attack it
        if(Player* enemy = dynamic_cast<Player*>(blocking)) {
            attack(enemy);
        }
    }
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

int Creature::getAttackDamage() const
{
    //Do this creature have a weapon?
    if(getWeapon() == nullptr){
        return basicAttack;
    } else {
        return getWeapon()->getAttackValue();
    }

}

int Creature::attack(Creature *enemy)
{
    int randomDamage = rand() % getAttackDamage() + 1; //1 to maxDamage

    //If we hit the player, log it to the player
    if(Player* player = dynamic_cast<Player*>(enemy)) {
       player->addLog(getId() + " attacked you with " + std::to_string(randomDamage) + " damage!");
    }

    enemy->changeHealth(-randomDamage);
    return randomDamage;
}

bool Creature::isHostile() const
{
    return hostile;
}

void Creature::setHostile(bool value)
{
    hostile = value;
}

void Creature::init(char symbol)
{
    /* initialize random seed: */
    srand (time(NULL));

    setMaxHealth(100);
    setHealth(100);
    setSymbol(symbol);
    setBasicAttack(10);
    setFgColor(conmanip::console_text_colors::yellow);
    setBgColor(conmanip::console_bg_colors::black);
    setX(0);
    setY(0);
    setCanMove(true);
    setId("Creature");
    //setInventory(new Inventory());
    setWeapon(nullptr);
    setHostile(true);
}
