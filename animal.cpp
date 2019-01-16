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

Animal::Animal(int age, double animalCost, int babies, int foodCost, double payOff) :
    age{age},
    animalCost{animalCost},
    babyPotential{babies},
    payOff {payOff} {}

int Animal::getAge() {
    return age;
}

void Animal::increaseAnimalAge() {
    age++;
}