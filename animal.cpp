/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2, 2019
** Description:     Animal class is the base class for Tiger, Penguin
**                  and Turtle classes.Subclasses inherit publicly.
**                  Base class holds characteristic that are the same
**                  of the derived classes such as age, their cost,
**                  food requirements, and payoff.
*********************************************************************/
#include "animal.hpp"
/*********************************************************************
** Description:     default constructor
*********************************************************************/
Animal::Animal() {};

/*********************************************************************
** Description:     default constructor that initializes variables
**                  in the base class
*********************************************************************/
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

double Animal::getAnimalCost() {
    return animalCost;
}

double Animal::getFoodCost() {
    return baseFoodCost;
}

double Animal::getPayOff() {
    return payOff;
}

Animal::Animal(const Animal &obj) {
    age = obj.age;
    animalCost = obj.animalCost;
    babyPotential = obj.babyPotential;
    baseFoodCost = obj. baseFoodCost;
    payOff = obj.payOff;
}

Animal &Animal::operator=(const Animal &right) {
    if (this != &right) {
        age = right.age;
        animalCost = right.animalCost;
        babyPotential = right.babyPotential;
        baseFoodCost = right.baseFoodCost;
        payOff = right.payOff;
        return *this;
    }
}