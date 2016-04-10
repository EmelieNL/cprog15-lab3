#ifndef MAP_H
#define MAP_H
#include "blocked.h"

class Map
{
private:
    int widthX;
    int heightY;
    AbstractEntity* map[10][10]; //the map data

    int playerX;
    int playerY;

public:
    Map();
    Map(int widthX, int heightY);

    void initMap();
    AbstractEntity* get(int x, int y);
    void set(int x, int y, AbstractEntity *obj);
    void render() const;
    void clear() const;
};

#endif // MAP_H
