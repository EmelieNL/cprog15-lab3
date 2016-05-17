#include "player.h"

Player::Player()
{
    setSymbol('@');

    setFgColor(conmanip::console_text_colors::light_yellow);
    setBgColor(conmanip::console_bg_colors::black);

}
