#ifndef ITEM_H
#define ITEM_H
#include "abstractentity.h"

class Item:public AbstractEntity
{
public:
    Item();
    Item(std::string id, int weight, char symbol);
    Item(std::string id, bool canStack, int maxStack, int stackAmount, int weight);

    bool getCanStack() const;
    int getMaxStack() const;
    int getStackAmount() const;
    int getWeight() const;

    virtual void update() override;

private:
    bool canStack; //If this item can be stacked in an inventory
    int maxStack; //max size of a stack of this item, if it can be stacked
    int stackAmount; //amount of items in this stack
    int weight; //item weight in grams
};

#endif // ITEM_H
