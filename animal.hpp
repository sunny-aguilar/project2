/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2, 2019
** Description:     Animal class is the base class for Tiger, Penguin
**                  and Turtle classes.Subclasses inherit publicly.
**                  Base class holds characteristic that are the same
**                  of the derived classes such as age, their cost,
**                  food requirements, and payoff.
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