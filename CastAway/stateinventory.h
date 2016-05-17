#ifndef STATEINVENTORY_H
#define STATEINVENTORY_H

#include "gamestate.h"
#include "menuoption.h"
#include "inventory.h"

class StateInventory:public GameState, public MenuOption
{
public:
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

    //Get static
    static StateInventory* instance(){
        return &inventoryState;
    }

private:
    static StateInventory inventoryState;

    int menuOption;
};

#endif // STATEINVENTORY_H
