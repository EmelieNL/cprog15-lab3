#include <iostream>
//#include "map.h"
#include "engine.h"
using namespace std;

int main(int argc, char *argv[])
{
   Map firstMap(10,10); //Create a map

   // Engine engine(firstMap);
   Engine engine;

   engine.setMap(firstMap);

   char userCommand;

   //Gameloop
   while(true){

       engine.update();
       engine.render();
       std::cin >> userCommand;
       //TODO movement
   }

   return 0;
}
