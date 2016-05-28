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
    void moveX(int x);
    void moveY(int y);
    void action(int x, int y);
    void update() override;
    void updateTerrainData(int newX, int newY);

private:
     std::vector<std::string> log; //vector of log messanges
};

#endif // PLAYER_H
