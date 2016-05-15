#ifndef MAP_H
#define MAP_H
#include <string>

#include "blocked.h"
#include "terrain.h"
#include "tile.h"

class Map
{
public:
    Map();
    ~Map();

    void initMap();
    Tile* getTile(int x, int y);
    void setTerrain(int x, int y, Terrain::Type terrainType);
    void setAbstractEntity(int x, int y, AbstractEntity absEntity);
    void render() const;
    void clear() const;
    bool isBlocked(int x, int y);

private:
    // Set map size
    static const int widthX = 70;
    static const int heightY = 20;

    Tile* map[heightY][widthX];

    int playerX;
    int playerY;
};

#endif // MAP_H
