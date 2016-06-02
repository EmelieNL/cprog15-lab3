#ifndef ITEM_H
#define ITEM_H
#include "abstractentity.h"

class Item:public AbstractEntity
{
public:
    Item(std::string id, int weight, char symbol);
    Item(std::string id, int weight, char symbol, bool canStack, int maxStack, int stackAmount);

    virtual ~Item() {}
    bool getCanStack() const;
    void setCanStack(bool canStack);
    int getMaxStack() const;
    void setMaxStack(int maxStack);
    int getStackAmount() const;
    void setStackAmount(int amount);
    int getWeight() const;
    void setWeight(int weight);

    virtual void update() override;

private:
    bool canStack; //If this item can be stacked in an inventory
    int maxStack; //max size of a stack of this item, if it can be stacked
    int stackAmount; //amount of items in this stack
    int weight; //item weight in grams
    void init(std::string id, int weight, char symbol, bool canStack, int maxStack, int stackAmount);
};

#endif // ITEM_H
