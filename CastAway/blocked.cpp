#include "blocked.h"

Blocked::Blocked(){

}

Blocked::Blocked(char symbol)
{
    setSymbol(symbol);
    setSolid(true);
}

Blocked::Blocked(char symbol,int x, int y)
{
    setX(x);
    setY(y);
    setSymbol(symbol);
    setSolid(true);
}


