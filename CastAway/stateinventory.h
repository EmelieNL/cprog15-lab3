#ifndef STATEINVENTORY_H
#define STATEINVENTORY_H

#include "gamestate.h"
#include "menuoption.h"
#include "inventory.h"

class StateInventory:public IGameState, public MenuOption
{
public:
    // Assignment and copy constructors are deleted due to singelton
    StateInventory (const StateInventory&) = delete;
    void operator= (const StateInventory&) = delete;

    void init();
    void update();
    void render();
    void handleInput();
    void clear();
    void printCommands();
    void menuOptionAction();

    //Be able to pause states when we enter a new one
    void pause();
    void resume();

    // Get static instance
    static StateInventory& instance(){
        static StateInventory inventoryState;
        return inventoryState;
    }

protected:
    StateInventory() {}

private:
    int menuOption;
};

#endif // STATEINVENTORY_H
