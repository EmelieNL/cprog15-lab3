#include "map.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "conmanip.h"
#include "render.h"

using namespace conmanip;
using namespace std;

// Default constructor
Map::Map() {
    initMap();
}

// Return tile at position x, y
Map::Tile Map::getTile(int x, int y){
    return map[y][x];
}

// Set entity at position x, y
// Tror inte vi kommer att behöva denna
void Map::setAbstractEntity(int x, int y, AbstractEntity absEntity){
    // TODO beroende på hur vi vill hantera objectet
}

// Set terrain type at position x, y
// Tror inte vi kommer att behöva denna
void Map::setTerrain(int x, int y, Terrain::Type terrainType){
    map[y][x].terrain.setTerrain(terrainType);
}

// Render map
void Map::render() const {
    clear();
    for(int y=0; y < heightY; y++){
        for(int x=0; x < widthX; x++){
            Tile current = map[y][x];
            Render::printSymbol(current.terrain.getSymbol(), current.terrain.getTextcolor(), current.terrain.getBGcolor());
        }
        std::cout << endl;
    }
}


void Map::initMap(){
    std::cout << "Map is inited from Map class"<< "\n";

    // Not renderd right now
    Blocked wall = Blocked();
    wall.setSolid(true);
    wall.setSymbol('#');

    map[4][0].absEntity = wall;
    map[4][1].absEntity = wall;
    map[4][2].absEntity = wall;
    map[4][3].absEntity = wall;
    map[4][4].absEntity = wall;
    map[4][5].absEntity = wall;
    map[4][6].absEntity = wall;

    // Testing
    map[4][7].terrain.setTerrain(Terrain::Type::SAND);
    map[4][11].terrain.setTerrain(Terrain::Type::FORREST);
    map[4][19].terrain.setTerrain(Terrain::Type::MOUNTAIN);

}

void  Map::clear() const{
#ifdef _WIN32
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}


