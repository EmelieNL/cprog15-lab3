#include <iostream>
#include "map.h"
#include "engine.h"
#include "stateintro.h"
using namespace std;

int main(int /*argc*/, char** /*argv[]*/)
{
   //Map firstMap; //Create a map

  // Engine engine(firstMap);
   Engine engine;
   //engine.init();
   engine.changeState(StateIntro::instance());

   //Engine engine;
   //engine.setMap(firstMap);

   //char userCommand;

   //Gameloop
   while(engine.isRunning()){

       engine.handleEvents();
       engine.update();
       engine.render();
       //std::cin >> userCommand;
       //TODO movement
   }

   return 0;
}
