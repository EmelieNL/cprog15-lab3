#ifndef TERRAIN_H
#define TERRAIN_H
#include "conmanip.h"

/* Class to represent different terrains that a tile can have */
class Terrain
{
public:
    // Strict enum to represent different terrains
    enum class Type {WATER, SAND, FORREST, MOUNTAIN};

    Terrain() {}
    Terrain(Terrain::Type terrainType);
    void setTerrain(Terrain::Type terrainType);
    Terrain::Type getType();
    char getSymbol();
    conmanip::console_bg_colors getBGcolor();
    conmanip::console_text_colors getTextcolor();
    std::string getDesc() const;

private:
    Type type;
    char symbol;
};

#endif // TERRAIN_H
