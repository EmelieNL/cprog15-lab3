#include "map.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "conmanip.h"
#include "render.h"
#include "engine.h"
#include "player.h"

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

    int playerX = Engine::Instance().getPlayer()->getX();
    int playerY = Engine::Instance().getPlayer()->getY();

    for(int y=0; y < heightY; y++){
        for(int x=0; x < widthX; x++){
            Tile* current = map[y][x];
            if(current != nullptr){

                double rad =  sqrt(pow(((double)x - (double)playerX), 2) + pow((double)y - (double)playerY, 2));

                //FOV
                if(rad <= 8){

                    current->setExplored();

                    //First try to render any absEntity
                    if(current->getAbsEntity() != nullptr){
                        current->getAbsEntity()->render();
                    //if not present render the terrain
                    } else {
                        Render::printSymbol(current->getTerrain()->getSymbol(), current->getTerrain()->getTextcolor(), current->getTerrain()->getBGcolor());
                        Render::printSymbol(char(32), current->getTerrain()->getTextcolor(), current->getTerrain()->getBGcolor());
                    }

                //if already explored, show terrain but not entities
                } else if(current->isExplored()){
                    Render::printSymbol(current->getTerrain()->getSymbol(), conmanip::console_text_colors::gray, conmanip::console_bg_colors::black);
                    Render::printSymbol(char(32), conmanip::console_text_colors::gray, conmanip::console_bg_colors::black);
                } else {
                   Render::printSymbol('.', conmanip::console_text_colors::black, conmanip::console_bg_colors::black);
                   Render::printSymbol('.', conmanip::console_text_colors::black, conmanip::console_bg_colors::black);
                }
            } else {
                 Render::printSymbol('.', conmanip::console_text_colors::black, conmanip::console_bg_colors::black);
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

    //Test item
    Item* knife = new Item("Knife", 400, '|');
    map[3][2]->setAbsEntity(knife);

    //Test apple
    Consumable* apple = new Consumable("Apple", 50, 'A', 20);
    apple->setFgColor(conmanip::console_text_colors::light_red);
    map[4][4]->setAbsEntity(apple);

    Blocked* wall = new Blocked('#'); //TODO add destructor
    map[12][11]->setAbsEntity(wall);

    Blocked* wall2 = new Blocked('#'); //TODO add destructor
    map[13][11]->setAbsEntity(wall2);

    Blocked* wall3 = new Blocked('#'); //TODO add destructor
    map[14][11]->setAbsEntity(wall3);

    Blocked* wall4 = new Blocked('#'); //TODO add destructor
    map[14][12]->setAbsEntity(wall4);

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
    //Map boundry check
    if(x < 0 || x >= getWidth() || y < 0 || y >= getHeight()){
        return true;
    }

    Tile* tile = getTile(x,y);
    if(tile != nullptr && tile->getAbsEntity() != nullptr) //&& tile->getAbsEntity()->isSolid())
        return true;
    else
        return false;
}

//Get map width
int Map::getWidth() const
{
    return widthX;
}

//Get map height
int Map::getHeight() const
{
    return heightY;
}
