#include "tile.h"

Tile::Tile()
{
    absEntity = nullptr;
    terrain = new Terrain(Terrain::Type::WATER); //TODO desturctor
}

Tile::~Tile()
{
    delete absEntity;
}

AbstractEntity *Tile::getAbsEntity()
{
    return absEntity;
}

Terrain *Tile::getTerrain()
{
    return terrain;
}

void Tile::setAbsEntity(AbstractEntity *absEntity)
{
    this->absEntity = absEntity;
}

void Tile::setTerrain(Terrain::Type terrainType)
{
    this->terrain->setTerrain(terrainType);
}
