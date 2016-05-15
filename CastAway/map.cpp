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

Map::~Map()
{

    //Clean tiles in this map
    for(int y=0; y < heightY; y++){
        for(int x=0; x < widthX; x++){
            delete[] map[y][x];
         }
    }
}

// Return tile at position x, y
Tile* Map::getTile(int x, int y){
    return map[y][x];
}

// Render map
void Map::render() const {
    clear();
    for(int y=0; y < heightY; y++){
        for(int x=0; x < widthX; x++){
            Tile* current = map[y][x];
            if(current != nullptr){
                //First try to render any absEntity
                if(current->getAbsEntity() != nullptr){
                    current->getAbsEntity()->render();
                //if not present render the terrain
                } else {
                    Render::printSymbol(current->getTerrain()->getSymbol(), current->getTerrain()->getTextcolor(), current->getTerrain()->getBGcolor());
                }
            } else {
                 Render::printSymbol('.', conmanip::console_text_colors::black, conmanip::console_bg_colors::black);
            }
        }
        std::cout << endl;
    }
}

void Map::initMap(){
    std::cout << "Map is inited from Map class"<< "\n";

    //Init tiles
    for(int y=0; y < heightY; y++){
        for(int x=0; x < widthX; x++){
            map[y][x] = new Tile(); //TODO add to destructor
          }
    }

    Blocked* wall = new Blocked('#'); //TODO add destructor
    map[7][3]->setAbsEntity(wall);

    map[4][15]->setTerrain(Terrain::Type::SAND);
    map[4][16]->setTerrain(Terrain::Type::SAND);
    map[4][17]->setTerrain(Terrain::Type::FORREST);
    map[4][18]->setTerrain(Terrain::Type::SAND);

    map[5][15]->setTerrain(Terrain::Type::SAND);
    map[5][16]->setTerrain(Terrain::Type::MOUNTAIN);
    map[5][17]->setTerrain(Terrain::Type::SAND);
    map[5][18]->setTerrain(Terrain::Type::SAND);
}

void  Map::clear() const{
#ifdef _WIN32
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}

bool Map::isBlocked(int x, int y)
{
    Tile* tile = getTile(x,y);
    if(tile->getAbsEntity() != nullptr) //&& tile->getAbsEntity()->isSolid())
        return true;
    else
        return false;
}


