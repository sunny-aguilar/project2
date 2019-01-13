/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Zoo Tycoon -
**
**
**
**
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <cstring>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;

class Menu {
public:
    int validateNumber(int min, int max);
    void mainMenu();
    void setSelection(int sel);
    int getSelection();
    void initialTigers();
    void initialPenguins();
    void initialTurtles();

private:
    int selection;
};

#endif
