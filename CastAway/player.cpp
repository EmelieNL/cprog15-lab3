#include "player.h"

Player::Player()
{
    setSymbol('@');

    setFgColor(conmanip::console_text_colors::light_yellow);
    setBgColor(conmanip::console_bg_colors::black);

}

void Player::addLog(std::string message)
{
    log.insert(log.begin(), message); //Add message to first position

    //Only store 10 messages
    if(log.size() > 10)
        log.pop_back(); //remove last message
}

std::vector<std::string> Player::getLog() const
{
    return log;
}

void Player::moveX(int x)
{
    int newX = getX() + x;
    int newY = getY();

    //Can this creature move at all?
    if(isCanMove()){

         //check map boundaries in x
        if(newX < 0 || newX >= Engine::Instance().getMap()->getWidth()){
              return;

        //is there anyting blocking?
        }else if(Engine::Instance().getMap()->isBlocked(newX, newY)){
            action(newX, newY);
            return;

        } else {

            //Remove creature from map tile
            Engine::Instance().getMap()->getTile(getX(), getY())->setAbsEntity(nullptr);

            //Update the creatures position
            setX(newX);

            //Add creatre to map tile
            Engine::Instance().getMap()->getTile(getX(), getY())->setAbsEntity(this);
        }
    }
}

void Player::moveY(int y)
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
            Engine::Instance().getMap()->getTile(getX(), getY())->setAbsEntity(this);
        }
    }
}

void Player::action(int x, int y)
{
    //Get the entity at x and y
    Tile* tile = Engine::Instance().getMap()->getTile(x, y);
    AbstractEntity* blocking = tile->getAbsEntity();

    //If we hit a item, try to pick it up
    if(Item* item = dynamic_cast<Item*>(blocking)) {
        if(this->getInventory()->addItem(item)){
            Engine::Instance().getMap()->removeAbstractEntity(blocking);
            this->addLog("You picked up a " + item->getId());

         //could not pick up item
        } else {
             this->addLog("You see a " + item->getId() + " but can't pick it up!");
        }
    } else {
        this->addLog("You bumped in to a " + blocking->getId());
    }
}

void Player::update()
{
    //Dont update anything, the player controls input for this creature
}
