#ifndef BLOCKED_H
#define BLOCKED_H
#include "abstractentity.h"


class Blocked:public AbstractEntity
{
public:
    Blocked();
    Blocked(char symbol);
    Blocked(char symbol, int x, int y);

    virtual void update() override;
};

#endif // BLOCKED_H
