#ifndef MAP_H
#define MAP_H
#include <string>

#include "blocked.h"

class Map
{
private:
    // Set map size
    static const int widthX = 70;
    static const int heightY = 20;

    AbstractEntity* map[heightY][widthX]; //the map data

    int playerX;
    int playerY;

public:
    // Setting of map size from outside not supported at the moment
    Map(/*int widthX, int heightY*/);

    void initMap();
    AbstractEntity* get(int x, int y);
    void set(int x, int y, AbstractEntity *obj);
    void render() const;
    void clear() const;
};

#endif // MAP_H
