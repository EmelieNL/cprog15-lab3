#ifndef ABSTRACTENTITY_H
#define ABSTRACTENTITY_H
#include <string>

class AbstractEntity
{
private:
    bool canMove;
    bool moving;
    bool solid;
    int direction; //TODO connection to a global object which defines 1,2,3,4 for up, down and so on?
    std::string id;
    int x;
    int y;
    char symbol;
    int color;

public:
    //AbstractEntity(int x, int y, char symbol); //main constructor
    //virtual ~AbstractEntity();	//destructor
    int getColor() const;
    int getDirection() const;
    std::string getId() const;
    int getX() const;
    int getY() const;
    bool isCanMove() const;
    bool isMoving() const;
    bool isSolid() const;
    void render() const;
    void setCanMove(bool canMove);
    void setColor(int color);
    void setDirection(int direction);
    void setId(std::string newId);
    void setMoving(bool moving);
    void setSolid(bool solid);
    void setSymbol(char symbol);
    void setX(int x);
    void setY(int y);
    void update();



};

#endif // ABSTRACTENTITY_H
