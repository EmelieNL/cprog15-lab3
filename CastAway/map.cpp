#include "map.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "conmanip.h"
using namespace conmanip;
using namespace std;

// Unnamed namespace, functions only visible in this cpp (compilation
// unit). C++11 version of 'static'.
namespace {

// Print text with requested colors and reset console colors
void printSymbol(string text, console_text_colors textCol, console_bg_colors bgCol) {
    std::cout
    << settextcolor(textCol)
    << setbgcolor(bgCol)
    << text
    << settextcolor(console_text_colors::white)
    << setbgcolor(console_bg_colors::black);
}

} // End unnamed namespace

Map::Map(int x, int y){
     widthX = x;
     heightY = y;

     //Reset map
     for(int x=0; x < widthX;x++){
         for(int y=0; y < heightY;y++){
             map[x][y] = 0;
         }
     }

     initMap();
 }

//Return object at position
int Map::get(int x, int y){
    return map[y][x];
}

//Set a object at position
void Map::set(int x, int y, int obj){
    map[y][x] = obj;
}

void Map::render(){
    clear();
    for(int y=0; y < widthX;y++){
        for(int x=0; x < heightY;x++){
           //player
            if(map[y][x] == 1){
               std::cout << "@";
               playerX = x;
               playerY = y;
              //wall
           } else if(map[y][x] == 2){
                std::cout << "+";
                // water
            } else {
                printSymbol("^", console_text_colors::cyan, console_bg_colors::blue);
            }
        }

        //new line
        std::cout << "\n";
    }
}

int Map::getPlayerX(){
    return playerX;
}

int Map::getPlayerY(){
    return playerY;
}

void Map::initMap(){
    map[3][3] = 1; //player
    map[4][0] = 2; //wall
    map[4][1] = 2; //wall
    map[4][2] = 2; //wall
    map[4][3] = 2; //wall
    map[4][4] = 2; //wall
    map[4][5] = 2; //wall
    map[4][6] = 2; //wall
    map[4][7] = 2; //wall
}

void  Map::clear(){
#ifdef _WIN32
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}

