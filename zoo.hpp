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
    ~Zoo();
    void addTigers();
    void getTiger();
    void resizeTigerArray(int size);


    void setTigerLegs();
    void getTigerLegs();

private:
    int bankBalance;
    int baseFoodCost;
    int days;
    bool playAgain;
    bool ateFood;
    int tigerQty;
    int penguinQty;
    int turtleQty;
    int tigerArrayCapacity;
    int penguinArrayCapacity;
    int turtleArrayCapacity;
    int *intPtr;
//    Animal **tigerArray;
    Animal *tigerArray;
    Animal *penguinArray;
    Animal *turtleArray[10];
};

#endif