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

#include "animal.hpp"
class Zoo {
public:
    void addTigers();
//    void growArray();
    void getTiger();

private:
    int bankBalance;
    int baseFoodCost;
    int days;
    bool playAgain;
    bool ateFood;
    Animal *tigers;
    Animal *penguins[10];
    Animal *turtles[10];
};

#endif