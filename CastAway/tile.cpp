#include "tile.h"

Tile::Tile()
{
    absEntity = nullptr;
    terrain = new Terrain(Terrain::Type::WATER);
    explored = false;
}

Tile::~Tile()
{
    //delete absEntity;
    delete terrain;
}

AbstractEntity *Tile::getAbsEntity()
{
    return absEntity;
}

Terrain* Tile::getTerrain()
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

void Tile::setExplored()
{
    this->explored = true;
}

bool Tile::isExplored() const
{
    return explored;
}
