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
    Zoo();
    void addTigers();
    void getTiger();
    void resizeArray(int size);

private:
    int bankBalance;
    int baseFoodCost;
    int days;
    bool playAgain;
    bool ateFood;
    int *intPtr;
    Animal *tigerArray;
    Animal *penguinArray[10];
    Animal *turtlesArray[10];
};

#endif