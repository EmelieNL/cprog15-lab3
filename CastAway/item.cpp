#include "item.h"

Item::Item(std::string id, int weight, char symbol)
{
    init(id, weight, symbol, false, 1, 1);
}

Item::Item(std::string id, int weight, char symbol, bool canStack, int maxStack, int stackAmount)
{
    init(id, weight, symbol, canStack, maxStack, stackAmount);
}

bool Item::getCanStack() const
{
    return canStack;
}

void Item::setCanStack(bool canStack)
{
    this->canStack = canStack;
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
    this->weight = weight;
}

void Item::update()
{

}

void Item::init(std::string id, int weight, char symbol, bool canStack, int maxStack, int stackAmount)
{
    this->setId(id);
    this->setWeight(weight);
    this->setSymbol(symbol);
    this->setCanStack(canStack);
    this->setMaxStack(maxStack);
    this->setStackAmount(stackAmount);
    this->setSolid(true);
    this->setCanMove(false);

    setFgColor(conmanip::console_text_colors::white);
    setBgColor(conmanip::console_bg_colors::black);
}
