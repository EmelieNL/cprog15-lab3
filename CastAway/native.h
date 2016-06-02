#ifndef NATIVE_H
#define NATIVE_H
#include <stdlib.h> //for random dialog
#include <time.h> //for random seed
#include "creature.h"

//Represent a native human creature
class Native:public Creature
{
public:
    Native();
    void moveX(int x);
    void moveY(int y);
    void addDialog(std::string message);        //Add message to the dialog vector
    std::string popDialog();                    //Pop message from dialog vector
    std::string getRandomDialog() const;        //Get random dialog and keep it in the vector
    bool haveDialog() const;                    //Does any dialog messages exist?

    bool isLookingForItem() const;
    void setIsLookingForItem(bool value);

    std::string getLookingForId() const; //Get the id of what he is looking for
    void setLookingForId(std::string id); //set id this object is looking for

    int getNeedAmount() const;
    void setNeedAmount(int value);

private:
    std::vector<std::string> dialog; //vector of dialog messanges in sorted order
    bool lookingForItem; //if the native is looking for an item
    std::string lookingForId;
    int needAmount;
};

#endif // NATIVE_H
