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
    std::string id;
    int x;
    int y;
    conmanip::console_bg_colors bgColor;
    conmanip::console_text_colors fgColor;

protected:
    char symbol;

public:
    // Base class constructors should always be virtual
    virtual ~AbstractEntity() {};

    conmanip::console_bg_colors getBgColor() const;
    conmanip::console_text_colors getFgColor() const;
    std::string getId() const;
    int getX() const;
    int getY() const;
    bool isCanMove() const;
    void setCanMove(bool newCanMove);
    void setBgColor( conmanip::console_bg_colors color);
    void setFgColor( conmanip::console_text_colors color);
    void setId(std::string newId);
    void setSymbol(char symbol);
    void setX(int x);
    void setY(int y);

    // Pure virtual, abstract class
    virtual void update() = 0;

    void render() const;

};

#endif // ABSTRACTENTITY_H
