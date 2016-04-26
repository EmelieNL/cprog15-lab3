#ifndef ENGINE_H
#define ENGINE_H
#include <map>
#include <vector>
#include "abstractentity.h"
#include "map.h"

class GameState;

class Engine
{
private:
    Map* currentMap;
    std::map<std::string, Map*> maps; //maps available
    std::vector<AbstractEntity> entities; //Vector to store entities
    std::vector<GameState*> states; //Game states
    bool running = true;
public:
    Engine(); //constructor
    Engine(Map map);
    void init();
    void addEntity(AbstractEntity e);
    void clearEntities();
    AbstractEntity* getEntity(std::string id);
    AbstractEntity* getEntityAtLocation(int x, int y);
    void render() const;
    void update();
    void handleEvents();
    void clear() const;
    Map* getMap() const;
    void loadMap(std::string mapName);
    void changeState(GameState* state);
    void quit();
    bool isRunning();
};

#endif // ENGINE_H
