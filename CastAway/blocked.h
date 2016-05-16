#ifndef BLOCKED_H
#define BLOCKED_H
#include "abstractentity.h"


class Blocked:public AbstractEntity
{
public:
    Blocked();
    Blocked(char symbol);

    virtual void update() override;

private:
    void init(char symbol);
};

#endif // BLOCKED_H
