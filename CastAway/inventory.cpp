#include "inventory.h"

Inventory::Inventory()
{
    init(1000);
}

Inventory::Inventory(int maxWeight)
{
    init(maxWeight);
}

Inventory::~Inventory()
{
  //TODO delete all items
}

void Inventory::addItem(Item *item)
{
    //TODO check if this item can be stacked
    if(!isFull()){
        items.push_back(item);
    }
}

void Inventory::removeItem(Item *item)
{
    items.erase(std::remove(items.begin(), items.end(), item), items.end());
}

Item *Inventory::getItem(int i) const
{
    if(items.size() > i-1){
        return items[i];
    } else {
        return nullptr;
    }
}

int Inventory::getInventorySize() const
{
    return items.size();
}

bool Inventory::isFull() const
{
    int totalWeight = 0;
    for (std::vector<Item*>::const_iterator it = items.begin() ; it != items.end(); ++it){
        totalWeight += (*it)->getWeight();
    }

    if(totalWeight >getMaxWeight()){
        return true;
    } else {
        return false;
    }
}

std::vector<Item *> Inventory::getItems() const
{
    return items;
}

int Inventory::getMaxWeight() const
{
    return maxWeight;
}

int Inventory::getWeight() const
{
    int totalWeight = 0;
    for (std::vector<Item*>::const_iterator it = items.begin() ; it != items.end(); ++it){
        totalWeight += (*it)->getWeight();
    }

    return totalWeight;

}

void Inventory::init(int maxWeight)
{
    this->maxWeight = maxWeight;
}
