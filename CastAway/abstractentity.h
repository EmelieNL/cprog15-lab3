#ifndef ABSTRACTENTITY_H
#define ABSTRACTENTITY_H
#include "conmanip.h"
#include <string>

//Basic class to represent entities thay can exist in the game world,
//should be extended by all other map objects etc

class AbstractEntity
{

private:
    bool canMove;
    bool solid;
    std::string id;
    int x;
    int y;
    conmanip::console_bg_colors bgColor;
    conmanip::console_text_colors fgColor;

protected:
    char symbol;

public:
    //TODO make this class abstract!
    //AbstractEntity(int x, int y, char symbol); //main constructor
    //virtual ~AbstractEntity();	//destructor
    conmanip::console_bg_colors getBgColor() const;
    conmanip::console_text_colors getFgColor() const;
    std::string getId() const;
    int getX() const;
    int getY() const;
    bool isCanMove() const;
    bool isSolid() const;
    void setCanMove(bool canMove);
    void setBgColor( conmanip::console_bg_colors color);
    void setFgColor( conmanip::console_text_colors color);
    void setId(std::string newId);
    void setSolid(bool solid);
    void setSymbol(char symbol);
    void setX(int x);
    void setY(int y);
    virtual void update();

    void render() const;

};

#endif // ABSTRACTENTITY_H
