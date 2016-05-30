#include "terrain.h"
#include "creature.h"

Terrain::Terrain(Terrain::Type terrainType) {
    setTerrain(terrainType);
}

void Terrain::setTerrain(Terrain::Type terrainType) {
    type = terrainType;
}

Terrain::Type Terrain::getType() {
    return type;
}

bool Terrain::isSolid() const
{
    switch(type)
    {
    case Type::WATER:
        return false;
    case Type::SAND:
        return true;
    case Type::FORREST:
        return true;
    case Type::MOUNTAIN:
        return true;

    }
    return false;
}

char Terrain::getSymbol() {
    switch(type)
    {
    case Type::WATER:
        return '~';
    case Type::SAND:
        return ':';
    case Type::FORREST:
        return '^';
    case Type::MOUNTAIN:
        return 'V';

    }
    return '?';
}

conmanip::console_bg_colors Terrain::getBGcolor(){
    switch(type)
    {
    case Type::WATER:
        return conmanip::console_bg_colors::blue;
    case Type::SAND:
        return conmanip::console_bg_colors::yellow;
    case Type::FORREST:
        return conmanip::console_bg_colors::green;
    case Type::MOUNTAIN:
        return conmanip::console_bg_colors::black;
    }
    return conmanip::console_bg_colors::black;
}


conmanip::console_text_colors Terrain::getTextcolor() {
    switch(type)
    {
    case Type::WATER:
        return conmanip::console_text_colors::cyan;
    case Type::SAND:
        return conmanip::console_text_colors::light_yellow;
    case Type::FORREST:
        return conmanip::console_text_colors::light_green;
    case Type::MOUNTAIN:
        return conmanip::console_text_colors::white;
    }
    return conmanip::console_text_colors::white;
}

std::string Terrain::getDesc() const
{
    switch(type)
    {
    case Type::WATER:
        return "You are now swimming and are freezing!";
    case Type::SAND:
       return "You walk on warm sand";
    case Type::FORREST:
        return "You enter a forest";
    case Type::MOUNTAIN:
        return "You climb the mountain";
    default:
        return "You enter unfamiliar terrain";
    }
}

void Terrain::effect(Creature *creature)
{
    switch(type)
    {
    case Type::WATER:
        creature->changeHealth(-1);
        break;
    case Type::SAND:
        break;
    case Type::FORREST:
        break;
    case Type::MOUNTAIN:
        break;
    }

}

