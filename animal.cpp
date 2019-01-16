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

Animal::Animal(int age) : age{age} {}

int Animal::getAge() {
    return age;
}

void Animal::increaseAnimalAge() {
    age++;
}