/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Zoo Tycoon -
**
**
**
**
*********************************************************************/
#include "animal.hpp"

Animal::Animal() {};

Animal::Animal(int age, double animalCost, int babies, double foodCost, double payOff) :
    age{age},
    animalCost{animalCost},
    babyPotential{babies},
    baseFoodCost{foodCost},
    payOff {payOff} {}

int Animal::getAge() {
    return age;
}

void Animal::increaseAnimalAge() {
    age++;
}

double Animal::getFoodCost() {
    return baseFoodCost;
}

double Animal::getPayOff() {
    return payOff;
}