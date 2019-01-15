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

int Animal::getAge() {
    return age;
}

void Animal::increaseAnimalAge() {
    age++;
}