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

void Map::render() const {
    clear();
    for(int y=0; y < widthX;y++){
        for(int x=0; x < heightY;x++){
            AbstractEntity* current = map[y][x];
            if(current != nullptr){
                current->render();
                //  printSymbol("^", console_text_colors::cyan, console_bg_colors::blue);
            } else {
                std::cout << ".";
            }
        }

        //new line
        std::cout << "\n";
    }
}


void Map::initMap(){
    Blocked* wall; // uninitialized, will crash :)
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

