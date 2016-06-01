#include "tree.h"
#include "board.h"

Tree::Tree()
{
    setSymbol('T');
    setFgColor(conmanip::console_text_colors::light_green);
    setBgColor(conmanip::console_bg_colors::black);
    setX(0);
    setY(0);
    setCanMove(false);
    setId("Tree");
}

bool Tree::chopDown()
{

    int x = getX();
    int y = getY();

    //Remove from the map...
    Engine::Instance().getMap()->removeAbstractEntity(dynamic_cast<AbstractEntity*>(this));

    //Add some boards
    Board* boards = new Board("Wooden board", 250, 'B', true, 64, 5);
    boards->setX(x);
    boards->setY(y);

    Engine::Instance().getMap()->getTile(boards->getX(), boards->getY())->setAbsEntity(boards);

    return true;

}

void Tree::update()
{

}
