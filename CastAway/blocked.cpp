#include "blocked.h"
#include "conmanip.h"
#include "render.h"

using namespace conmanip;

Blocked::Blocked(){
    init('#');
}

Blocked::Blocked(char symbol)
{
    init(symbol);
}

void Blocked::update()
{

}

void Blocked::init(char symbol)
{
    setSymbol(symbol);
    setSolid(true);
    setFgColor(conmanip::console_text_colors::white);
    setBgColor(conmanip::console_bg_colors::black);
    setCanMove(false);
    setId("Wall");
    setX(0);
    setY(0);
}


