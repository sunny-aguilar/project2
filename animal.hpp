/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Zoo Tycoon -
**
**
**
**
*********************************************************************/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
public:
    Animal();
    Animal(int age, double payOff);
    int getAge();
    void increaseAnimalAge();

private:
    int age;
    int cost;
    int babyPotential;
    int baseFoodCost;
    double payOff;

};

#endif