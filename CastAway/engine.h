#ifndef ENGINE_H
#define ENGINE_H
#include <vector>
#include "abstractentity.h"
#include "map.h"


class Engine
{
private:
    Map map;
    //Vector to store entities
    std::vector<AbstractEntity> entities;
public:
    Engine();
    Engine(Map map);
    void addEntity(AbstractEntity e);
    void clearEntities();
    AbstractEntity* getEntity(std::string id);
    AbstractEntity* getEntityAtLocation(int x, int y);
    void render() const;
    void update();
    void setMap(Map map);
    Map getMap();
    void loadMap(std::string mapName);
};

#endif // ENGINE_H
