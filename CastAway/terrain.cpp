#include "terrain.h"

Terrain::Terrain(Terrain::Type terrainType) {
    setTerrain(terrainType);
}

void Terrain::setTerrain(Terrain::Type terrainType) {
    type = terrainType;
}

Terrain::Type Terrain::getType() {
    return type;
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

