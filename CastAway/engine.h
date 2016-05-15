#ifndef ENGINE_H
#define ENGINE_H
#include <map>
#include <vector>
#include "abstractentity.h"
#include "map.h"

class Player; //forward declaration
class GameState;

class Engine
{
private:
    Map* currentMap;
    std::map<std::string, Map*> maps; //maps available
    std::vector<AbstractEntity> entities; //Vector to store entities
    std::vector<GameState*> states; //Game states
    bool running = true;

    Engine(); //constructor
    //Engine(Map map);
    ~Engine(); //destructor
    Engine(Engine const&); //dont implement
    void operator=(Engine const&); //dont implement
    Player* player;


public:

    static Engine& Instance(){
        static Engine engine;
        return engine;
    }

    //Engine(Engine const&) = delete;
    //void operator=(Engine const&) = delete;

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
    Player* getPlayer() const;
    void setPlayer(Player* player);
};

#endif // ENGINE_H
