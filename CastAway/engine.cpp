#include <vector>
#include <algorithm>
#include <conio.h>
#include <iostream>
#include "engine.h"
#include "gamestate.h"

//Class to represent the gameengine, to help to load maps and hold information about active entities

Engine::Engine(void){
    init();
}

Engine::~Engine()
{
    //Clean maps
    maps.clear(); //TODO is this correct as delete[] is not compiling?

    //Remove player
    //delete player; //TODO how to free player?
}

/*Engine::Engine(Map map){
   // Map firstMap(10,10);
   // map = map;
    //setMap(map);
}*/

void Engine::init()
{
    Map* level_01 = new Map(); //TODO add to destructor
    this->maps["level_1"] = level_01;
/*
    player = new Player();

    //start pos for the player
    int playerX = 10;
    int playerY = 10;

    player->setX(playerX);
    player->setY(playerY);

    getMap()->getTile(playerX, playerY)->setAbsEntity(player);
    */


}

void Engine::addEntity(AbstractEntity e)
{
    //TODO, only compares on string id
     for(std::vector<AbstractEntity>::iterator it = entities.begin(); it != entities.end(); ++it) {
          if((*it).getId() == e.getId()){
              return;
          }
     }

     entities.push_back(e);

//    //If the entity is already in the list
//    if(std::find(entities.begin(), entities.end(), e) != entities.end()) {
//       //entities containts e
//        return;
//    //e does not exist in entities
//    } else {
//       entities.push_back(e); //add e last to vector
//    }
}

void Engine::clearEntities()
{
    entities.clear();
}

 AbstractEntity* Engine::getEntity(std::string id) {

     for(std::vector<AbstractEntity>::iterator it = entities.begin(); it != entities.end(); ++it) {
    // for(std::vector<AbstractEntity>::const_iterator it = entities.begin(); it != entities.end(); ++it) {
         if((*it).getId() == id){
           // return &(*it);
         }
     }

     return nullptr;

     //TODO
    /*auto it = find_if(entities.begin(), entities.end(), [&id](AbstractEntity* obj) {
         return obj->getId() == id;
     });

     if(it != entities.end())
     {
       // found element. it is an iterator to the first matching element.
       // if you really need the index, you can also get it:
       //auto index = std::distance(v.begin(), it);
             return &(*it);
     }
*/
     return nullptr;
 }

 AbstractEntity* Engine::getEntityAtLocation(int x, int y)
 {
     for(std::vector<AbstractEntity>::iterator it = entities.begin(); it != entities.end(); ++it) {
    // for(std::vector<AbstractEntity>::const_iterator it = entities.begin(); it != entities.end(); ++it) {
         if((*it).getX() == x && (*it).getY() == y){
            //return &(*it);
         }
     }

     return nullptr;
 }

 void Engine::render() const
 {
     //this->map.render();
     // the current state handles render
     states.back()->render();
 }

 void Engine::update()
 {
     // the current state handles update
     states.back()->update();

    /*
     * for(std::vector<AbstractEntity>::iterator it = entities.begin(); it != entities.end(); ++it) {
        //(*it).update();
     }
    */
 }

 Map* Engine::getMap() const
 {
     return this->currentMap;
 }

 void Engine::loadMap(std::string mapName)
 {

     if(maps.find(mapName) != maps.end()){
        this->clearEntities();
        currentMap = maps[mapName];
        std::cout << "Found map " << mapName << ", now set to currMap" << "\n";
     } else {
         std::cout << "Did not find map " << mapName << "... :(" << "\n";
     }

     //this->clearEntities();
     //Map map(10,10);
     //Map map(mapName);
     //this->setMap(map);
 }

 void Engine::changeState(GameState *state){

     //The old state might have to do stuff, clean up data
     if(!states.empty()){
         states.back()->clear();
         states.pop_back(); //pop from vector
     }

     //Add the new state to end of vector
     states.push_back(state);

     //Init the new state which is at end of vector
     states.back()->init();
 }

 void Engine::quit()
 {
     this->running = false;
 }

 bool Engine::isRunning()
 {
     return this->running;
 }

 Player *Engine::getPlayer() const
 {
     return player;
 }

 void Engine::setPlayer(Player *player)
 {
     this->player = player;
 }

 bool Engine::isDebug() const
 {
     return debug;
 }

 void Engine::handleEvents()
 {
     // the currentstate handles events
     states.back()->handleInput();
 }

 void Engine::clear() const
 {

 #ifdef _WIN32
     std::system("cls");
 #else
     // Assume POSIX
     std::system ("clear");
 #endif
 }

