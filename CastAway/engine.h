#ifndef ENGINE_H
#define ENGINE_H
#include <vector>
#include "abstractentity.h"
#include "map.h"

class GameState;

class Engine
{
private:
    Map map;
    //Vector to store entities
    std::vector<AbstractEntity> entities;
    std::vector<GameState*> states;
    bool running = true;
public:
    Engine(); //constructor
    Engine(Map map);
    void addEntity(AbstractEntity e);
    void clearEntities();
    AbstractEntity* getEntity(std::string id);
    AbstractEntity* getEntityAtLocation(int x, int y);
    void render() const;
    void update();
    void handleEvents();
    void clear() const;
    void setMap(Map map);
    Map getMap();
    void loadMap(std::string mapName);
    void changeState(GameState* state);
    void quit();
    bool isRunning();
};

#endif // ENGINE_H
