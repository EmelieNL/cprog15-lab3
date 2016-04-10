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
    int const getColor() const;
    int const getDirection() const;
    std::string const getId() const;
    int const getX() const;
    int const getY() const;
    bool const isCanMove() const;
    bool const isMoving() const;
    bool const isSolid() const;
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
