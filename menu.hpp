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
    void starDayMessage(int day);
    void animalSick();
    void menuBabyBorn(int num);
    void menuAttendanceBoom();
    void menuNoRandomEvent();
    void menuBuyNewAnimal();
    void menuBuyAnimalSelectionMade(int select);

    void gameOverMssg();

private:
    int selection;
};

#endif
