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
    Native(char symbol);
    void moveX(int x);
    void moveY(int y);
    void addDialog(std::string message);        //Add message to the dialog vector
    std::string popDialog();                    //Pop message from dialog vector
    std::string getRandomDialog() const;        //Get random dialog and keep it in the vector
    bool haveDialog() const;                    //Does any dialog messages exist?

private:
    std::vector<std::string> dialog; //vector of dialog messanges in sorted order
};

#endif // NATIVE_H
