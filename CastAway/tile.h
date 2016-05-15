#ifndef TILE_H
#define TILE_H
#include "blocked.h"
#include "terrain.h"

class Tile
{

private:
    AbstractEntity* absEntity;
    Terrain* terrain;

public:
    Tile();
    AbstractEntity* getAbsEntity();
    Terrain* getTerrain();
    void setAbsEntity(AbstractEntity* absEntity);
    void setTerrain(Terrain::Type terrainType);
};

#endif // TILE_H
