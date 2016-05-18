#include "player.h"

Player::Player()
{
    setSymbol('@');

    setFgColor(conmanip::console_text_colors::light_yellow);
    setBgColor(conmanip::console_bg_colors::black);

}

void Player::addLog(std::string message)
{
    log.insert(log.begin(), message); //Add message to first position

    //Only store 10 messages
    if(log.size() > 10)
        log.pop_back(); //remove last message
}

std::vector<std::string> Player::getLog() const
{
    return log;
}
