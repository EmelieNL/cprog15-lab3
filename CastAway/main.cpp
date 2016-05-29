#ifdef QT_NO_DEBUG_OUTPUT
#undef QT_NO_DEBUG_OUTPUT
#endif

#include <iostream>
#include "engine.h"
#include "stateintro.h"

using namespace std;

int main(int /*argc*/, char** /*argv[]*/)
{
   Engine::Instance().init();
   Engine::Instance().changeState(StateIntro::instance());

   //Gameloop
   while(Engine::Instance().isRunning())
   {
       Engine::Instance().handleEvents();
       Engine::Instance().update();
       Engine::Instance().render();
   }

   return 0;
}
