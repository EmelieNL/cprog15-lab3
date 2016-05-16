#ifndef STATEINVENTORY_H
#define STATEINVENTORY_H

#include "gamestate.h"
#include "inventory.h"

class StateInventory:public GameState
{
public:
    void init();
    void update();
    void render();
    void handleInput();
    void clear();
    void printCommands();

    //Be able to pause states when we enter a new one
    void pause();
    void resume();

    //Get static
    static StateInventory* instance(){
        return &inventoryState;
    }

private:
    static StateInventory inventoryState;
    const std::vector<std::string> commands = {"Continue"};
};

#endif // STATEINVENTORY_H
