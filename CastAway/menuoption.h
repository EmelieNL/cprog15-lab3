#ifndef MENUOPTION_H
#define MENUOPTION_H


class MenuOption
{
public:
    void initMenuOption(int max);
    void increaseMenuOption();
    void decreaseMenuOption();
    void setMaxMenuOption(int max);
    void setCurrentMenuOption(int curr);
    int getCurrentMenuOption() const;
    void menuOptionAction();

private:
    int currentMenuOption; //current selection
    int maxMenuOption; //max to select
};

#endif // MENUOPTION_H
