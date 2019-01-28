/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Turtle class is derived from Animal class. Instances
**                  of Turtle are initialized with their age. Turtle
**                  inherits publicly from Animal.
*********************************************************************/
#include "turtle.hpp"

/*********************************************************************
** Description:     default constructor
*********************************************************************/
Turtle::Turtle() {}

/*********************************************************************
** Description:     default constructor that initializes variables
**                  in the base class
*********************************************************************/
Turtle::Turtle(int age) : Animal{age, 100, 10, 100*0.5, 5} {}