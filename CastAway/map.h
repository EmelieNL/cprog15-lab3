#ifndef MAP_H
#define MAP_H
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include "terrain.h"

// Forward declare
class AbstractEntity;
class Tile;

class Map
{
public:
    Map();
    ~Map();

    void initMap();
    Tile* getTile(int x, int y);
    void setTerrain(int x, int y, Terrain::Type terrainType);
    void addAbstractEntity(int x, int y, AbstractEntity* absEntity);
    void removeAbstractEntity(AbstractEntity* absEntity);
    void render() const;
    void update();
    void clear() const;
    bool isBlocked(int x, int y);
    int getWidth() const;
    int getHeight() const;

private:
    // Set map size
    static const int widthX = 70;
    static const int heightY = 20;

    Tile* map[heightY][widthX];
    std::vector<AbstractEntity*> entities; //entities in this map
};

#endif // MAP_H
