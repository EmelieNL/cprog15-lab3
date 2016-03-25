#include <iostream>
#include "map.h"

using namespace std;

int main(int argc, char *argv[])
{
   Map map(10,10); //Create a map
   char userCommand;

   //Gameloop
   while(true){
       map.render();

       //Input
       std::cin >> userCommand;
       if (userCommand == 'd') {  //move right
           map.set(map.getPlayerX(), map.getPlayerY(), 0); //Clear where the player was
           map.set(map.getPlayerX()+1, map.getPlayerY(), 1); //move player
       } else if(userCommand == 'a'){ //move left
           map.set(map.getPlayerX(), map.getPlayerY(), 0); //Clear where the player was
           map.set(map.getPlayerX()-1, map.getPlayerY(), 1); //move player
       }
   }

   return 0;
}
