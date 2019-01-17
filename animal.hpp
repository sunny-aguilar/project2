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
    double getAnimalCost();
    double getFoodCost();
    double getPayOff();
    Animal(const Animal &obj);
    Animal &operator=(const Animal &rigth);

private:
    int age;
    double animalCost;
    int babyPotential;
    double baseFoodCost;
    double payOff;

};

#endif