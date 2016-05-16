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

void Engine::init()
{
    Map* level_01 = new Map(); //TODO add to destructor
    this->maps["level_1"] = level_01;
}

 void Engine::render() const
 {
     states.back()->render();
 }

 void Engine::update()
 {
     // the current state handles update
     states.back()->update();
 }

 Map* Engine::getMap() const
 {
     return this->currentMap;
 }

 void Engine::loadMap(std::string mapName)
 {
     if(maps.find(mapName) != maps.end()){
        currentMap = maps[mapName];
        std::cout << "Found map " << mapName << ", now set to currMap" << "\n";
     } else {
         std::cout << "Did not find map " << mapName << "... :(" << "\n";
     }
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
     states.back()->render();
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

