#include <vector>
#include <algorithm>
#include "engine.h"

//Class to represent the gameengine, to help to load maps and hold information about active entities

Engine::Engine(Map map){
   // Map firstMap(10,10);
   // map = map;
    setMap(map);
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
     this->map.render();
 }

 void Engine::update()
 {
    /*
     * for(std::vector<AbstractEntity>::iterator it = entities.begin(); it != entities.end(); ++it) {
        //(*it).update();
     }
    */
 }

 void Engine::setMap(Map map)
 {
     this->map = map;
 }

 Map Engine::getMap()
 {
     return this->map;
 }

 void Engine::loadMap(std::string mapName)
 {
     this->clearEntities();
     //Map map(10,10);
     //Map map(mapName);
     //this->setMap(map);

 }

