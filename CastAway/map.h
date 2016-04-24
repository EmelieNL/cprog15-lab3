#ifndef MAP_H
#define MAP_H
#include <string>


class Map
{
private:
    int widthX;
    int heightY;
    int map[20][50]; //the map data

    int playerX;
    int playerY;

public:
    Map(int widthX, int heightY);

    void initMap();
    int get(int x, int y);
    void set(int x, int y, int obj);
    void render();
    void clear();
    int getPlayerX();
    int getPlayerY();
};

#endif // MAP_H
