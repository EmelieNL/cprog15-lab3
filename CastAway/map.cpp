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
#include "native.h"
#include "inventory.h"
#include "crab.h"
#include "blocked.h"
#include "tile.h"
#include "item.h"
#include "consumable.h"
#include "weapon.h"
#include "abstractentity.h"
#include "axe.h"
#include "tree.h"
#include "boat.h"

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

    /* SHARKS */
    Fish* shark1 = new Fish('^');
    shark1->setId("Shark");
    shark1->setFgColor(console_text_colors::light_cyan);
    shark1->setBgColor(console_bg_colors::blue);
    shark1->setX(3);
    shark1->setY(3);
    shark1->setMaxHealth(20);
    shark1->setBasicAttack(15);
    addAbstractEntity(shark1->getX(), shark1->getY(), shark1);

    Fish* shark2 = new Fish('^');
    shark2->setId("Shark");
    shark2->setFgColor(console_text_colors::light_cyan);
    shark2->setBgColor(console_bg_colors::blue);
    shark2->setX(10);
    shark2->setY(15);
    shark2->setMaxHealth(20);
    shark2->setBasicAttack(10);
    addAbstractEntity(shark2->getX(), shark2->getY(), shark2);

    Fish* shark3 = new Fish('^');
    shark3->setId("Shark");
    shark3->setFgColor(console_text_colors::light_cyan);
    shark3->setBgColor(console_bg_colors::blue);
    shark3->setX(10);
    shark3->setY(16);
    shark3->setMaxHealth(20);
    shark3->setBasicAttack(10);
    addAbstractEntity(shark3->getX(), shark3->getY(), shark3);

    Fish* shark4 = new Fish('^');
    shark4->setId("Shark");
    shark4->setFgColor(console_text_colors::light_cyan);
    shark4->setBgColor(console_bg_colors::blue);
    shark4->setX(11);
    shark4->setY(15);
    shark4->setMaxHealth(20);
    shark4->setBasicAttack(10);
    addAbstractEntity(shark4->getX(), shark4->getY(), shark4);

    Fish* shark5 = new Fish('^');
    shark5->setId("Shark");
    shark5->setFgColor(console_text_colors::light_cyan);
    shark5->setBgColor(console_bg_colors::blue);
    shark5->setX(12);
    shark5->setY(13);
    shark5->setMaxHealth(20);
    shark5->setBasicAttack(10);
    addAbstractEntity(shark5->getX(), shark5->getY(), shark5);

    Fish* shark6 = new Fish('^');
    shark6->setId("Shark");
    shark6->setFgColor(console_text_colors::light_cyan);
    shark6->setBgColor(console_bg_colors::blue);
    shark6->setX(55);
    shark6->setY(6);
    shark6->setMaxHealth(20);
    shark6->setBasicAttack(10);
    addAbstractEntity(shark6->getX(), shark6->getY(), shark6);

    Fish* shark7 = new Fish('^');
    shark7->setId("Shark");
    shark7->setFgColor(console_text_colors::light_cyan);
    shark7->setBgColor(console_bg_colors::blue);
    shark7->setX(52);
    shark7->setY(10);
    shark7->setMaxHealth(20);
    shark7->setBasicAttack(10);
    addAbstractEntity(shark7->getX(), shark7->getY(), shark7);


    /* CRABS */
    //Crab meat that will be added to crab inventory
    Consumable* crabMeat1 = new Consumable("Crabmeat", 100, 'M', 15);
    Crab* crab1 = new Crab('C');
    crab1->setId("Crab");
    crab1->setFgColor(console_text_colors::light_red);
    crab1->setBgColor(console_bg_colors::light_yellow);
    crab1->setX(17);
    crab1->setY(8);
    crab1->setMaxHealth(5);
    crab1->getInventory()->addItem(crabMeat1);
    addAbstractEntity(crab1->getX(), crab1->getY(), crab1);

    Crab* crab2 = new Crab('C');
    crab2->setId("Crab");
    crab2->setFgColor(console_text_colors::light_red);
    crab2->setBgColor(console_bg_colors::light_yellow);
    crab2->setX(6);
    crab2->setY(17);
    crab2->setMaxHealth(5);
    addAbstractEntity(crab2->getX(), crab2->getY(), crab2);

    Consumable* crabMeat2 = new Consumable("Crabmeat", 100, 'M', 15);
    Crab* crab3 = new Crab('C');
    crab3->setId("Crab");
    crab3->setFgColor(console_text_colors::light_red);
    crab3->setBgColor(console_bg_colors::light_yellow);
    crab3->setX(39);
    crab3->setY(16);
    crab3->setMaxHealth(5);
    crab3->getInventory()->addItem(crabMeat2);
    addAbstractEntity(crab3->getX(), crab3->getY(), crab3);

    Crab* crab4 = new Crab('C');
    crab4->setId("Crab");
    crab4->setFgColor(console_text_colors::light_red);
    crab4->setBgColor(console_bg_colors::light_yellow);
    crab4->setX(53);
    crab4->setY(5);
    crab4->setMaxHealth(5);
    addAbstractEntity(crab4->getX(), crab4->getY(), crab4);

    /* HUMAN NATIVES */
    Native* human = new Native();
    human->setX(15);
    human->setY(8);
    human->setHostile(false);
    human->setId("Native indian");
    human->addDialog("Are you lost or something?");
    human->addDialog("I heard rumors there is a boatbuilder in the far east...");
    addAbstractEntity(human->getX(), human->getY(), human);

    Native* boatBuilder = new Native();
    boatBuilder->setX(47);
    boatBuilder->setY(4);
    boatBuilder->setHostile(false);
    boatBuilder->setId("Indian boatbuilder");
    boatBuilder->addDialog("I have already made a decent boat for you!");
    boatBuilder->addDialog("I feel to tierd to build anything");
    boatBuilder->setIsLookingForItem(true);
    boatBuilder->setNeedAmount(8);
    boatBuilder->setLookingForId("Wooden board");

    //Boat that should be added to inventory
    Boat* boat = new Boat("Boat", 5000, 'B');
    boatBuilder->getInventory()->addItem(boat);

    addAbstractEntity(boatBuilder->getX(), boatBuilder->getY(), boatBuilder);

    /* WEAPONS */
    Weapon* knife = new Weapon("Knife", 400, '|', 80);
    knife->setX(3);
    knife->setY(2);
    addAbstractEntity(knife->getX(), knife->getY(), knife);

    Axe* axe = new Axe("Axe", 1200, '[', 25);
    axe->setX(16);
    axe->setY(8);
    addAbstractEntity(axe->getX(), axe->getY(), axe);

    /* CONSUMABLES */
    Consumable* apple = new Consumable("Apple", 50, 'A', 20);
    apple->setFgColor(console_text_colors::light_red);
    apple->setX(42);
    apple->setY(8);
    addAbstractEntity(apple->getX(), apple->getY(), apple);

    /* TREES */
    Tree* tree = new Tree();
    tree->setX(20);
    tree->setY(8);
    addAbstractEntity(tree->getX(), tree->getY(), tree);

    Tree* tree2 = new Tree();
    tree2->setX(24);
    tree2->setY(8);
    addAbstractEntity(tree2->getX(), tree2->getY(), tree2);

    Tree* tree3 = new Tree();
    tree3->setX(24);
    tree3->setY(6);
    addAbstractEntity(tree3->getX(), tree3->getY(), tree3);

    Tree* tree4 = new Tree();
    tree4->setX(26);
    tree4->setY(13);
    addAbstractEntity(tree4->getX(), tree4->getY(), tree4);

    Tree* tree5 = new Tree();
    tree5->setX(35);
    tree5->setY(10);
    addAbstractEntity(tree5->getX(), tree5->getY(), tree5);

    Tree* tree6 = new Tree();
    tree6->setX(43);
    tree6->setY(14);
    addAbstractEntity(tree6->getX(), tree6->getY(), tree6);

    // Read map from input file
    char ch;
    ifstream fileStream("map1.txt");
    if (fileStream.is_open() == false) cerr << "Could not open file" << endl;
    while (!fileStream.eof()) {
        for(int x = 0; x < heightY; ++x){
            for(int y = 0; y < widthX; ++y){

                fileStream >> ch;

                switch(ch) {
                case '~':
                    map[x][y]->setTerrain(Terrain::Type::WATER);
                    break;
                case ':':
                    map[x][y]->setTerrain(Terrain::Type::SAND);
                    break;
                case '*':
                    map[x][y]->setTerrain(Terrain::Type::FORREST);
                    break;
                case '^':
                    map[x][y]->setTerrain(Terrain::Type::MOUNTAIN);
                    break;
                default:
                    map[x][y]->setTerrain(Terrain::Type::WATER);
                    break;
                }
                ch = 'o';   // reset char
            }
        }
    }
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
