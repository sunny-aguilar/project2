/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Penguin class is derived from Animal class. Instances
**                  of Penguin are initialized with their age. Penguin
**                  inherits publicly from Animal.
*********************************************************************/
#include "penguin.hpp"

/*********************************************************************
** Description:     default constructor
*********************************************************************/
Penguin::Penguin() {}

/*********************************************************************
** Description:     default constructor that initializes variables
**                  in the base class
*********************************************************************/
Penguin::Penguin(int age) : Animal{age, 1000, 5, 100, 100} {}