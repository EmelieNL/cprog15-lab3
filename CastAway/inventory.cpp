#include "inventory.h"
#include <string>

Inventory::Inventory()
{
    init(1000);
}

Inventory::Inventory(int maxWeight)
{
    init(maxWeight);
}

// Delete all item ptrs in container, and clear container
Inventory::~Inventory()
{
  for (auto item : items) {
      delete item;
  }

  items.clear();
}

bool Inventory::addItem(Item* item)
{
    if(!isFull()){

        //Can the item be stacked?
        if(false){
            bool isStacked = false;
            //Check if the item type already exist and can be stacked
            for (const auto currItem : items){
                //Can the item stack, same id, and still room to stack?
                if(currItem->getCanStack() && currItem->getId().compare(item->getId()) == 0 && (currItem->getStackAmount() + item->getStackAmount()) <= currItem->getMaxStack()){
                   currItem->setStackAmount(currItem->getStackAmount() + item->getStackAmount());
                   delete item;
                   isStacked = true;
                   return true;
                }
            }

            //If the item could not be stacked, add normal
            if(!isStacked){
                items.push_back(item);
                return true;
            }
        }

        items.push_back(item);
        return true;
    }
    return false;
}

void Inventory::removeItem(Item* item)
{
    items.erase(std::remove(items.begin(), items.end(), item), items.end());
    delete item;
}

Item *Inventory::getAndRemoveItem(unsigned int i)
{
    Item* item = items[i];

    //Only remove the item from the vector, no delete
    items.erase(std::remove(items.begin(), items.end(), items[i]), items.end());

    return item;
}

Item* Inventory::getItem(unsigned int i)
{
    if(items.size()+1 > i){
        return items[i];
    } else {
        return nullptr;
    }
}

Item* Inventory::getItem(std::string id)
{
    for (const auto item : items){

        if(item->getId().compare(id) == 0){
          return item;
        }
    }
    return nullptr;
}

int Inventory::getInventorySize() const
{
    return items.size();
}

bool Inventory::isFull() const
{
    int totalWeight = getWeight();
    if(totalWeight >getMaxWeight()){
        return true;
    } else {
        return false;
    }
}

// Return reference, not a copy
const std::vector<Item*>& Inventory::getItems() const
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
    for (const auto item : items){
        if(item->getCanStack()){
           totalWeight += item->getWeight()*item->getStackAmount();
        } else {
           totalWeight += item->getWeight();
        }
    }
    return totalWeight;
}

void Inventory::setMaxWeight(int value)
{
    maxWeight = value;
}

void Inventory::init(int newMaxWeight)
{
    maxWeight = newMaxWeight;
}
