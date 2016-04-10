#include "map.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

Map::Map(){
}

Map::Map(int x, int y){
     widthX = x;
     heightY = y;

     //Reset map
     for(int x=0; x < widthX;x++){
         for(int y=0; y < heightY;y++){
             map[x][y] = nullptr;
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

void Map::render() const{

    clear();
    for(int y=0; y < 10;y++){
        for(int x=0; x < 10;x++){
           /*
            //player
            if(map[y][x] == 1){
               std::cout << "@";
               playerX = x;
               playerY = y;
              //wall
           } else if(map[y][x] == 2){
                std::cout << "+";
            } else {
                std::cout << ".";
            }*/
            AbstractEntity* current = map[y][x];
            if(current != nullptr){
                current->render();
            } else {
                std::cout << ".";
            }
        }

        //new line
        std::cout << "\n";
    }
}


void Map::initMap(){
    Blocked* wall;
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

