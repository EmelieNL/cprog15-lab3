#include "item.h"

Item::Item(std::string id, int weight, char symbol)
{
    Item(id, weight, symbol, false, 1, 1);
}

Item::Item(std::string id, int weight, char symbol, bool canStack, int maxStack, int stackAmount)
{
    this->setId(id);
    this->setWeight(weight);
    this->setSymbol(symbol);
    this->setCanStack(canStack);
    this->setMaxStack(maxStack);
    this->setStackAmount(stackAmount);

    this->setCanMove(false);

}

bool Item::getCanStack() const
{
    return canStack;
}

void Item::setCanStack(bool canStack)
{
    canStack = canStack;
}

int Item::getMaxStack() const
{
    return maxStack;
}

void Item::setMaxStack(bool maxStack)
{
   this->maxStack = maxStack;
}

int Item::getStackAmount() const
{
    return stackAmount;
}

void Item::setStackAmount(int amount)
{
    this->stackAmount = amount;
}

int Item::getWeight() const
{
    return weight;
}

void Item::setWeight(int weight)
{
    weight = weight;
}

void Item::update()
{

}
