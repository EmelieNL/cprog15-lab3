#include "item.h"

Item::Item()
{
    Item("New item", false, 1, 1, 1000);
}

Item::Item(std::string id, int weight, char symbol)
{
    Item(id, false, 1, 1, weight);
}

Item::Item(std::string id, bool canStack, int maxStack, int stackAmount, int weight)
{
    this->setId(id);
    this->canStack = canStack;
    this->maxStack = maxStack;
    this->stackAmount = stackAmount;
    this->weight = weight;

    this->setCanMove(false);

}

bool Item::getCanStack() const
{
    return canStack;
}

int Item::getMaxStack() const
{
    return maxStack;
}

int Item::getStackAmount() const
{
    return stackAmount;
}

int Item::getWeight() const
{
    return weight;
}
