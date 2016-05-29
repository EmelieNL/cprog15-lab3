#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include <algorithm>
#include "item.h"

class Inventory
{
public:
    Inventory();
    Inventory(int maxWeight);
    ~Inventory();
    bool addItem(Item* item);               //Add item to this inventory
    void removeItem(Item* item);            //Remove an item from inventory
    Item* getItem(unsigned int i);          //Get a specific item by index
    int getInventorySize() const;           //Get total # of items in this inventory
    bool isFull() const;                    //Is the inventory full regarding weight capacity?
    const std::vector<Item*>& getItems() const;    //Get a list of all items
    int getMaxWeight() const;
    int getWeight() const;

private:
    std::vector<Item*> items; //items in this inventory
    int maxWeight; //max weight this inventory can hold
    void init(int maxWeight);
};

#endif // INVENTORY_H
