#ifndef TILE_H
#define TILE_H
#include "blocked.h"
#include "terrain.h"

class Tile
{

private:
    AbstractEntity* absEntity;
    Terrain* terrain;
    bool explored;

public:
    Tile();
    ~Tile();
    AbstractEntity* getAbsEntity();
    Terrain* getTerrain();
    void setAbsEntity(AbstractEntity* absEntity);
    void setTerrain(Terrain::Type terrainType);
    void setExplored();
    bool isExplored() const;
};

#endif // TILE_H
