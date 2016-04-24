#include "map.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "conmanip.h"
#include "render.h"

using namespace conmanip;
using namespace std;

Map::Map(/*int x, int y*/){
//    widthX = x;
//    heightY = y;

//    // Allocate dynamic size of map array
//    map = new AbstractEntity**[heightY];

    //Reset map
    for(int y=0; y < heightY; y++){
//        map[y] = new AbstractEntity*[widthX];
        for(int x=0; x < widthX; x++){
            map[y][x] = nullptr;
        }
    }

    initMap();
}

//Return object at position
AbstractEntity* Map::get(int x, int y){
    return map[y][x];
}

//Set a object at position
void Map::set(int x, int y, AbstractEntity* obj){
    map[y][x] = obj;
}

void Map::render() const {
    clear();
    for(int y=0; y < heightY;y++){
        for(int x=0; x < widthX;x++){
            AbstractEntity* current = map[y][x];
            if(current != nullptr){
                current->render();
            } else {
               Render::printSymbol('^', console_text_colors::cyan, console_bg_colors::blue);
            }
        }

        //new line
        std::cout << "\n";
    }
}


void Map::initMap(){
    Blocked* wall = new Blocked();
    wall->setSolid(true);
    wall->setSymbol('#');

    map[4][0] = wall;
    map[4][1] = wall;
    map[4][2] = wall;
    map[4][3] = wall;
    map[4][4] = wall;
    map[4][5] = wall;
    map[4][6] = wall;
    map[4][7] = wall;

}

void  Map::clear() const{
#ifdef _WIN32
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}


