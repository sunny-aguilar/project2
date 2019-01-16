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
    Animal(int age, double animalCost, int babies, double foodCost, double payOff);
    int getAge();
    void increaseAnimalAge();
    void getFoodCost();

private:
    int age;
    double animalCost;
    int babyPotential;
    double baseFoodCost;
    double payOff;

};

#endif