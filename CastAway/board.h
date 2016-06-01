#ifndef BOARD_H
#define BOARD_H

#include "item.h"

//Class to represent boards made out of wood
class Board:public Item
{
public:
    Board(std::string id, int weight, char symbol, bool canStack, int maxStack, int stackAmount);
};

#endif // BOARD_H
