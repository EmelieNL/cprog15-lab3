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
    std::vector<GameState*> states; //Game states
    bool running = true;

    Engine(); //constructor
    ~Engine(); //destructor
    Engine(Engine const&); //dont implement
    void operator=(Engine const&); //dont implement
    Player* player;
    bool debug = true;


public:
    static Engine& Instance(){
        static Engine engine;
        return engine;
    }

    void init();
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
    bool isDebug() const;
};

#endif // ENGINE_H
