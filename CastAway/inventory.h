#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include <algorithm>
#include "item.h";

class Inventory
{
public:
    Inventory();
    void addItem(Item* item);               //Add item to this inventory
    void removeItem(Item* item);            //Remove an item from inventory
    Item* getItem(int i) const;             //Get a specific item by index
    int getInventorySize() const;           //Get total # of items in this inventory
    bool isFull() const;                    //Is the inventory full regarding weight capacity?
    std::vector<Item*> getItems() const;    //Get a list of all items
    int getMaxWeight() const;

private:
    std::vector<Item*> items; //items in this inventory
    int maxWeight; //max weight this inventory can hold
};

#endif // INVENTORY_H
