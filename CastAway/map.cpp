#include "map.h"

#include <iostream>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "conmanip.h"
#include "render.h"
#include "engine.h"
#include "player.h"
#include "fish.h"
#include "blocked.h"
#include "tile.h"
#include "item.h"
#include "consumable.h"
#include "weapon.h"
#include "abstractentity.h"

#ifdef _WIN32
    #include <conio.h>
#endif

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
            delete map[y][x];
         }
    }
}

// Return tile at position x, y
Tile* Map::getTile(int x, int y){
    return map[y][x];
}

void Map::addAbstractEntity(int x, int y, AbstractEntity *absEntity)
{
    this->map[y][x]->setAbsEntity(absEntity);
    entities.insert(entities.begin(), absEntity);
}

//Remove a entity from the map vector
void Map::removeAbstractEntity(AbstractEntity *absEntity)
{
    Engine::Instance().getPlayer()->addLog("Try to remove " + absEntity->getId());

    //Remove from map
    map[absEntity->getY()][absEntity->getX()]->setAbsEntity(nullptr);

    //Remove from entities vector
    entities.erase(std::remove(entities.begin(), entities.end(), absEntity), entities.end());
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
                    Render::printSymbol(current->getTerrain()->getSymbol(), console_text_colors::gray, console_bg_colors::black);
                    Render::printSymbol(char(32), console_text_colors::gray, console_bg_colors::black);
                } else {
                   Render::printSymbol('.', console_text_colors::black, console_bg_colors::black);
                   Render::printSymbol('.', console_text_colors::black, console_bg_colors::black);
                }
            } else {
                 Render::printSymbol('.', console_text_colors::black, console_bg_colors::black);
                 Render::printSymbol('.', console_text_colors::black, console_bg_colors::black);
            }
        }
        cout << endl;
    }
}

void Map::update()
{
    //Update all entities once
    for(auto entity : entities)
        entity->update();
}

void Map::initMap(){
    cout << "Map is inited from Map class"<< "\n";

    //Init tiles
    for(int y=0; y < heightY; y++){
        for(int x=0; x < widthX; x++){
            map[y][x] = new Tile();
          }
    }

    Fish* shark = new Fish('^');
    shark->setId("Shark");
    shark->setFgColor(console_text_colors::light_cyan);
    shark->setBgColor(console_bg_colors::blue);
    shark->setX(3);
    shark->setY(3);
    shark->setMaxHealth(20);
    addAbstractEntity(shark->getX(), shark->getY(), shark);

    //Test weapon
    Weapon* knife = new Weapon("Knife", 400, '|', 80);
    knife->setX(3);
    knife->setY(2);
    addAbstractEntity(knife->getX(), knife->getY(), knife);

    //Test apple
    Consumable* apple = new Consumable("Apple", 50, 'A', 20);
    apple->setFgColor(console_text_colors::light_red);
    apple->setX(4);
    apple->setY(4);
    addAbstractEntity(apple->getX(), apple->getY(), apple);


    Blocked* wall = new Blocked('#'); //TODO add destructor
    wall->setX(12);
    wall->setY(11);
    addAbstractEntity(wall->getX(), wall->getY(), wall);

    Blocked* wall2 = new Blocked('#'); //TODO add destructor
    wall2->setX(13);
    wall2->setY(11);
    addAbstractEntity(wall2->getX(), wall2->getY(), wall2);

    Blocked* wall3 = new Blocked('#'); //TODO add destructor
    wall3->setX(14);
    wall3->setY(11);
    addAbstractEntity(wall3->getX(), wall3->getY(), wall3);

    // Read map from input file
    char ch;
    ifstream fileStream("map.txt");
    fileStream >> ch;
    while (!fileStream.eof()) {
       map[1][1]->setTerrain(Terrain::Type::FORREST);
       fileStream >> ch;
    }

    /* map[4][15]->setTerrain(Terrain::Type::SAND);
    map[4][16]->setTerrain(Terrain::Type::SAND);
    map[4][17]->setTerrain(Terrain::Type::FORREST);
    map[4][18]->setTerrain(Terrain::Type::SAND);

    map[5][15]->setTerrain(Terrain::Type::SAND);
    map[5][16]->setTerrain(Terrain::Type::MOUNTAIN);
    map[5][17]->setTerrain(Terrain::Type::SAND);
    map[5][18]->setTerrain(Terrain::Type::SAND); */
}

void  Map::clear() const{
#ifdef _WIN32
    std::system("cls");
#else
    // Assume POSIX
    auto res = std::system("clear");
    if (res != 0)
        std::cerr << "Unable to clear screen" << std::endl;
#endif
}

bool Map::isBlocked(int x, int y)
{
    //Map boundry check
    if(x < 0 || x >= getWidth() || y < 0 || y >= getHeight()){
        return true;
    }

    Tile* tile = getTile(x,y);
    if(tile != nullptr && tile->getAbsEntity() != nullptr)
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
