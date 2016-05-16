#include "player.h"

Player::Player()
{
    setSymbol('@');

    setFgColor(conmanip::console_text_colors::red);
    setBgColor(conmanip::console_bg_colors::black);

}
