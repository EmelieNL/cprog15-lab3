#include "blocked.h"
#include "conmanip.h"
#include "render.h"

using namespace conmanip;

Blocked::Blocked(){
    setSolid(true);
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

void Blocked::render() const
{
   Render::printSymbol(symbol, console_text_colors::green, console_bg_colors::black);
}


