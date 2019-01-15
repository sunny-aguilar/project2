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
    bool startDay();
    void ageAnimals();
    void countAnimals();
    void dailyBudget();
    void feedAnimals();
    void randomEvents();

private:
    Animal **animals;      // array of pointers
    int tigerQty;
    int penguinQty;
    int turtleQty;
    int bearQty;
    double bankBalance;
    bool continueDay;
    bool gameOver;
    int dailyProfit;
    int baseFoodCost;
    bool randomEvent;
};

#endif