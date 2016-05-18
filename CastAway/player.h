#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "creature.h"

class Player:public Creature
{
public:
    Player();
    void addLog(std::string message);
    std::vector<std::string> getLog() const;
private:
     std::vector<std::string> log; //vector of log messanges
};

#endif // PLAYER_H
