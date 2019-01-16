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
    Animal(int age, double animalCost, int babies, int foodCost, double payOff);
    int getAge();
    void increaseAnimalAge();

private:
    int age;
    double animalCost;
    int babyPotential;
    double baseFoodCost;
    double payOff;

};

#endif