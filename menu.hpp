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
    void mainMenu();
    void setSelection(int sel);
    int getSelection();
    int validateNumber(int min, int max);

private:
    int selection;
};

#endif
