#ifndef MAP_H
#define MAP_H
#include <string>

#include "blocked.h"
#include "terrain.h"

class Map
{
public:
    Map();

    // Struct to represent a singel tile in map
    struct Tile {
      AbstractEntity absEntity;
      Terrain terrain;
      //TODO e.g. Creature creature;
    };

    void initMap();
    Tile getTile(int x, int y);
    void setTerrain(int x, int y, Terrain::Type terrainType);
    void setAbstractEntity(int x, int y, AbstractEntity absEntity);
    void render() const;
    void clear() const;

private:
    // Set map size
    static const int widthX = 70;
    static const int heightY = 20;


    int playerX;
    int playerY;
};

#endif // MAP_H
