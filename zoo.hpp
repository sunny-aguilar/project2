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
//    Animal *gettigerArrayPtr(int elem);
    void resizeTigerArray(int size);

    // testing methods
    void tigerArrayAddress();
    void resizeArray();

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
    Animal **tigerArray;      // pointer to a pointer
    Animal **penguinArray;
    Animal **turtleArray;
};

#endif