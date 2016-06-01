#ifndef TREE_H
#define TREE_H

#include "abstractentity.h"
#include "tile.h"
#include "engine.h"

class Tree:public AbstractEntity
{
public:
    Tree();
    bool chopDown();
    virtual void update() override;
private:
    bool canChopdown;
};

#endif // TREE_H
