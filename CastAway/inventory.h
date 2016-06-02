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
    Item* getAndRemoveItem(unsigned int i);  //Get a item and remove from vector
    Item* getItem(unsigned int i);          //Get a specific item by index
    Item* getItem(std::string id);          //Get a specific item by id
    int getInventorySize() const;           //Get total # of items in this inventory
    bool isFull() const;                    //Is the inventory full regarding weight capacity?
    const std::vector<Item*>& getItems() const;    //Get a list of all items
    int getMaxWeight() const;
    int getWeight() const;

    void setMaxWeight(int value);

private:
    std::vector<Item*> items; //items in this inventory
    int maxWeight; //max weight this inventory can hold
    void init(int newMaxWeight);
};

#endif // INVENTORY_H
