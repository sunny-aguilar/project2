/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Zoo Tycoon -
**
**
**
**
*********************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP

#include <ctime>
#include "menu.hpp"
#include "animal.hpp"

class Zoo {
public:
    // menu class
    Menu menu;
    // zoo class
    Zoo();
    void playGame();
    void initializeAnimals();
    void startUpCosts();


private:
    Animal **animals;      // array of pointers
    int tigerQty;
    int penguinQty;
    int turtleQty;
    int bearQty;
    int bankBalance;
    int dailyBudget;
    int baseFoodCost;
    bool randomEvent;
};

#endif