#ifndef TERRAIN_H
#define TERRAIN_H
#include "conmanip.h"

class Creature; //Forward declaration of creature

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
    void effect(Creature* creature);          //Effect a creature that is in this terrain

private:
    Type type;
    char symbol;
};

#endif // TERRAIN_H
