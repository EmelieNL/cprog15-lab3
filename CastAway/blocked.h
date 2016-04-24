#ifndef BLOCKED_H
#define BLOCKED_H
#include "abstractentity.h"


class Blocked:public AbstractEntity
{
public:
    Blocked();
    Blocked(char symbol);
    Blocked(char symbol, int x, int y);

    void render() const override;
};

#endif // BLOCKED_H
